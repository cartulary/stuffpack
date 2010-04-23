#include <ctype.h>
#include <err.h>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sysexits.h>
#include <map>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
/* for the non-standard user_from_uid and group_from_gid functions */
#include <pwd.h>
#include <grp.h>
#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/config/warning_disable.hpp>
#include <boost/config.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/optional.hpp>
#include <boost/foreach.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/lexical_cast.hpp>
#include "ls_helper.cpp"
void usage();

namespace bf = boost::filesystem;

/*  various options */
/* showDotLinks - show . and ..
  showHidden - show hidden files (. files on unix)
*/
bool flagShowHidden = false, flagShowDotLinks = false;
bool flagPrintUnprintableChars = false, flagUseCEscapeCodes = false;
/* multi col should be false when piping */
bool flagMultiColOutput = true, flagOneColOutput = false, flagSortAcross = false;
/* showPathSymbol == -P			showDirSymbol == -F */
bool flagShowPathSymbol = false, flagShowDirSymbol = false;
bool flagColorize = false;
bool flagFollowSymLinks = true, flagFollowArgumentSymLinks = false;
/* never be recursive is for the the -d option */
bool flagBeRecursive = false, flagNeverBeRecursive = false;
/* don't sort should be false - but I don't feel like sorting yet */
bool flagSortBySize = false, flagSortTimeCreated = false, flagSortByLastChanged = false, flagDontSort = true, flagReverseSort = false, flagSortTimeModified, flagSortLastAccess;
bool flagShowCompleteTimeInfo = false;
/* the -W option */
bool flagDisplayWhiteouts = false;
bool flagDisplayMacLabel = false;
bool flagFileSizeHumanReadable = false;
bool flagDisplayFileInodeNum = false, flagDisplayNumBlocks = false;
bool flag1024BlockSize = false;
bool flagDisplayLong = false, flagShowFileFlags = false;
bool flagStreamOutput = false;
bool flagDisplayUidAsNumber = false;
bool flagDisplayNonGraphicAsQuestionMark = false;
bool flagRawNonGraphic = true;

/* we use these quite often and std:: is annoying) */
using std::string;

typedef std::map<string,string> fileMap;
typedef boost::optional<fileMap> optFileMap;

optFileMap getFileMap(bf::directory_iterator dir_itr);
void printFile(fileMap data);
void opArg(const char* arg);
string permStringFromStatMode(mode_t mode);
char* get_link_location (const char *filename);

int main(int argc, char *argv[])
{
	/* lets go through the arguments now */
	int c;
	if (getuid() == static_cast<uid_t>(0))
	{
		flagShowHidden = true;
	}
	// SUcfrtux are not compatible with our system as they require sorting
	while ((c = getopt (argc, argv, "ABCFGHILPRSTUWZabcdfhiklmnopqrstuwx1")) != -1)
	{
		switch (c)
		{
			case 'A':
				flagShowHidden = true;
				flagShowDotLinks = false;
				break;
			case 'F':
				flagShowPathSymbol = true;
				flagFollowSymLinks = false;
				break;
			case 'I':
				flagShowHidden = false;
				break;
			case 'H':
				flagFollowSymLinks = true;
				break;
			case 'R':
				flagBeRecursive = true;
				break;
			case 'W':
				flagDisplayWhiteouts=true;
				break;
			case 'a':
				flagShowHidden = true;
				flagShowDotLinks = true;
				break;
			case 'd':
				flagNeverBeRecursive = true;
				break;
			case 'i':
				flagDisplayFileInodeNum = true;
				break;
			case 'l':
				flagDisplayLong = true;
				flagFollowSymLinks = false;
				break;
			case 'm':
				flagStreamOutput = true;
				break;
			case 'n':
				flagDisplayUidAsNumber = true;
				break;
			case 'p':
				flagShowDirSymbol = true;
				break;
			case 'r':
				flagReverseSort = true;
				break;
			case '1':
				flagOneColOutput = true;
				break;
			default:
				break;
		}
	}

	if (argc > optind)
	{
		int i;
		for (i = optind; i < argc; ++i)
		{
			opArg(argv[i]);
		}
	}
	else
	{
		opArg(".");
	}
	std::cout << std::endl;
}

void usage()
{
	std::cout << "usage: ls [-ABCFGHILPRSTUWZabcdfhiklmnopqrstuwx1] [-D format] [file ...]" << std::endl;
	exit(EX_USAGE);
}

optFileMap getFileMap(bf::directory_iterator dir_itr)
{
	fileMap result;
	std::string file_name = dir_itr->path().filename();

	struct stat buf;
	int status;
	errno=0;
	if (flagFollowSymLinks)
	{
		status = stat(file_name.c_str(), &buf);
	}
	else
	{
		status = lstat(file_name.c_str(), &buf);
	}
	if (errno!=0)
	{
		//I think we have some kind of problem - so lets get out of here for now. I will have to deal with this case later
		// this really should be errx + EX_OSERR -> but I'm leaving it as warnx as this is OUR problem while I clean up stuff from the data/print split 
		warnx("stat != 0");
		return optFileMap();
	}
	/* if we don't display whiteouts -> and this is a whiteout get out of here */
	if (!flagDisplayWhiteouts && S_ISWHT(buf.st_mode))
	{
		return optFileMap();
	}
	if (file_name[0] == '.' && !flagShowHidden)
	{
		return optFileMap();
		// we are a hidden file so lets get outa here
	}
	result["permstring"] = permStringFromStatMode(buf.st_mode);
	try
	{
		result["link_to"] = boost::lexical_cast<std::string>(buf.st_nlink);
		if (flagDisplayUidAsNumber)
		{
			result["uid"] = boost::lexical_cast<std::string>(buf.st_uid);
			result["gid"] = boost::lexical_cast<std::string>(buf.st_gid);
		}
		else
		{
			// not standard - see if there is a better way of doing this
			result["uid"] = user_from_uid(buf.st_uid,0);
			result["gid"] = group_from_gid(buf.st_gid,0);
		}
		result["mod_time"]= boost::lexical_cast<std::string>(buf.st_mtime);
		result["serial"]= boost::lexical_cast<std::string>(buf.st_ino);
		result["size"]= boost::lexical_cast<std::string>(buf.st_size);
	}
	catch(boost::bad_lexical_cast& e)
	{
		errx(1,"bad lexical cast");
	}
	result["filename"] = file_name;
	/* change to boost status??? */
	result["linkloc"] ="___no___";
	if (buf.st_mode && S_IFLNK)
	{
		result["linkloc"] = get_link_location(file_name.c_str());
	}

	/* -F stuff */
	result["post_symbol"]="";
	if (flagShowPathSymbol)
	{
		result["post_symbol"]=get_post_symbol(dir_itr,buf);
	}
	/* -p stuff */
	else if (flagShowDirSymbol && bf::is_directory(*dir_itr))
	{
			result["post_symbol"]="/";
	}
	return result;
}

void opArg(const char* arg)
{
	std::vector<fileMap> fileList;
	try
	{
		bf::path workingDir(arg);
		/* resolve the path */
		workingDir = bf::system_complete(workingDir);
  		if ( bf::exists( workingDir ) )
		{
			if ( bf::is_directory( workingDir ) )
			{
    			bf::directory_iterator end_iter;
				for (bf::directory_iterator dir_itr( workingDir ); dir_itr != end_iter; ++dir_itr)
				{
					optFileMap data = getFileMap(dir_itr);
					if (data)
					{
						if ( bf::is_directory( dir_itr->status() ) )
    	    			{
							std::cout << dir_itr->path().filename() << ": [directory]\n";
							opArg(dir_itr->path().filename().c_str());
        				}
						fileList.push_back(*data);
					}
				}
			}
			else
			{
				/* deal with this later */
			}
		}
		else
		{
			errx(1,"No such file or directory");
		}
	}
	catch (bf::filesystem_error e)
	{
		std::cout << "Exception occured!" << e.what() << std::endl;
	}
	// by default lets go by fileName
	const char sortBy[] = "filename";
	boost::function<bool(fileMap, fileMap)> bindResult = boost::bind(std::less<std::string>(),boost::bind(&fileMap::operator[],_1,sortBy),boost::bind(&fileMap::operator[],_2,sortBy));
	std::sort(fileList.begin(), fileList.end(), bindResult);
	if (flagReverseSort)
	{
		swap_ranges( fileList.begin(), fileList.begin() + fileList.size() / 2, fileList.rbegin() );
	}
	BOOST_FOREACH(fileMap &it, fileList)
	{
    	printFile(it);
		if (flagOneColOutput || flagDisplayLong)
		{
			std::cout << std::endl;
		}
		else if (flagStreamOutput)
		{
			std::cout << ",";
		}
		else
		{
			std::cout << ' ';
		}
	}
}


std::string permStringFromStatMode(mode_t mode)
{
	std::string result;
	result.resize(10);
	// Use a bodyless for loop to set all members to "-"
	for (int i=0; i<10; result[i++]='-');

	/* As per man page the third item of each "set" gets treated differently */

	//-rw-rw-r--
	//0123456789
	if (mode & S_IRUSR)
		result[1]='r';
	if (mode & S_IWUSR)
		result[2]='w';
	if (mode & S_ISUID)
	{
		if (mode & S_IXUSR)
		{
			result[3]='s';
		}
		else
		{
			result[3]='S';
		}
	}
	else if (mode & S_IXUSR)
	{
		result[3]='x';
	}
	if (mode & S_IRGRP)
		result[4]='r';
	if (mode & S_IWGRP)
		result[5]='w';
	if (mode & S_ISGID)
	{
		if (mode & S_IXGRP)
		{
			result[6]='s';
		}
		else
		{
			result[6]='S';
		}
	}
	else if (mode & S_IXGRP)
	{
		result[6]='x';
	}

	if (mode & S_IROTH)
		result[7]='r';
	if (mode & S_IWOTH)
		result[8]='w';
	if (mode & S_ISTXT)
	{
		if (mode & S_IXOTH)
		{
			result[9]='t';
		}
		else
		{
			result[9]='T';
		}
	}
	else if (mode & S_IXOTH)
	{
		result[9]='x';
	}

	if (mode & S_IFREG)
		result[0]='-';
	else if (mode & S_IFBLK)
		result[0]='b';
	else if (mode & S_IFCHR)
		result[0]='c';
	else if (mode & S_IFDIR)
		result[0]='d';
	else if (mode & S_IFLNK)
		result[0]='l';
	else if (mode & S_IFIFO)
		result[0]='p';
	else if (mode & S_IFSOCK)
		result[0]='s';
	else if (mode & S_IFWHT)
		result[0]='w';
	return result;
}

void printFile(fileMap data)
{
	// we got a foo - we will have to fix this method of testing later...
	if (data["noprint"]=="true")
		return;

	if (flagDisplayLong)
	{
		std::cout << data["permstring"] << ' ' << data["link_to"] << ' ' <<data["uid"] << ' ' <<data["gid"];
		std::cout << ' ' << data["mod_time"];
		if (flagDisplayFileInodeNum)
		{
			std::cout << ' ' << data["serial"];
		}
		std::cout << ' ' << data["size"] << ' ';
	}
	std::cout << data["filename"] << data["post_symbol"];
	std::cout << "->" << data["linkloc"];
	/* should this be moved to the "meta-printer" as each file should not know how it will be printed? ? ? ?*/
}

char* get_link_location (const char* filename)
{
	int size = 255;
	while (1) {
		char *buffer = new char[size];
		int nchars = readlink (filename, buffer, size);
		if (nchars < 0)
			return NULL;
		if (nchars < size) {
			buffer[nchars] = '\0';
			return buffer;
		}
		delete[] buffer;
		size *= 2;
	}
}