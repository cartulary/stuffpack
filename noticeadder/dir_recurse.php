<?php
// http://www.sourcerally.net/Scripts/41-rmdir-and-scandir-recursively
/*
//remove directory recursively
directoryUtility::remove($dirname);

//scan directory recursively
$dir = directoryUtility::scan($dirname));
print_r($dir);
*/
class directoryUtility
{
    function scan($dirname)
    {
        $array = array();
        $dir = new RecursiveDirectoryIterator($dirname);
        foreach($dir as $k => $v)
        {
            if(!$dir->isDot())
            {
                $array[]=$v->getPathname();
            }
            if($v->isDir())
            {
                $subArray = directoryUtility::scan($v->getPathname());
                $array = array_merge($array,$subArray);
            }
        }
        return $array;
    }
    
    function remove($dirname)
    {
        if(is_dir($dirname))
        {
            $dir = new RecursiveDirectoryIterator($dirname);
            foreach($dir as $k => $v)
            {
                if(!$dir->isDot())
                {
                    if($v->isDir()&&$v->hasChildren())
                    {
                        directoryUtility::remove($v->getPathname());
                    }
                    else
                    {
                        unlink($v->getPathname());
                    }
                }
            }
            unset($dir);
            rmdir($dirname);
            return true;
        }
        return false;
    }
}
?> 
