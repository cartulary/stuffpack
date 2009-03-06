/* Unix Socket Echo client
 * Copyright (C) 2001  Mark Ferlatte
 * Adapted from echoclient.c, Copyright (C) 2000  David Helder
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#define GNET_EXPERIMENTAL 1
#include <gnet.h>	/* Or <gnet/gnet.h> when installed. */

static void usage (int status);

static void normal_echoclient (gchar* path);

int
main(int argc, char** argv)
{

  gnet_init ();

  	if (argc != 2 && argc != 3)
	{
    		usage(EXIT_FAILURE);
	}

    g_print ("Normal echo client running\n");
    normal_echoclient(argv[argc - 1]);

  return 0;
}

static void
usage (int status)
{
	g_print ("usage: echoclient <path>\n");
	exit(status);
}


static void
normal_echoclient(gchar* path)
{
  GUnixSocket *socket = NULL;
  GIOChannel* iochannel = NULL;
  gchar buffer[1024];
  guint n;
  GIOError e = G_IO_ERROR_NONE;

  g_assert(path != NULL);

  /* Create the socket */
  socket = gnet_unix_socket_new(path);
  g_assert (socket != NULL);

  /* Get the IOChannel */
  iochannel = gnet_unix_socket_get_iochannel(socket);
  g_assert (iochannel != NULL);

  	while (fgets(buffer, sizeof(buffer), stdin) != 0)
	{
 	   	n = strlen(buffer);
    		e = gnet_io_channel_writen(iochannel, buffer, n, &n);
    		if (e != G_IO_ERROR_NONE)
		{
	      	break;
		}
    		e = gnet_io_channel_readn(iochannel, buffer, n, &n);
    		if (e != G_IO_ERROR_NONE)
	      	break;
		printf("server:");
    		fwrite(buffer, n, 1, stdout);
  	}

  	if (e != G_IO_ERROR_NONE)
	{
    		g_print ("IO error (%d)\n", e);
	}
  return;
}
