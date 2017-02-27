/*
 * vim: ts=8 sw=8
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

static	char		*me = "sissy";
static	char		*cmd = "false";

int
main(
	int		argc,
	char * *	argv
)
{
	int		c;
	int		status;

	opterr = 0;
	while( (c = getopt( argc, argv, "c:" )) != EOF )	{
		switch( c )	{
		default:
			fprintf(
				stderr, 
				"%s: switch -%c not implemented yet.\n",
				me,
				c
			);
			exit( 1 );
		case '?':
			fprintf(
				stderr,
				"%s: unknown switch '-%s'.\n",
				me,
				optarg
			);
			exit( 1 );
		case 'c':
			cmd = optarg;
			break;
		}
	}
	if( optind < argc )	{
		fprintf(
			stderr,
			"%s: too many arguments!\n",
			me
		);
		exit( 1 );
	}
	setbuf( stdout, NULL );
	printf( "--> About to |%s|\n", cmd );
	status = system( cmd );
	switch( status )	{
	default:
		printf( "--> Exited with status %u.\n", status );
		exit( 1 );
	case -1:
		fprintf(
			stderr,
			"%s: some forking error (%s) or other!\n",
			me,
			strerror( errno )
		);
		exit( 1 );
	case 0:
		puts( "--> Hunky-dory" );
		break;
	}
	return( 0 );
}
