/*
 * Copyright (c) 20014 Gauthier Voron.
 *
 * This file is part of Netio.
 *
 * Netio is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * Netio is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Netio. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef NETIO_UDP_H
#define NETIO_UDP_H


struct netio_udp;
typedef struct netio_udp netio_udp_t;


#include "netio/header.h"
#include "netio/protocol.h"


extern netio_protocol_t *NETIO_UDP_PROTOCOL;


#define NETIO_UDP_PORT_TCPMUX            1 /* TCP Port Service Multiplexer */
#define NETIO_UDP_PORT_COMPRESSNETMAN    2 /* Management Utility */
#define NETIO_UDP_PORT_COMPRESSNET       3 /* Compression Process */
#define NETIO_UDP_PORT_RJE               5 /* Remote Job Entry */
#define NETIO_UDP_PORT_ECHO              7 /* Echo */
#define NETIO_UDP_PORT_DISCARD           9 /* Discard */
#define NETIO_UDP_PORT_SYSTAT            11 /* Active Users */
#define NETIO_UDP_PORT_DAYTIME           13 /* Daytime */
#define NETIO_UDP_PORT_QOTD              17 /* Quote of the Day */
#define NETIO_UDP_PORT_MSP               18 /* Message Send Protocol (historic) */
#define NETIO_UDP_PORT_CHARGEN           19 /* Character Generator */
#define NETIO_UDP_PORT_FTP_DATA          20 /* File Transfer [Default Data] */
#define NETIO_UDP_PORT_FTP               21 /* File Transfer [Control] */
#define NETIO_UDP_PORT_SSH               22 /* The Secure Shell (SSH) Protocol */
#define NETIO_UDP_PORT_TELNET            23 /* Telnet */
#define NETIO_UDP_PORT_SMTP              25 /* Simple Mail Transfer */
#define NETIO_UDP_PORT_NSW_FE            27 /* NSW User System FE */
#define NETIO_UDP_PORT_MSG_ICP           29 /* MSG ICP */
#define NETIO_UDP_PORT_MSG_AUTH          31 /* MSG Authentication */
#define NETIO_UDP_PORT_DSP               33 /* Display Support Protocol */
#define NETIO_UDP_PORT_TIME              37 /* Time */
#define NETIO_UDP_PORT_RAP               38 /* Route Access Protocol */
#define NETIO_UDP_PORT_RLP               39 /* Resource Location Protocol */
#define NETIO_UDP_PORT_GRAPHICS          41 /* Graphics */
#define NETIO_UDP_PORT_NAME              42 /* Host Name Server */
#define NETIO_UDP_PORT_NICNAME           43 /* Who Is */
#define NETIO_UDP_PORT_MPM_FLAGS         44 /* MPM FLAGS Protocol */
#define NETIO_UDP_PORT_MPM               45 /* Message Processing Module [recv] */
#define NETIO_UDP_PORT_MPM_SND           46 /* MPM [default send] */
#define NETIO_UDP_PORT_NI_FTP            47 /* NI FTP */
#define NETIO_UDP_PORT_AUDITD            48 /* Digital Audit Daemon */
#define NETIO_UDP_PORT_TACACS            49 /* Login Host Protocol (TACACS) */
#define NETIO_UDP_PORT_RE_MAIL_CK        50 /* Remote Mail Checking Protocol */
#define NETIO_UDP_PORT_XNS_TIME          52 /* XNS Time Protocol */
#define NETIO_UDP_PORT_DOMAIN            53 /* Domain Name Server */
#define NETIO_UDP_PORT_XNS_CH            54 /* XNS Clearinghouse */
#define NETIO_UDP_PORT_ISI_GL            55 /* ISI Graphics Language */
#define NETIO_UDP_PORT_XNS_AUTH          56 /* XNS Authentication */
#define NETIO_UDP_PORT_XNS_MAIL          58 /* XNS Mail */
#define NETIO_UDP_PORT_NI_MAIL           61 /* NI MAIL */
#define NETIO_UDP_PORT_ACAS              62 /* ACA Services */
#define NETIO_UDP_PORT_WHOISPP           63 /* "whois++ */
#define NETIO_UDP_PORT_COVIA             64 /* Communications Integrator (CI) */
#define NETIO_UDP_PORT_TACACS_DS         65 /* TACACS-Database Service */
#define NETIO_UDP_PORT_OSQL_NET          66 /* "Oracle SQL*NET */
#define NETIO_UDP_PORT_BOOTPS            67 /* Bootstrap Protocol Server */
#define NETIO_UDP_PORT_BOOTPC            68 /* Bootstrap Protocol Client */
#define NETIO_UDP_PORT_TFTP              69 /* Trivial File Transfer */
#define NETIO_UDP_PORT_GOPHER            70 /* Gopher */
#define NETIO_UDP_PORT_NETRJS_1          71 /* Remote Job Service */
#define NETIO_UDP_PORT_NETRJS_2          72 /* Remote Job Service */
#define NETIO_UDP_PORT_NETRJS_3          73 /* Remote Job Service */
#define NETIO_UDP_PORT_NETRJS_4          74 /* Remote Job Service */
#define NETIO_UDP_PORT_DEOS              76 /* Distributed External Object Store */
#define NETIO_UDP_PORT_VETTCP            78 /* vettcp */
#define NETIO_UDP_PORT_FINGER            79 /* Finger */
#define NETIO_UDP_PORT_HTTP              80 /* World Wide Web HTTP */
#define NETIO_UDP_PORT_XFER              82 /* XFER Utility */
#define NETIO_UDP_PORT_MIT_ML_DEV        83 /* MIT ML Device */
#define NETIO_UDP_PORT_CTF               84 /* Common Trace Facility */
#define NETIO_UDP_PORT_MIT_ML_DEV2       85 /* MIT ML Device */
#define NETIO_UDP_PORT_MFCOBOL           86 /* Micro Focus Cobol */
#define NETIO_UDP_PORT_KERBEROS          88 /* Kerberos */
#define NETIO_UDP_PORT_SU_MIT_TG         89 /* SU/MIT Telnet Gateway */
#define NETIO_UDP_PORT_DNSIX             90 /* DNSIX Securit Attribute Token Map */
#define NETIO_UDP_PORT_MIT_DOV           91 /* MIT Dover Spooler */
#define NETIO_UDP_PORT_NPP               92 /* Network Printing Protocol */
#define NETIO_UDP_PORT_DCP               93 /* Device Control Protocol */
#define NETIO_UDP_PORT_OBJCALL           94 /* Tivoli Object Dispatcher */
#define NETIO_UDP_PORT_SUPDUP            95 /* SUPDUP */
#define NETIO_UDP_PORT_DIXIE             96 /* DIXIE Protocol Specification */
#define NETIO_UDP_PORT_SWIFT_RVF         97 /* Swift Remote Virtural File Protocol */
#define NETIO_UDP_PORT_TACNEWS           98 /* TAC News */
#define NETIO_UDP_PORT_METAGRAM          99 /* Metagram Relay */
#define NETIO_UDP_PORT_HOSTNAME          101 /* NIC Host Name Server */
#define NETIO_UDP_PORT_ISO_TSAP          102 /* ISO-TSAP Class 0 */
#define NETIO_UDP_PORT_GPPITNP           103 /* Genesis Point-to-Point Trans Net */
#define NETIO_UDP_PORT_ACR_NEMA          104 /* ACR-NEMA Digital Imag. & Comm. 300 */
#define NETIO_UDP_PORT_CSO               105 /* CCSO name server protocol */
#define NETIO_UDP_PORT_3COM_TSMUX        106 /* 3COM-TSMUX */
#define NETIO_UDP_PORT_RTELNET           107 /* Remote Telnet Service */
#define NETIO_UDP_PORT_SNAGAS            108 /* SNA Gateway Access Server */
#define NETIO_UDP_PORT_POP2              109 /* Post Office Protocol - Version 2 */
#define NETIO_UDP_PORT_POP3              110 /* Post Office Protocol - Version 3 */
#define NETIO_UDP_PORT_SUNRPC            111 /* SUN Remote Procedure Call */
#define NETIO_UDP_PORT_MCIDAS            112 /* McIDAS Data Transmission Protocol */
#define NETIO_UDP_PORT_AUTH              113 /* Authentication Service */
#define NETIO_UDP_PORT_SFTP              115 /* Simple File Transfer Protocol */
#define NETIO_UDP_PORT_ANSANOTIFY        116 /* ANSA REX Notify */
#define NETIO_UDP_PORT_UUCP_PATH         117 /* UUCP Path Service */
#define NETIO_UDP_PORT_SQLSERV           118 /* SQL Services */
#define NETIO_UDP_PORT_NNTP              119 /* Network News Transfer Protocol */
#define NETIO_UDP_PORT_CFDPTKT           120 /* CFDPTKT */
#define NETIO_UDP_PORT_ERPC              121 /* Encore Expedited Remote Pro.Call */
#define NETIO_UDP_PORT_SMAKYNET          122 /* SMAKYNET */
#define NETIO_UDP_PORT_NTP               123 /* Network Time Protocol */
#define NETIO_UDP_PORT_ANSATRADER        124 /* ANSA REX Trader */
#define NETIO_UDP_PORT_LOCUS_MAP         125 /* Locus PC-Interface Net Map Ser */
#define NETIO_UDP_PORT_NXEDIT            126 /* NXEdit */
#define NETIO_UDP_PORT_LOCUS_CON         127 /* Locus PC-Interface Conn Server */
#define NETIO_UDP_PORT_GSS_XLICEN        128 /* GSS X License Verification */
#define NETIO_UDP_PORT_PWDGEN            129 /* Password Generator Protocol */
#define NETIO_UDP_PORT_CISCO_FNA         130 /* cisco FNATIVE */
#define NETIO_UDP_PORT_CISCO_TNA         131 /* cisco TNATIVE */
#define NETIO_UDP_PORT_CISCO_SYS         132 /* cisco SYSMAINT */
#define NETIO_UDP_PORT_STATSRV           133 /* Statistics Service */
#define NETIO_UDP_PORT_INGRES_NET        134 /* INGRES-NET Service */
#define NETIO_UDP_PORT_EPMAP             135 /* DCE endpoint resolution */
#define NETIO_UDP_PORT_PROFILE           136 /* PROFILE Naming System */
#define NETIO_UDP_PORT_NETBIOS_NS        137 /* NETBIOS Name Service */
#define NETIO_UDP_PORT_NETBIOS_DGM       138 /* NETBIOS Datagram Service */
#define NETIO_UDP_PORT_NETBIOS_SSN       139 /* NETBIOS Session Service */
#define NETIO_UDP_PORT_EMFIS_DATA        140 /* EMFIS Data Service */
#define NETIO_UDP_PORT_EMFIS_CNTL        141 /* EMFIS Control Service */
#define NETIO_UDP_PORT_BL_IDM            142 /* Britton-Lee IDM */
#define NETIO_UDP_PORT_IMAP              143 /* Internet Message Access Protocol */
#define NETIO_UDP_PORT_UMA               144 /* Universal Management Architecture */
#define NETIO_UDP_PORT_UAAC              145 /* UAAC Protocol */
#define NETIO_UDP_PORT_ISO_TP0           146 /* ISO-IP0 */
#define NETIO_UDP_PORT_ISO_IP            147 /* ISO-IP */
#define NETIO_UDP_PORT_JARGON            148 /* Jargon */
#define NETIO_UDP_PORT_AED_512           149 /* AED 512 Emulation Service */
#define NETIO_UDP_PORT_SQL_NET           150 /* SQL-NET */
#define NETIO_UDP_PORT_HEMS              151 /* HEMS */
#define NETIO_UDP_PORT_BFTP              152 /* Background File Transfer Program */
#define NETIO_UDP_PORT_SGMP              153 /* SGMP */
#define NETIO_UDP_PORT_NETSC_PROD        154 /* NETSC */
#define NETIO_UDP_PORT_NETSC_DEV         155 /* NETSC */
#define NETIO_UDP_PORT_SQLSRV            156 /* SQL Service */
#define NETIO_UDP_PORT_KNET_CMP          157 /* KNET/VM Command/Message Protocol */
#define NETIO_UDP_PORT_PCMAIL_SRV        158 /* PCMail Server */
#define NETIO_UDP_PORT_NSS_ROUTING       159 /* NSS-Routing */
#define NETIO_UDP_PORT_SGMP_TRAPS        160 /* SGMP-TRAPS */
#define NETIO_UDP_PORT_SNMP              161 /* SNMP */
#define NETIO_UDP_PORT_SNMPTRAP          162 /* SNMPTRAP */
#define NETIO_UDP_PORT_CMIP_MAN          163 /* CMIP/TCP Manager */
#define NETIO_UDP_PORT_CMIP_AGENT        164 /* CMIP/TCP Agent */
#define NETIO_UDP_PORT_XNS_COURIER       165 /* Xerox */
#define NETIO_UDP_PORT_S_NET             166 /* Sirius Systems */
#define NETIO_UDP_PORT_NAMP              167 /* NAMP */
#define NETIO_UDP_PORT_RSVD              168 /* RSVD */
#define NETIO_UDP_PORT_SEND              169 /* SEND */
#define NETIO_UDP_PORT_PRINT_SRV         170 /* Network PostScript */
#define NETIO_UDP_PORT_MULTIPLEX         171 /* Network Innovations Multiplex */
#define NETIO_UDP_PORT_CL_1              172 /* "Network Innovations CL/1 */
#define NETIO_UDP_PORT_XYPLEX_MUX        173 /* Xyplex */
#define NETIO_UDP_PORT_MAILQ             174 /* MAILQ */
#define NETIO_UDP_PORT_VMNET             175 /* VMNET */
#define NETIO_UDP_PORT_GENRAD_MUX        176 /* GENRAD-MUX */
#define NETIO_UDP_PORT_XDMCP             177 /* X Display Manager Control Protocol */
#define NETIO_UDP_PORT_NEXTSTEP          178 /* NextStep Window Server */
#define NETIO_UDP_PORT_BGP               179 /* Border Gateway Protocol */
#define NETIO_UDP_PORT_RIS               180 /* Intergraph */
#define NETIO_UDP_PORT_UNIFY             181 /* Unify */
#define NETIO_UDP_PORT_AUDIT             182 /* Unisys Audit SITP */
#define NETIO_UDP_PORT_OCBINDER          183 /* OCBinder */
#define NETIO_UDP_PORT_OCSERVER          184 /* OCServer */
#define NETIO_UDP_PORT_REMOTE_KIS        185 /* Remote-KIS */
#define NETIO_UDP_PORT_KIS               186 /* KIS Protocol */
#define NETIO_UDP_PORT_ACI               187 /* Application Communication Interface */
#define NETIO_UDP_PORT_MUMPS             188 /* Plus Five's MUMPS */
#define NETIO_UDP_PORT_QFT               189 /* Queued File Transport */
#define NETIO_UDP_PORT_GACP              190 /* Gateway Access Control Protocol */
#define NETIO_UDP_PORT_PROSPERO          191 /* Prospero Directory Service */
#define NETIO_UDP_PORT_OSU_NMS           192 /* OSU Network Monitoring System */
#define NETIO_UDP_PORT_SRMP              193 /* Spider Remote Monitoring Protocol */
#define NETIO_UDP_PORT_IRC               194 /* Internet Relay Chat Protocol */
#define NETIO_UDP_PORT_DN6_NLM_AUD       195 /* DNSIX Network Level Module Audit */
#define NETIO_UDP_PORT_DN6_SMM_RED       196 /* DNSIX Session Mgt Module Audit Redir */
#define NETIO_UDP_PORT_DLS               197 /* Directory Location Service */
#define NETIO_UDP_PORT_DLS_MON           198 /* Directory Location Service Monitor */
#define NETIO_UDP_PORT_SMUX              199 /* SMUX */
#define NETIO_UDP_PORT_SRC               200 /* IBM System Resource Controller */
#define NETIO_UDP_PORT_AT_RTMP           201 /* AppleTalk Routing Maintenance */
#define NETIO_UDP_PORT_AT_NBP            202 /* AppleTalk Name Binding */
#define NETIO_UDP_PORT_AT_3              203 /* AppleTalk Unused */
#define NETIO_UDP_PORT_AT_ECHO           204 /* AppleTalk Echo */
#define NETIO_UDP_PORT_AT_5              205 /* AppleTalk Unused */
#define NETIO_UDP_PORT_AT_ZIS            206 /* AppleTalk Zone Information */
#define NETIO_UDP_PORT_AT_7              207 /* AppleTalk Unused */
#define NETIO_UDP_PORT_AT_8              208 /* AppleTalk Unused */
#define NETIO_UDP_PORT_QMTP              209 /* The Quick Mail Transfer Protocol */
#define NETIO_UDP_PORT_Z39_50            210 /* "ANSI Z39.50 */
#define NETIO_UDP_PORT_914C_G            211 /* "Texas Instruments 914C/G Terminal */
#define NETIO_UDP_PORT_ANET              212 /* ATEXSSTR */
#define NETIO_UDP_PORT_IPX               213 /* IPX */
#define NETIO_UDP_PORT_VMPWSCS           214 /* VM PWSCS */
#define NETIO_UDP_PORT_SOFTPC            215 /* Insignia Solutions */
#define NETIO_UDP_PORT_CAILIC            216 /* Computer Associates Int'l License Server */
#define NETIO_UDP_PORT_DBASE             217 /* dBASE Unix */
#define NETIO_UDP_PORT_MPP               218 /* Netix Message Posting Protocol */
#define NETIO_UDP_PORT_UARPS             219 /* Unisys ARPs */
#define NETIO_UDP_PORT_IMAP3             220 /* Interactive Mail Access Protocol v3 */
#define NETIO_UDP_PORT_FLN_SPX           221 /* Berkeley rlogind with SPX auth */
#define NETIO_UDP_PORT_RSH_SPX           222 /* Berkeley rshd with SPX auth */
#define NETIO_UDP_PORT_CDC               223 /* Certificate Distribution Center */
#define NETIO_UDP_PORT_MASQDIALER        224 /* masqdialer */
#define NETIO_UDP_PORT_DIRECT            242 /* Direct */
#define NETIO_UDP_PORT_SUR_MEAS          243 /* Survey Measurement */
#define NETIO_UDP_PORT_INBUSINESS        244 /* inbusiness */
#define NETIO_UDP_PORT_LINK              245 /* LINK */
#define NETIO_UDP_PORT_DSP3270           246 /* Display Systems Protocol */
#define NETIO_UDP_PORT_SUBNTBCST_TFTP    247 /* "SUBNTBCST_TFTP */
#define NETIO_UDP_PORT_BHFHS             248 /* bhfhs */
#define NETIO_UDP_PORT_RAP2              256 /* RAP */
#define NETIO_UDP_PORT_SET               257 /* Secure Electronic Transaction */
#define NETIO_UDP_PORT_ESRO_GEN          259 /* Efficient Short Remote Operations */
#define NETIO_UDP_PORT_OPENPORT          260 /* Openport */
#define NETIO_UDP_PORT_NSIIOPS           261 /* IIOP Name Service over TLS/SSL */
#define NETIO_UDP_PORT_ARCISDMS          262 /* Arcisdms */
#define NETIO_UDP_PORT_HDAP              263 /* HDAP */
#define NETIO_UDP_PORT_BGMP              264 /* BGMP */
#define NETIO_UDP_PORT_X_BONE_CTL        265 /* X-Bone CTL */
#define NETIO_UDP_PORT_SST               266 /* SCSI on ST */
#define NETIO_UDP_PORT_TD_SERVICE        267 /* Tobit David Service Layer */
#define NETIO_UDP_PORT_TD_REPLICA        268 /* Tobit David Replica */
#define NETIO_UDP_PORT_MANET             269 /* MANET Protocols */
#define NETIO_UDP_PORT_GIST              270 /* Q-mode encapsulation for GIST messages */
#define NETIO_UDP_PORT_HTTP_MGMT         280 /* http-mgmt */
#define NETIO_UDP_PORT_PERSONAL_LINK     281 /* Personal Link */
#define NETIO_UDP_PORT_CABLEPORT_AX      282 /* Cable Port A/X */
#define NETIO_UDP_PORT_RESCAP            283 /* rescap */
#define NETIO_UDP_PORT_CORERJD           284 /* corerjd */
#define NETIO_UDP_PORT_FXP               286 /* FXP Communication */
#define NETIO_UDP_PORT_K_BLOCK           287 /* K-BLOCK */
#define NETIO_UDP_PORT_NOVASTORBAKCUP    308 /* Novastor Backup */
#define NETIO_UDP_PORT_ENTRUSTTIME       309 /* EntrustTime */
#define NETIO_UDP_PORT_BHMDS             310 /* bhmds */
#define NETIO_UDP_PORT_ASIP_WEBADMIN     311 /* AppleShare IP WebAdmin */
#define NETIO_UDP_PORT_VSLMP             312 /* VSLMP */
#define NETIO_UDP_PORT_MAGENTA_LOGIC     313 /* Magenta Logic */
#define NETIO_UDP_PORT_OPALIS_ROBOT      314 /* Opalis Robot */
#define NETIO_UDP_PORT_DPSI              315 /* DPSI */
#define NETIO_UDP_PORT_DECAUTH           316 /* decAuth */
#define NETIO_UDP_PORT_ZANNET            317 /* Zannet */
#define NETIO_UDP_PORT_PKIX_TIMESTAMP    318 /* PKIX TimeStamp */
#define NETIO_UDP_PORT_PTP_EVENT         319 /* PTP Event */
#define NETIO_UDP_PORT_PTP_GENERAL       320 /* PTP General */
#define NETIO_UDP_PORT_PIP               321 /* PIP */
#define NETIO_UDP_PORT_RTSPS             322 /* RTSPS */
#define NETIO_UDP_PORT_TEXAR             333 /* Texar Security Port */
#define NETIO_UDP_PORT_PDAP              344 /* Prospero Data Access Protocol */
#define NETIO_UDP_PORT_PAWSERV           345 /* Perf Analysis Workbench */
#define NETIO_UDP_PORT_ZSERV             346 /* Zebra server */
#define NETIO_UDP_PORT_FATSERV           347 /* Fatmen Server */
#define NETIO_UDP_PORT_CSI_SGWP          348 /* Cabletron Management Protocol */
#define NETIO_UDP_PORT_MFTP              349 /* mftp */
#define NETIO_UDP_PORT_MATIP_TYPE_A      350 /* MATIP Type A */
#define NETIO_UDP_PORT_MATIP_TYPE_B      351 /* MATIP Type B */
#define NETIO_UDP_PORT_DTAG_STE_SB       352 /* DTAG */
#define NETIO_UDP_PORT_NDSAUTH           353 /* NDSAUTH */
#define NETIO_UDP_PORT_BH611             354 /* bh611 */
#define NETIO_UDP_PORT_DATEX_ASN         355 /* DATEX-ASN */
#define NETIO_UDP_PORT_CLOANTO_NET_1     356 /* Cloanto Net 1 */
#define NETIO_UDP_PORT_BHEVENT           357 /* bhevent */
#define NETIO_UDP_PORT_SHRINKWRAP        358 /* Shrinkwrap */
#define NETIO_UDP_PORT_NSRMP             359 /* Network Security Risk Management Protocol */
#define NETIO_UDP_PORT_SCOI2ODIALOG      360 /* scoi2odialog */
#define NETIO_UDP_PORT_SEMANTIX          361 /* Semantix */
#define NETIO_UDP_PORT_SRSSEND           362 /* SRS Send */
#define NETIO_UDP_PORT_RSVP_TUNNEL       363 /* "RSVP Tunnel */
#define NETIO_UDP_PORT_AURORA_CMGR       364 /* Aurora CMGR */
#define NETIO_UDP_PORT_DTK               365 /* DTK */
#define NETIO_UDP_PORT_ODMR              366 /* ODMR */
#define NETIO_UDP_PORT_MORTGAGEWARE      367 /* MortgageWare */
#define NETIO_UDP_PORT_QBIKGDP           368 /* QbikGDP */
#define NETIO_UDP_PORT_RPC2PORTMAP       369 /* rpc2portmap */
#define NETIO_UDP_PORT_CODAAUTH2         370 /* codaauth2 */
#define NETIO_UDP_PORT_CLEARCASE         371 /* Clearcase */
#define NETIO_UDP_PORT_ULISTPROC         372 /* ListProcessor */
#define NETIO_UDP_PORT_LEGENT_1          373 /* Legent Corporation */
#define NETIO_UDP_PORT_LEGENT_2          374 /* Legent Corporation */
#define NETIO_UDP_PORT_HASSLE            375 /* Hassle */
#define NETIO_UDP_PORT_NIP               376 /* Amiga Envoy Network Inquiry Proto */
#define NETIO_UDP_PORT_TNETOS            377 /* NEC Corporation */
#define NETIO_UDP_PORT_DSETOS            378 /* NEC Corporation */
#define NETIO_UDP_PORT_IS99C             379 /* TIA/EIA/IS-99 modem client */
#define NETIO_UDP_PORT_IS99S             380 /* TIA/EIA/IS-99 modem server */
#define NETIO_UDP_PORT_HP_COLLECTOR      381 /* hp performance data collector */
#define NETIO_UDP_PORT_HP_MANAGED_NODE   382 /* hp performance data managed node */
#define NETIO_UDP_PORT_HP_ALARM_MGR      383 /* hp performance data alarm manager */
#define NETIO_UDP_PORT_ARNS              384 /* A Remote Network Server System */
#define NETIO_UDP_PORT_IBM_APP           385 /* IBM Application */
#define NETIO_UDP_PORT_ASA               386 /* ASA Message Router Object Def. */
#define NETIO_UDP_PORT_AURP              387 /* Appletalk Update-Based Routing Pro. */
#define NETIO_UDP_PORT_UNIDATA_LDM       388 /* Unidata LDM */
#define NETIO_UDP_PORT_LDAP              389 /* Lightweight Directory Access Protocol */
#define NETIO_UDP_PORT_UIS               390 /* UIS */
#define NETIO_UDP_PORT_SYNOTICS_RELAY    391 /* SynOptics SNMP Relay Port */
#define NETIO_UDP_PORT_SYNOTICS_BROKER   392 /* SynOptics Port Broker Port */
#define NETIO_UDP_PORT_META5             393 /* Meta5 */
#define NETIO_UDP_PORT_EMBL_NDT          394 /* EMBL Nucleic Data Transfer */
#define NETIO_UDP_PORT_NETCP             395 /* NetScout Control Protocol */
#define NETIO_UDP_PORT_NETWARE_IP        396 /* Novell Netware over IP */
#define NETIO_UDP_PORT_MPTN              397 /* Multi Protocol Trans. Net. */
#define NETIO_UDP_PORT_KRYPTOLAN         398 /* Kryptolan */
#define NETIO_UDP_PORT_ISO_TSAP_C2       399 /* ISO Transport Class 2 Non-Control over UDP */
#define NETIO_UDP_PORT_OSB_SD            400 /* Oracle Secure Backup */
#define NETIO_UDP_PORT_UPS               401 /* Uninterruptible Power Supply */
#define NETIO_UDP_PORT_GENIE             402 /* Genie Protocol */
#define NETIO_UDP_PORT_DECAP             403 /* decap */
#define NETIO_UDP_PORT_NCED              404 /* nced */
#define NETIO_UDP_PORT_NCLD              405 /* ncld */
#define NETIO_UDP_PORT_IMSP              406 /* Interactive Mail Support Protocol */
#define NETIO_UDP_PORT_TIMBUKTU          407 /* Timbuktu */
#define NETIO_UDP_PORT_PRM_SM            408 /* Prospero Resource Manager Sys. Man. */
#define NETIO_UDP_PORT_PRM_NM            409 /* Prospero Resource Manager Node Man. */
#define NETIO_UDP_PORT_DECLADEBUG        410 /* DECLadebug Remote Debug Protocol */
#define NETIO_UDP_PORT_RMT               411 /* Remote MT Protocol */
#define NETIO_UDP_PORT_SYNOPTICS_TRAP    412 /* Trap Convention Port */
#define NETIO_UDP_PORT_SMSP              413 /* Storage Management Services Protocol */
#define NETIO_UDP_PORT_INFOSEEK          414 /* InfoSeek */
#define NETIO_UDP_PORT_BNET              415 /* BNet */
#define NETIO_UDP_PORT_SILVERPLATTER     416 /* Silverplatter */
#define NETIO_UDP_PORT_ONMUX             417 /* Onmux */
#define NETIO_UDP_PORT_HYPER_G           418 /* Hyper-G */
#define NETIO_UDP_PORT_ARIEL1            419 /* Ariel 1 */
#define NETIO_UDP_PORT_SMPTE             420 /* SMPTE */
#define NETIO_UDP_PORT_ARIEL2            421 /* Ariel 2 */
#define NETIO_UDP_PORT_ARIEL3            422 /* Ariel 3 */
#define NETIO_UDP_PORT_OPC_JOB_START     423 /* IBM Operations Planning and Control Start */
#define NETIO_UDP_PORT_OPC_JOB_TRACK     424 /* IBM Operations Planning and Control Track */
#define NETIO_UDP_PORT_ICAD_EL           425 /* ICAD */
#define NETIO_UDP_PORT_SMARTSDP          426 /* smartsdp */
#define NETIO_UDP_PORT_SVRLOC            427 /* Server Location */
#define NETIO_UDP_PORT_OCS_CMU           428 /* "OCS_CMU */
#define NETIO_UDP_PORT_OCS_AMU           429 /* "OCS_AMU */
#define NETIO_UDP_PORT_UTMPSD            430 /* UTMPSD */
#define NETIO_UDP_PORT_UTMPCD            431 /* UTMPCD */
#define NETIO_UDP_PORT_IASD              432 /* IASD */
#define NETIO_UDP_PORT_NNSP              433 /* NNSP */
#define NETIO_UDP_PORT_MOBILEIP_AGENT    434 /* MobileIP-Agent */
#define NETIO_UDP_PORT_MOBILIP_MN        435 /* MobilIP-MN */
#define NETIO_UDP_PORT_DNA_CML           436 /* DNA-CML */
#define NETIO_UDP_PORT_COMSCM            437 /* comscm */
#define NETIO_UDP_PORT_DSFGW             438 /* dsfgw */
#define NETIO_UDP_PORT_DASP              439 /* dasp */
#define NETIO_UDP_PORT_SGCP              440 /* sgcp */
#define NETIO_UDP_PORT_DECVMS_SYSMGT     441 /* decvms-sysmgt */
#define NETIO_UDP_PORT_CVC_HOSTD         442 /* "cvc_hostd */
#define NETIO_UDP_PORT_HTTPS             443 /* http protocol over TLS/SSL */
#define NETIO_UDP_PORT_SNPP              444 /* Simple Network Paging Protocol */
#define NETIO_UDP_PORT_MICROSOFT_DS      445 /* Microsoft-DS */
#define NETIO_UDP_PORT_DDM_RDB           446 /* DDM-Remote Relational Database Access */
#define NETIO_UDP_PORT_DDM_DFM           447 /* DDM-Distributed File Management */
#define NETIO_UDP_PORT_DDM_SSL           448 /* DDM-Remote DB Access Using Secure Sockets */
#define NETIO_UDP_PORT_AS_SERVERMAP      449 /* AS Server Mapper */
#define NETIO_UDP_PORT_TSERVER           450 /* Computer Supported Telecomunication Applications */
#define NETIO_UDP_PORT_SFS_SMP_NET       451 /* Cray Network Semaphore server */
#define NETIO_UDP_PORT_SFS_CONFIG        452 /* Cray SFS config server */
#define NETIO_UDP_PORT_CREATIVESERVER    453 /* CreativeServer */
#define NETIO_UDP_PORT_CONTENTSERVER     454 /* ContentServer */
#define NETIO_UDP_PORT_CREATIVEPARTNR    455 /* CreativePartnr */
#define NETIO_UDP_PORT_MACON_UDP         456 /* macon-udp */
#define NETIO_UDP_PORT_SCOHELP           457 /* scohelp */
#define NETIO_UDP_PORT_APPLEQTC          458 /* apple quick time */
#define NETIO_UDP_PORT_AMPR_RCMD         459 /* ampr-rcmd */
#define NETIO_UDP_PORT_SKRONK            460 /* skronk */
#define NETIO_UDP_PORT_DATASURFSRV       461 /* DataRampSrv */
#define NETIO_UDP_PORT_DATASURFSRVSEC    462 /* DataRampSrvSec */
#define NETIO_UDP_PORT_ALPES             463 /* alpes */
#define NETIO_UDP_PORT_KPASSWD           464 /* kpasswd */
#define NETIO_UDP_PORT_IGMPV3LITE        465 /* IGMP over UDP for SSM */
#define NETIO_UDP_PORT_DIGITAL_VRC       466 /* digital-vrc */
#define NETIO_UDP_PORT_MYLEX_MAPD        467 /* mylex-mapd */
#define NETIO_UDP_PORT_PHOTURIS          468 /* proturis */
#define NETIO_UDP_PORT_RCP               469 /* Radio Control Protocol */
#define NETIO_UDP_PORT_SCX_PROXY         470 /* scx-proxy */
#define NETIO_UDP_PORT_MONDEX            471 /* Mondex */
#define NETIO_UDP_PORT_LJK_LOGIN         472 /* ljk-login */
#define NETIO_UDP_PORT_HYBRID_POP        473 /* hybrid-pop */
#define NETIO_UDP_PORT_TN_TL_W2          474 /* tn-tl-w2 */
#define NETIO_UDP_PORT_TCPNETHASPSRV     475 /* tcpnethaspsrv */
#define NETIO_UDP_PORT_TN_TL_FD1         476 /* tn-tl-fd1 */
#define NETIO_UDP_PORT_SS7NS             477 /* ss7ns */
#define NETIO_UDP_PORT_SPSC              478 /* spsc */
#define NETIO_UDP_PORT_IAFSERVER         479 /* iafserver */
#define NETIO_UDP_PORT_IAFDBASE          480 /* iafdbase */
#define NETIO_UDP_PORT_PH                481 /* Ph service */
#define NETIO_UDP_PORT_BGS_NSI           482 /* bgs-nsi */
#define NETIO_UDP_PORT_ULPNET            483 /* ulpnet */
#define NETIO_UDP_PORT_INTEGRA_SME       484 /* Integra Software Management Environment */
#define NETIO_UDP_PORT_POWERBURST        485 /* Air Soft Power Burst */
#define NETIO_UDP_PORT_AVIAN             486 /* avian */
#define NETIO_UDP_PORT_SAFT              487 /* saft Simple Asynchronous File Transfer */
#define NETIO_UDP_PORT_GSS_HTTP          488 /* gss-http */
#define NETIO_UDP_PORT_NEST_PROTOCOL     489 /* nest-protocol */
#define NETIO_UDP_PORT_MICOM_PFS         490 /* micom-pfs */
#define NETIO_UDP_PORT_GO_LOGIN          491 /* go-login */
#define NETIO_UDP_PORT_TICF_1            492 /* Transport Independent Convergence for FNA */
#define NETIO_UDP_PORT_TICF_2            493 /* Transport Independent Convergence for FNA */
#define NETIO_UDP_PORT_POV_RAY           494 /* POV-Ray */
#define NETIO_UDP_PORT_INTECOURIER       495 /* intecourier */
#define NETIO_UDP_PORT_PIM_RP_DISC       496 /* PIM-RP-DISC */
#define NETIO_UDP_PORT_RETROSPECT        497 /* Retrospect backup and restore service */
#define NETIO_UDP_PORT_SIAM              498 /* siam */
#define NETIO_UDP_PORT_ISO_ILL           499 /* ISO ILL Protocol */
#define NETIO_UDP_PORT_ISAKMP            500 /* isakmp */
#define NETIO_UDP_PORT_STMF              501 /* STMF */
#define NETIO_UDP_PORT_MBAP              502 /* Modbus Application Protocol */
#define NETIO_UDP_PORT_INTRINSA          503 /* Intrinsa */
#define NETIO_UDP_PORT_CITADEL           504 /* citadel */
#define NETIO_UDP_PORT_MAILBOX_LM        505 /* mailbox-lm */
#define NETIO_UDP_PORT_OHIMSRV           506 /* ohimsrv */
#define NETIO_UDP_PORT_CRS               507 /* crs */
#define NETIO_UDP_PORT_XVTTP             508 /* xvttp */
#define NETIO_UDP_PORT_SNARE             509 /* snare */
#define NETIO_UDP_PORT_FCP               510 /* FirstClass Protocol */
#define NETIO_UDP_PORT_PASSGO            511 /* PassGo */
#define NETIO_UDP_PORT_BIFF              512 /* used by mail system to notify users of new mail received; currently receives messages only from processes on the same machine */
#define NETIO_UDP_PORT_WHO               513 /* maintains data bases showing who's logged in to machines on a local net and the load average of the machine */
#define NETIO_UDP_PORT_PRINTER           515 /* spooler */
#define NETIO_UDP_PORT_VIDEOTEX          516 /* videotex */
#define NETIO_UDP_PORT_TALK              517 /* "like tenex link */
#define NETIO_UDP_PORT_UTIME             519 /* unixtime */
#define NETIO_UDP_PORT_ROUTER            520 /* local routing process (on site); uses variant of Xerox NS routing information protocol - RIP */
#define NETIO_UDP_PORT_RIPNG             521 /* ripng */
#define NETIO_UDP_PORT_ULP               522 /* ULP */
#define NETIO_UDP_PORT_IBM_DB2           523 /* IBM-DB2 */
#define NETIO_UDP_PORT_NCP               524 /* NCP */
#define NETIO_UDP_PORT_TIMED             525 /* timeserver */
#define NETIO_UDP_PORT_TEMPO             526 /* newdate */
#define NETIO_UDP_PORT_STX               527 /* Stock IXChange */
#define NETIO_UDP_PORT_CUSTIX            528 /* Customer IXChange */
#define NETIO_UDP_PORT_IRC_SERV          529 /* IRC-SERV */
#define NETIO_UDP_PORT_COURIER           530 /* rpc */
#define NETIO_UDP_PORT_CONFERENCE        531 /* chat */
#define NETIO_UDP_PORT_NETNEWS           532 /* readnews */
#define NETIO_UDP_PORT_NETWALL           533 /* for emergency broadcasts */
#define NETIO_UDP_PORT_WINDREAM          534 /* windream Admin */
#define NETIO_UDP_PORT_IIOP              535 /* iiop */
#define NETIO_UDP_PORT_OPALIS_RDV        536 /* opalis-rdv */
#define NETIO_UDP_PORT_NMSP              537 /* Networked Media Streaming Protocol */
#define NETIO_UDP_PORT_GDOMAP            538 /* gdomap */
#define NETIO_UDP_PORT_APERTUS_LDP       539 /* Apertus Technologies Load Determination */
#define NETIO_UDP_PORT_UUCP              540 /* uucpd */
#define NETIO_UDP_PORT_UUCP_RLOGIN       541 /* uucp-rlogin */
#define NETIO_UDP_PORT_COMMERCE          542 /* commerce */
#define NETIO_UDP_PORT_KSHELL            544 /* krcmd */
#define NETIO_UDP_PORT_APPLEQTCSRVR      545 /* appleqtcsrvr */
#define NETIO_UDP_PORT_DHCPV6_CLIENT     546 /* DHCPv6 Client */
#define NETIO_UDP_PORT_DHCPV6_SERVER     547 /* DHCPv6 Server */
#define NETIO_UDP_PORT_AFPOVERTCP        548 /* AFP over TCP */
#define NETIO_UDP_PORT_IDFP              549 /* IDFP */
#define NETIO_UDP_PORT_NEW_RWHO          550 /* new-who */
#define NETIO_UDP_PORT_CYBERCASH         551 /* cybercash */
#define NETIO_UDP_PORT_DEVSHR_NTS        552 /* DeviceShare */
#define NETIO_UDP_PORT_PIRP              553 /* pirp */
#define NETIO_UDP_PORT_RTSP              554 /* Real Time Streaming Protocol (RTSP) */
#define NETIO_UDP_PORT_REMOTEFS          556 /* rfs server */
#define NETIO_UDP_PORT_OPENVMS_SYSIPC    557 /* openvms-sysipc */
#define NETIO_UDP_PORT_SDNSKMP           558 /* SDNSKMP */
#define NETIO_UDP_PORT_TEEDTAP           559 /* TEEDTAP */
#define NETIO_UDP_PORT_RMONITOR          560 /* rmonitord */
#define NETIO_UDP_PORT_CHSHELL           562 /* chcmd */
#define NETIO_UDP_PORT_NNTPS             563 /* nntp protocol over TLS/SSL (was snntp) */
#define NETIO_UDP_PORT_9PFS              564 /* plan 9 file service */
#define NETIO_UDP_PORT_WHOAMI            565 /* whoami */
#define NETIO_UDP_PORT_STREETTALK        566 /* streettalk */
#define NETIO_UDP_PORT_BANYAN_RPC        567 /* banyan-rpc */
#define NETIO_UDP_PORT_MS_SHUTTLE        568 /* microsoft shuttle */
#define NETIO_UDP_PORT_MS_ROME           569 /* microsoft rome */
#define NETIO_UDP_PORT_METER             570 /* demon */
#define NETIO_UDP_PORT_UMETER            571 /* udemon */
#define NETIO_UDP_PORT_SONAR             572 /* sonar */
#define NETIO_UDP_PORT_BANYAN_VIP        573 /* banyan-vip */
#define NETIO_UDP_PORT_FTP_AGENT         574 /* FTP Software Agent System */
#define NETIO_UDP_PORT_VEMMI             575 /* VEMMI */
#define NETIO_UDP_PORT_IPCD              576 /* ipcd */
#define NETIO_UDP_PORT_VNAS              577 /* vnas */
#define NETIO_UDP_PORT_IPDD              578 /* ipdd */
#define NETIO_UDP_PORT_DECBSRV           579 /* decbsrv */
#define NETIO_UDP_PORT_SNTP_HEARTBEAT    580 /* SNTP HEARTBEAT */
#define NETIO_UDP_PORT_BDP               581 /* Bundle Discovery Protocol */
#define NETIO_UDP_PORT_SCC_SECURITY      582 /* SCC Security */
#define NETIO_UDP_PORT_PHILIPS_VC        583 /* Philips Video-Conferencing */
#define NETIO_UDP_PORT_KEYSERVER         584 /* Key Server */
#define NETIO_UDP_PORT_PASSWORD_CHG      586 /* Password Change */
#define NETIO_UDP_PORT_SUBMISSION        587 /* Message Submission */
#define NETIO_UDP_PORT_CAL               588 /* CAL */
#define NETIO_UDP_PORT_EYELINK           589 /* EyeLink */
#define NETIO_UDP_PORT_TNS_CML           590 /* TNS CML */
#define NETIO_UDP_PORT_HTTP_ALT          591 /* "FileMaker */
#define NETIO_UDP_PORT_EUDORA_SET        592 /* Eudora Set */
#define NETIO_UDP_PORT_HTTP_RPC_EPMAP    593 /* HTTP RPC Ep Map */
#define NETIO_UDP_PORT_TPIP              594 /* TPIP */
#define NETIO_UDP_PORT_CAB_PROTOCOL      595 /* CAB Protocol */
#define NETIO_UDP_PORT_SMSD              596 /* SMSD */
#define NETIO_UDP_PORT_PTCNAMESERVICE    597 /* PTC Name Service */
#define NETIO_UDP_PORT_SCO_WEBSRVRMG3    598 /* SCO Web Server Manager 3 */
#define NETIO_UDP_PORT_ACP               599 /* Aeolon Core Protocol */
#define NETIO_UDP_PORT_IPCSERVER         600 /* Sun IPC server */
#define NETIO_UDP_PORT_SYSLOG_CONN       601 /* Reliable Syslog Service */
#define NETIO_UDP_PORT_XMLRPC_BEEP       602 /* XML-RPC over BEEP */
#define NETIO_UDP_PORT_IDXP              603 /* IDXP */
#define NETIO_UDP_PORT_TUNNEL            604 /* TUNNEL */
#define NETIO_UDP_PORT_SOAP_BEEP         605 /* SOAP over BEEP */
#define NETIO_UDP_PORT_URM               606 /* Cray Unified Resource Manager */
#define NETIO_UDP_PORT_NQS               607 /* nqs */
#define NETIO_UDP_PORT_SIFT_UFT          608 /* Sender-Initiated/Unsolicited File Transfer */
#define NETIO_UDP_PORT_NPMP_TRAP         609 /* npmp-trap */
#define NETIO_UDP_PORT_NPMP_LOCAL        610 /* npmp-local */
#define NETIO_UDP_PORT_NPMP_GUI          611 /* npmp-gui */
#define NETIO_UDP_PORT_HMMP_IND          612 /* HMMP Indication */
#define NETIO_UDP_PORT_HMMP_OP           613 /* HMMP Operation */
#define NETIO_UDP_PORT_SSHELL            614 /* SSLshell */
#define NETIO_UDP_PORT_SCO_INETMGR       615 /* Internet Configuration Manager */
#define NETIO_UDP_PORT_SCO_SYSMGR        616 /* SCO System Administration Server */
#define NETIO_UDP_PORT_SCO_DTMGR         617 /* SCO Desktop Administration Server */
#define NETIO_UDP_PORT_DEI_ICDA          618 /* DEI-ICDA */
#define NETIO_UDP_PORT_COMPAQ_EVM        619 /* Compaq EVM */
#define NETIO_UDP_PORT_SCO_WEBSRVRMGR    620 /* SCO WebServer Manager */
#define NETIO_UDP_PORT_ESCP_IP           621 /* ESCP */
#define NETIO_UDP_PORT_COLLABORATOR      622 /* Collaborator */
#define NETIO_UDP_PORT_ASF_RMCP          623 /* ASF Remote Management and Control Protocol */
#define NETIO_UDP_PORT_CRYPTOADMIN       624 /* Crypto Admin */
#define NETIO_UDP_PORT_DEC_DLM           625 /* "DEC DLM */
#define NETIO_UDP_PORT_ASIA              626 /* ASIA */
#define NETIO_UDP_PORT_PASSGO_TIVOLI     627 /* PassGo Tivoli */
#define NETIO_UDP_PORT_QMQP              628 /* QMQP */
#define NETIO_UDP_PORT_3COM_AMP3         629 /* 3Com AMP3 */
#define NETIO_UDP_PORT_RDA               630 /* RDA */
#define NETIO_UDP_PORT_IPP               631 /* IPP (Internet Printing Protocol) */
#define NETIO_UDP_PORT_BMPP              632 /* bmpp */
#define NETIO_UDP_PORT_SERVSTAT          633 /* Service Status update (Sterling Software) */
#define NETIO_UDP_PORT_GINAD             634 /* ginad */
#define NETIO_UDP_PORT_RLZDBASE          635 /* RLZ DBase */
#define NETIO_UDP_PORT_LDAPS             636 /* ldap protocol over TLS/SSL (was sldap) */
#define NETIO_UDP_PORT_LANSERVER         637 /* lanserver */
#define NETIO_UDP_PORT_MCNS_SEC          638 /* mcns-sec */
#define NETIO_UDP_PORT_MSDP              639 /* MSDP */
#define NETIO_UDP_PORT_ENTRUST_SPS       640 /* entrust-sps */
#define NETIO_UDP_PORT_REPCMD            641 /* repcmd */
#define NETIO_UDP_PORT_ESRO_EMSDP        642 /* ESRO-EMSDP V1.3 */
#define NETIO_UDP_PORT_SANITY            643 /* SANity */
#define NETIO_UDP_PORT_DWR               644 /* dwr */
#define NETIO_UDP_PORT_PSSC              645 /* PSSC */
#define NETIO_UDP_PORT_LDP               646 /* LDP */
#define NETIO_UDP_PORT_DHCP_FAILOVER     647 /* DHCP Failover */
#define NETIO_UDP_PORT_RRP               648 /* Registry Registrar Protocol (RRP) */
#define NETIO_UDP_PORT_CADVIEW_3D        649 /* Cadview-3d - streaming 3d models over the internet */
#define NETIO_UDP_PORT_OBEX              650 /* OBEX */
#define NETIO_UDP_PORT_IEEE_MMS          651 /* IEEE MMS */
#define NETIO_UDP_PORT_HELLO_PORT        652 /* HELLO_PORT */
#define NETIO_UDP_PORT_REPSCMD           653 /* RepCmd */
#define NETIO_UDP_PORT_AODV              654 /* AODV */
#define NETIO_UDP_PORT_TINC              655 /* TINC */
#define NETIO_UDP_PORT_SPMP              656 /* SPMP */
#define NETIO_UDP_PORT_RMC               657 /* RMC */
#define NETIO_UDP_PORT_TENFOLD           658 /* TenFold */
#define NETIO_UDP_PORT_MAC_SRVR_ADMIN    660 /* MacOS Server Admin */
#define NETIO_UDP_PORT_HAP               661 /* HAP */
#define NETIO_UDP_PORT_PFTP              662 /* PFTP */
#define NETIO_UDP_PORT_PURENOISE         663 /* PureNoise */
#define NETIO_UDP_PORT_ASF_SECURE_RMCP   664 /* ASF Secure Remote Management and Control Protocol */
#define NETIO_UDP_PORT_SUN_DR            665 /* Sun DR */
#define NETIO_UDP_PORT_DOOM              666 /* doom Id Software */
#define NETIO_UDP_PORT_DISCLOSE          667 /* campaign contribution disclosures - SDR Technologies */
#define NETIO_UDP_PORT_MECOMM            668 /* MeComm */
#define NETIO_UDP_PORT_MEREGISTER        669 /* MeRegister */
#define NETIO_UDP_PORT_VACDSM_SWS        670 /* VACDSM-SWS */
#define NETIO_UDP_PORT_VACDSM_APP        671 /* VACDSM-APP */
#define NETIO_UDP_PORT_VPPS_QUA          672 /* VPPS-QUA */
#define NETIO_UDP_PORT_CIMPLEX           673 /* CIMPLEX */
#define NETIO_UDP_PORT_ACAP              674 /* ACAP */
#define NETIO_UDP_PORT_DCTP              675 /* DCTP */
#define NETIO_UDP_PORT_VPPS_VIA          676 /* VPPS Via */
#define NETIO_UDP_PORT_VPP               677 /* Virtual Presence Protocol */
#define NETIO_UDP_PORT_GGF_NCP           678 /* GNU Generation Foundation NCP */
#define NETIO_UDP_PORT_MRM               679 /* MRM */
#define NETIO_UDP_PORT_ENTRUST_AAAS      680 /* entrust-aaas */
#define NETIO_UDP_PORT_ENTRUST_AAMS      681 /* entrust-aams */
#define NETIO_UDP_PORT_XFR               682 /* XFR */
#define NETIO_UDP_PORT_CORBA_IIOP        683 /* CORBA IIOP */
#define NETIO_UDP_PORT_CORBA_IIOP_SSL    684 /* CORBA IIOP SSL */
#define NETIO_UDP_PORT_MDC_PORTMAPPER    685 /* MDC Port Mapper */
#define NETIO_UDP_PORT_HCP_WISMAR        686 /* Hardware Control Protocol Wismar */
#define NETIO_UDP_PORT_ASIPREGISTRY      687 /* asipregistry */
#define NETIO_UDP_PORT_REALM_RUSD        688 /* ApplianceWare managment protocol */
#define NETIO_UDP_PORT_NMAP              689 /* NMAP */
#define NETIO_UDP_PORT_VATP              690 /* Velazquez Application Transfer Protocol */
#define NETIO_UDP_PORT_MSEXCH_ROUTING    691 /* MS Exchange Routing */
#define NETIO_UDP_PORT_HYPERWAVE_ISP     692 /* Hyperwave-ISP */
#define NETIO_UDP_PORT_CONNENDP          693 /* almanid Connection Endpoint */
#define NETIO_UDP_PORT_HA_CLUSTER        694 /* ha-cluster */
#define NETIO_UDP_PORT_IEEE_MMS_SSL      695 /* IEEE-MMS-SSL */
#define NETIO_UDP_PORT_RUSHD             696 /* RUSHD */
#define NETIO_UDP_PORT_UUIDGEN           697 /* UUIDGEN */
#define NETIO_UDP_PORT_OLSR              698 /* OLSR */
#define NETIO_UDP_PORT_ACCESSNETWORK     699 /* Access Network */
#define NETIO_UDP_PORT_EPP               700 /* Extensible Provisioning Protocol */
#define NETIO_UDP_PORT_LMP               701 /* Link Management Protocol (LMP) */
#define NETIO_UDP_PORT_IRIS_BEEP         702 /* IRIS over BEEP */
#define NETIO_UDP_PORT_ELCSD             704 /* errlog copy/server daemon */
#define NETIO_UDP_PORT_AGENTX            705 /* AgentX */
#define NETIO_UDP_PORT_SILC              706 /* SILC */
#define NETIO_UDP_PORT_BORLAND_DSJ       707 /* Borland DSJ */
#define NETIO_UDP_PORT_ENTRUST_KMSH      709 /* Entrust Key Management Service Handler */
#define NETIO_UDP_PORT_ENTRUST_ASH       710 /* Entrust Administration Service Handler */
#define NETIO_UDP_PORT_CISCO_TDP         711 /* Cisco TDP */
#define NETIO_UDP_PORT_TBRPF             712 /* TBRPF */
#define NETIO_UDP_PORT_IRIS_XPC          713 /* IRIS over XPC */
#define NETIO_UDP_PORT_IRIS_XPCS         714 /* IRIS over XPCS */
#define NETIO_UDP_PORT_IRIS_LWZ          715 /* IRIS-LWZ */
#define NETIO_UDP_PORT_PANA              716 /* PANA Messages */
#define NETIO_UDP_PORT_NETVIEWDM1        729 /* IBM NetView DM/6000 Server/Client */
#define NETIO_UDP_PORT_NETVIEWDM2        730 /* IBM NetView DM/6000 send/tcp */
#define NETIO_UDP_PORT_NETVIEWDM3        731 /* IBM NetView DM/6000 receive/tcp */
#define NETIO_UDP_PORT_NETGW             741 /* netGW */
#define NETIO_UDP_PORT_NETRCS            742 /* Network based Rev. Cont. Sys. */
#define NETIO_UDP_PORT_FLEXLM            744 /* Flexible License Manager */
#define NETIO_UDP_PORT_FUJITSU_DEV       747 /* Fujitsu Device Control */
#define NETIO_UDP_PORT_RIS_CM            748 /* Russell Info Sci Calendar Manager */
#define NETIO_UDP_PORT_KERBEROS_ADM      749 /* kerberos administration */
#define NETIO_UDP_PORT_KERBEROS_IV       750 /* kerberos version iv */
#define NETIO_UDP_PORT_TELL              754 /* send */
#define NETIO_UDP_PORT_PHONEBOOK         767 /* phone */
#define NETIO_UDP_PORT_ACMAINT_DBD       774 /* "IANA assigned this well-formed service name as a replacement for ""acmaint_dbd""." */
#define NETIO_UDP_PORT_ACMAINT_TRANSD    775 /* "IANA assigned this well-formed service name as a replacement for ""acmaint_transd""." */
#define NETIO_UDP_PORT_MULTILING_HTTP    777 /* Multiling HTTP */
#define NETIO_UDP_PORT_MDBS_DAEMON       800 /* "IANA assigned this well-formed service name as a replacement for ""mdbs_daemon""." */
#define NETIO_UDP_PORT_MBAP_S            802 /* Modbus Application Protocol Secure */
#define NETIO_UDP_PORT_FCP_UDP           810 /* FCP Datagram */
#define NETIO_UDP_PORT_ITM_MCELL_S       828 /* itm-mcell-s */
#define NETIO_UDP_PORT_PKIX_3_CA_RA      829 /* PKIX-3 CA/RA */
#define NETIO_UDP_PORT_NETCONF_SSH       830 /* NETCONF over SSH */
#define NETIO_UDP_PORT_NETCONF_BEEP      831 /* NETCONF over BEEP */
#define NETIO_UDP_PORT_NETCONFSOAPHTTP   832 /* NETCONF for SOAP over HTTPS */
#define NETIO_UDP_PORT_NETCONFSOAPBEEP   833 /* NETCONF for SOAP over BEEP */
#define NETIO_UDP_PORT_DHCP_FAILOVER2    847 /* dhcp-failover 2 */
#define NETIO_UDP_PORT_GDOI              848 /* GDOI */
#define NETIO_UDP_PORT_ISCSI             860 /* iSCSI */
#define NETIO_UDP_PORT_OWAMP_CONTROL     861 /* OWAMP-Control */
#define NETIO_UDP_PORT_TWAMP_CONTROL     862 /* Two-way Active Measurement Protocol (TWAMP) Control */
#define NETIO_UDP_PORT_RSYNC             873 /* rsync */
#define NETIO_UDP_PORT_ICLCNET_LOCATE    886 /* ICL coNETion locate server */
#define NETIO_UDP_PORT_ICLCNET_SVINFO    887 /* "ICL coNETion server info */
#define NETIO_UDP_PORT_ACCESSBUILDER     888 /* AccessBuilder */
#define NETIO_UDP_PORT_OMGINITIALREFS    900 /* OMG Initial Refs */
#define NETIO_UDP_PORT_SMPNAMERES        901 /* SMPNAMERES */
#define NETIO_UDP_PORT_IDEAFARM_DOOR     902 /* self documenting Door: send 0x00 for info */
#define NETIO_UDP_PORT_IDEAFARM_PANIC    903 /* self documenting Panic Door: send 0x00 for info */
#define NETIO_UDP_PORT_KINK              910 /* Kerberized Internet Negotiation of Keys (KINK) */
#define NETIO_UDP_PORT_XACT_BACKUP       911 /* xact-backup */
#define NETIO_UDP_PORT_APEX_MESH         912 /* APEX relay-relay service */
#define NETIO_UDP_PORT_APEX_EDGE         913 /* APEX endpoint-relay service */
#define NETIO_UDP_PORT_FTPS_DATA         989 /* "ftp protocol */
#define NETIO_UDP_PORT_FTPS              990 /* "ftp protocol */
#define NETIO_UDP_PORT_NAS               991 /* Netnews Administration System */
#define NETIO_UDP_PORT_TELNETS           992 /* telnet protocol over TLS/SSL */
#define NETIO_UDP_PORT_IMAPS             993 /* imap4 protocol over TLS/SSL */
#define NETIO_UDP_PORT_POP3S             995 /* pop3 protocol over TLS/SSL (was spop3) */
#define NETIO_UDP_PORT_VSINET            996 /* vsinet */
#define NETIO_UDP_PORT_APPLIX            999 /* Applix ac */
#define NETIO_UDP_PORT_SURF              1010 /* surf */
#define NETIO_UDP_PORT_EXP1              1021 /* RFC3692-style Experiment 1 */
#define NETIO_UDP_PORT_EXP2              1022 /* RFC3692-style Experiment 2 */
#define NETIO_UDP_PORT_BLACKJACK         1025 /* network blackjack */
#define NETIO_UDP_PORT_CAP               1026 /* Calendar Access Protocol */
#define NETIO_UDP_PORT_6A44              1027 /* IPv6 Behind NAT44 CPEs */
#define NETIO_UDP_PORT_SOLID_MUX         1029 /* Solid Mux Server */
#define NETIO_UDP_PORT_NETINFO_LOCAL     1033 /* local netinfo port */
#define NETIO_UDP_PORT_ACTIVESYNC        1034 /* ActiveSync Notifications */
#define NETIO_UDP_PORT_MXXRLOGIN         1035 /* MX-XR RPC */
#define NETIO_UDP_PORT_NSSTP             1036 /* Nebula Secure Segment Transfer Protocol */
#define NETIO_UDP_PORT_AMS               1037 /* AMS */
#define NETIO_UDP_PORT_MTQP              1038 /* Message Tracking Query Protocol */
#define NETIO_UDP_PORT_SBL               1039 /* Streamlined Blackhole */
#define NETIO_UDP_PORT_NETARX            1040 /* Netarx Netcare */
#define NETIO_UDP_PORT_DANF_AK2          1041 /* AK2 Product */
#define NETIO_UDP_PORT_AFROG             1042 /* Subnet Roaming */
#define NETIO_UDP_PORT_BOINC_CLIENT      1043 /* BOINC Client Control */
#define NETIO_UDP_PORT_DCUTILITY         1044 /* Dev Consortium Utility */
#define NETIO_UDP_PORT_FPITP             1045 /* Fingerprint Image Transfer Protocol */
#define NETIO_UDP_PORT_WFREMOTERTM       1046 /* WebFilter Remote Monitor */
#define NETIO_UDP_PORT_NEOD1             1047 /* Sun's NEO Object Request Broker */
#define NETIO_UDP_PORT_NEOD2             1048 /* Sun's NEO Object Request Broker */
#define NETIO_UDP_PORT_TD_POSTMAN        1049 /* Tobit David Postman VPMN */
#define NETIO_UDP_PORT_CMA               1050 /* CORBA Management Agent */
#define NETIO_UDP_PORT_OPTIMA_VNET       1051 /* Optima VNET */
#define NETIO_UDP_PORT_DDT               1052 /* Dynamic DNS Tools */
#define NETIO_UDP_PORT_REMOTE_AS         1053 /* Remote Assistant (RA) */
#define NETIO_UDP_PORT_BRVREAD           1054 /* BRVREAD */
#define NETIO_UDP_PORT_ANSYSLMD          1055 /* ANSYS - License Manager */
#define NETIO_UDP_PORT_VFO               1056 /* VFO */
#define NETIO_UDP_PORT_STARTRON          1057 /* STARTRON */
#define NETIO_UDP_PORT_NIM               1058 /* nim */
#define NETIO_UDP_PORT_NIMREG            1059 /* nimreg */
#define NETIO_UDP_PORT_POLESTAR          1060 /* POLESTAR */
#define NETIO_UDP_PORT_KIOSK             1061 /* KIOSK */
#define NETIO_UDP_PORT_VERACITY          1062 /* Veracity */
#define NETIO_UDP_PORT_KYOCERANETDEV     1063 /* KyoceraNetDev */
#define NETIO_UDP_PORT_JSTEL             1064 /* JSTEL */
#define NETIO_UDP_PORT_SYSCOMLAN         1065 /* SYSCOMLAN */
#define NETIO_UDP_PORT_FPO_FNS           1066 /* FPO-FNS */
#define NETIO_UDP_PORT_INSTL_BOOTS       1067 /* "Installation Bootstrap Proto. Serv. */
#define NETIO_UDP_PORT_INSTL_BOOTC       1068 /* "Installation Bootstrap Proto. Cli. */
#define NETIO_UDP_PORT_COGNEX_INSIGHT    1069 /* COGNEX-INSIGHT */
#define NETIO_UDP_PORT_GMRUPDATESERV     1070 /* GMRUpdateSERV */
#define NETIO_UDP_PORT_BSQUARE_VOIP      1071 /* BSQUARE-VOIP */
#define NETIO_UDP_PORT_CARDAX            1072 /* CARDAX */
#define NETIO_UDP_PORT_BRIDGECONTROL     1073 /* Bridge Control */
#define NETIO_UDP_PORT_WARMSPOTMGMT      1074 /* Warmspot Management Protocol */
#define NETIO_UDP_PORT_RDRMSHC           1075 /* RDRMSHC */
#define NETIO_UDP_PORT_DAB_STI_C         1076 /* DAB STI-C */
#define NETIO_UDP_PORT_IMGAMES           1077 /* IMGames */
#define NETIO_UDP_PORT_AVOCENT_PROXY     1078 /* Avocent Proxy Protocol */
#define NETIO_UDP_PORT_ASPROVATALK       1079 /* ASPROVATalk */
#define NETIO_UDP_PORT_SOCKS             1080 /* Socks */
#define NETIO_UDP_PORT_PVUNIWIEN         1081 /* PVUNIWIEN */
#define NETIO_UDP_PORT_AMT_ESD_PROT      1082 /* AMT-ESD-PROT */
#define NETIO_UDP_PORT_ANSOFT_LM_1       1083 /* Anasoft License Manager */
#define NETIO_UDP_PORT_ANSOFT_LM_2       1084 /* Anasoft License Manager */
#define NETIO_UDP_PORT_WEBOBJECTS        1085 /* Web Objects */
#define NETIO_UDP_PORT_CPLSCRAMBLER_LG   1086 /* CPL Scrambler Logging */
#define NETIO_UDP_PORT_CPLSCRAMBLER_IN   1087 /* CPL Scrambler Internal */
#define NETIO_UDP_PORT_CPLSCRAMBLER_AL   1088 /* CPL Scrambler Alarm Log */
#define NETIO_UDP_PORT_FF_ANNUNC         1089 /* FF Annunciation */
#define NETIO_UDP_PORT_FF_FMS            1090 /* FF Fieldbus Message Specification */
#define NETIO_UDP_PORT_FF_SM             1091 /* FF System Management */
#define NETIO_UDP_PORT_OBRPD             1092 /* Open Business Reporting Protocol */
#define NETIO_UDP_PORT_PROOFD            1093 /* PROOFD */
#define NETIO_UDP_PORT_ROOTD             1094 /* ROOTD */
#define NETIO_UDP_PORT_NICELINK          1095 /* NICELink */
#define NETIO_UDP_PORT_CNRPROTOCOL       1096 /* Common Name Resolution Protocol */
#define NETIO_UDP_PORT_SUNCLUSTERMGR     1097 /* Sun Cluster Manager */
#define NETIO_UDP_PORT_RMIACTIVATION     1098 /* RMI Activation */
#define NETIO_UDP_PORT_RMIREGISTRY       1099 /* RMI Registry */
#define NETIO_UDP_PORT_MCTP              1100 /* MCTP */
#define NETIO_UDP_PORT_PT2_DISCOVER      1101 /* PT2-DISCOVER */
#define NETIO_UDP_PORT_ADOBESERVER_1     1102 /* ADOBE SERVER 1 */
#define NETIO_UDP_PORT_ADOBESERVER_2     1103 /* ADOBE SERVER 2 */
#define NETIO_UDP_PORT_XRL               1104 /* XRL */
#define NETIO_UDP_PORT_FTRANHC           1105 /* FTRANHC */
#define NETIO_UDP_PORT_ISOIPSIGPORT_1    1106 /* ISOIPSIGPORT-1 */
#define NETIO_UDP_PORT_ISOIPSIGPORT_2    1107 /* ISOIPSIGPORT-2 */
#define NETIO_UDP_PORT_RATIO_ADP         1108 /* ratio-adp */
#define NETIO_UDP_PORT_NFSD_KEEPALIVE    1110 /* Client status info */
#define NETIO_UDP_PORT_LMSOCIALSERVER    1111 /* LM Social Server */
#define NETIO_UDP_PORT_ICP               1112 /* Intelligent Communication Protocol */
#define NETIO_UDP_PORT_LTP_DEEPSPACE     1113 /* Licklider Transmission Protocol */
#define NETIO_UDP_PORT_MINI_SQL          1114 /* Mini SQL */
#define NETIO_UDP_PORT_ARDUS_TRNS        1115 /* ARDUS Transfer */
#define NETIO_UDP_PORT_ARDUS_CNTL        1116 /* ARDUS Control */
#define NETIO_UDP_PORT_ARDUS_MTRNS       1117 /* ARDUS Multicast Transfer */
#define NETIO_UDP_PORT_SACRED            1118 /* SACRED */
#define NETIO_UDP_PORT_BNETGAME          1119 /* Battle.net Chat/Game Protocol */
#define NETIO_UDP_PORT_BNETFILE          1120 /* Battle.net File Transfer Protocol */
#define NETIO_UDP_PORT_RMPP              1121 /* Datalode RMPP */
#define NETIO_UDP_PORT_AVAILANT_MGR      1122 /* availant-mgr */
#define NETIO_UDP_PORT_MURRAY            1123 /* Murray */
#define NETIO_UDP_PORT_HPVMMCONTROL      1124 /* HP VMM Control */
#define NETIO_UDP_PORT_HPVMMAGENT        1125 /* HP VMM Agent */
#define NETIO_UDP_PORT_HPVMMDATA         1126 /* HP VMM Agent */
#define NETIO_UDP_PORT_KWDB_COMMN        1127 /* KWDB Remote Communication */
#define NETIO_UDP_PORT_SAPHOSTCTRL       1128 /* SAPHostControl over SOAP/HTTP */
#define NETIO_UDP_PORT_SAPHOSTCTRLS      1129 /* SAPHostControl over SOAP/HTTPS */
#define NETIO_UDP_PORT_CASP              1130 /* CAC App Service Protocol */
#define NETIO_UDP_PORT_CASPSSL           1131 /* CAC App Service Protocol Encripted */
#define NETIO_UDP_PORT_KVM_VIA_IP        1132 /* KVM-via-IP Management Service */
#define NETIO_UDP_PORT_DFN               1133 /* Data Flow Network */
#define NETIO_UDP_PORT_APLX              1134 /* MicroAPL APLX */
#define NETIO_UDP_PORT_OMNIVISION        1135 /* OmniVision Communication Service */
#define NETIO_UDP_PORT_HHB_GATEWAY       1136 /* HHB Gateway Control */
#define NETIO_UDP_PORT_TRIM              1137 /* TRIM Workgroup Service */
#define NETIO_UDP_PORT_ENCRYPTED_ADMIN   1138 /* "encrypted admin requests */
#define NETIO_UDP_PORT_EVM               1139 /* Enterprise Virtual Manager */
#define NETIO_UDP_PORT_AUTONOC           1140 /* AutoNOC Network Operations Protocol */
#define NETIO_UDP_PORT_MXOMSS            1141 /* User Message Service */
#define NETIO_UDP_PORT_EDTOOLS           1142 /* User Discovery Service */
#define NETIO_UDP_PORT_IMYX              1143 /* Infomatryx Exchange */
#define NETIO_UDP_PORT_FUSCRIPT          1144 /* Fusion Script */
#define NETIO_UDP_PORT_X9_ICUE           1145 /* X9 iCue Show Control */
#define NETIO_UDP_PORT_AUDIT_TRANSFER    1146 /* audit transfer */
#define NETIO_UDP_PORT_CAPIOVERLAN       1147 /* CAPIoverLAN */
#define NETIO_UDP_PORT_ELFIQ_REPL        1148 /* Elfiq Replication Service */
#define NETIO_UDP_PORT_BVTSONAR          1149 /* BlueView Sonar Service */
#define NETIO_UDP_PORT_BLAZE             1150 /* Blaze File Server */
#define NETIO_UDP_PORT_UNIZENSUS         1151 /* Unizensus Login Server */
#define NETIO_UDP_PORT_WINPOPLANMESS     1152 /* Winpopup LAN Messenger */
#define NETIO_UDP_PORT_C1222_ACSE        1153 /* ANSI C12.22 Port */
#define NETIO_UDP_PORT_RESACOMMUNITY     1154 /* Community Service */
#define NETIO_UDP_PORT_NFA               1155 /* Network File Access */
#define NETIO_UDP_PORT_IASCONTROL_OMS    1156 /* iasControl OMS */
#define NETIO_UDP_PORT_IASCONTROL        1157 /* Oracle iASControl */
#define NETIO_UDP_PORT_DBCONTROL_OMS     1158 /* dbControl OMS */
#define NETIO_UDP_PORT_ORACLE_OMS        1159 /* Oracle OMS */
#define NETIO_UDP_PORT_OLSV              1160 /* DB Lite Mult-User Server */
#define NETIO_UDP_PORT_HEALTH_POLLING    1161 /* Health Polling */
#define NETIO_UDP_PORT_HEALTH_TRAP       1162 /* Health Trap */
#define NETIO_UDP_PORT_SDDP              1163 /* SmartDialer Data Protocol */
#define NETIO_UDP_PORT_QSM_PROXY         1164 /* QSM Proxy Service */
#define NETIO_UDP_PORT_QSM_GUI           1165 /* QSM GUI Service */
#define NETIO_UDP_PORT_QSM_REMOTE        1166 /* QSM RemoteExec */
#define NETIO_UDP_PORT_CISCO_IPSLA       1167 /* Cisco IP SLAs Control Protocol */
#define NETIO_UDP_PORT_VCHAT             1168 /* VChat Conference Service */
#define NETIO_UDP_PORT_TRIPWIRE          1169 /* TRIPWIRE */
#define NETIO_UDP_PORT_ATC_LM            1170 /* AT+C License Manager */
#define NETIO_UDP_PORT_ATC_APPSERVER     1171 /* AT+C FmiApplicationServer */
#define NETIO_UDP_PORT_DNAP              1172 /* DNA Protocol */
#define NETIO_UDP_PORT_D_CINEMA_RRP      1173 /* D-Cinema Request-Response */
#define NETIO_UDP_PORT_FNET_REMOTE_UI    1174 /* FlashNet Remote Admin */
#define NETIO_UDP_PORT_DOSSIER           1175 /* Dossier Server */
#define NETIO_UDP_PORT_INDIGO_SERVER     1176 /* Indigo Home Server */
#define NETIO_UDP_PORT_DKMESSENGER       1177 /* DKMessenger Protocol */
#define NETIO_UDP_PORT_SGI_STORMAN       1178 /* SGI Storage Manager */
#define NETIO_UDP_PORT_B2N               1179 /* Backup To Neighbor */
#define NETIO_UDP_PORT_MC_CLIENT         1180 /* Millicent Client Proxy */
#define NETIO_UDP_PORT_3COMNETMAN        1181 /* 3Com Net Management */
#define NETIO_UDP_PORT_ACCELENET_DATA    1182 /* AcceleNet Data */
#define NETIO_UDP_PORT_LLSURFUP_HTTP     1183 /* LL Surfup HTTP */
#define NETIO_UDP_PORT_LLSURFUP_HTTPS    1184 /* LL Surfup HTTPS */
#define NETIO_UDP_PORT_CATCHPOLE         1185 /* Catchpole port */
#define NETIO_UDP_PORT_MYSQL_CLUSTER     1186 /* MySQL Cluster Manager */
#define NETIO_UDP_PORT_ALIAS             1187 /* Alias Service */
#define NETIO_UDP_PORT_HP_WEBADMIN       1188 /* HP Web Admin */
#define NETIO_UDP_PORT_UNET              1189 /* Unet Connection */
#define NETIO_UDP_PORT_COMMLINX_AVL      1190 /* CommLinx GPS / AVL System */
#define NETIO_UDP_PORT_GPFS              1191 /* General Parallel File System */
#define NETIO_UDP_PORT_CAIDS_SENSOR      1192 /* caids sensors channel */
#define NETIO_UDP_PORT_FIVEACROSS        1193 /* Five Across Server */
#define NETIO_UDP_PORT_OPENVPN           1194 /* OpenVPN */
#define NETIO_UDP_PORT_RSF_1             1195 /* RSF-1 clustering */
#define NETIO_UDP_PORT_NETMAGIC          1196 /* Network Magic */
#define NETIO_UDP_PORT_CARRIUS_RSHELL    1197 /* Carrius Remote Access */
#define NETIO_UDP_PORT_CAJO_DISCOVERY    1198 /* cajo reference discovery */
#define NETIO_UDP_PORT_DMIDI             1199 /* DMIDI */
#define NETIO_UDP_PORT_SCOL              1200 /* SCOL */
#define NETIO_UDP_PORT_NUCLEUS_SAND      1201 /* Nucleus Sand Database Server */
#define NETIO_UDP_PORT_CAICCIPC          1202 /* caiccipc */
#define NETIO_UDP_PORT_SSSLIC_MGR        1203 /* License Validation */
#define NETIO_UDP_PORT_SSSLOG_MGR        1204 /* Log Request Listener */
#define NETIO_UDP_PORT_ACCORD_MGC        1205 /* Accord-MGC */
#define NETIO_UDP_PORT_ANTHONY_DATA      1206 /* Anthony Data */
#define NETIO_UDP_PORT_METASAGE          1207 /* MetaSage */
#define NETIO_UDP_PORT_SEAGULL_AIS       1208 /* SEAGULL AIS */
#define NETIO_UDP_PORT_IPCD3             1209 /* IPCD3 */
#define NETIO_UDP_PORT_EOSS              1210 /* EOSS */
#define NETIO_UDP_PORT_GROOVE_DPP        1211 /* Groove DPP */
#define NETIO_UDP_PORT_LUPA              1212 /* lupa */
#define NETIO_UDP_PORT_MPC_LIFENET       1213 /* Medtronic/Physio-Control LIFENET */
#define NETIO_UDP_PORT_KAZAA             1214 /* KAZAA */
#define NETIO_UDP_PORT_SCANSTAT_1        1215 /* scanSTAT 1.0 */
#define NETIO_UDP_PORT_ETEBAC5           1216 /* ETEBAC 5 */
#define NETIO_UDP_PORT_HPSS_NDAPI        1217 /* HPSS NonDCE Gateway */
#define NETIO_UDP_PORT_AEROFLIGHT_ADS    1218 /* AeroFlight-ADs */
#define NETIO_UDP_PORT_AEROFLIGHT_RET    1219 /* AeroFlight-Ret */
#define NETIO_UDP_PORT_QT_SERVERADMIN    1220 /* QT SERVER ADMIN */
#define NETIO_UDP_PORT_SWEETWARE_APPS    1221 /* SweetWARE Apps */
#define NETIO_UDP_PORT_NERV              1222 /* SNI R&D network */
#define NETIO_UDP_PORT_TGP               1223 /* TrulyGlobal Protocol */
#define NETIO_UDP_PORT_VPNZ              1224 /* VPNz */
#define NETIO_UDP_PORT_SLINKYSEARCH      1225 /* SLINKYSEARCH */
#define NETIO_UDP_PORT_STGXFWS           1226 /* STGXFWS */
#define NETIO_UDP_PORT_DNS2GO            1227 /* DNS2Go */
#define NETIO_UDP_PORT_FLORENCE          1228 /* FLORENCE */
#define NETIO_UDP_PORT_ZENTED            1229 /* ZENworks Tiered Electronic Distribution */
#define NETIO_UDP_PORT_PERISCOPE         1230 /* Periscope */
#define NETIO_UDP_PORT_MENANDMICE_LPM    1231 /* menandmice-lpm */
#define NETIO_UDP_PORT_FIRST_DEFENSE     1232 /* Remote systems monitoring */
#define NETIO_UDP_PORT_UNIV_APPSERVER    1233 /* Universal App Server */
#define NETIO_UDP_PORT_SEARCH_AGENT      1234 /* Infoseek Search Agent */
#define NETIO_UDP_PORT_MOSAICSYSSVC1     1235 /* mosaicsyssvc1 */
#define NETIO_UDP_PORT_BVCONTROL         1236 /* bvcontrol */
#define NETIO_UDP_PORT_TSDOS390          1237 /* tsdos390 */
#define NETIO_UDP_PORT_HACL_QS           1238 /* hacl-qs */
#define NETIO_UDP_PORT_NMSD              1239 /* NMSD */
#define NETIO_UDP_PORT_INSTANTIA         1240 /* Instantia */
#define NETIO_UDP_PORT_NESSUS            1241 /* nessus */
#define NETIO_UDP_PORT_NMASOVERIP        1242 /* NMAS over IP */
#define NETIO_UDP_PORT_SERIALGATEWAY     1243 /* SerialGateway */
#define NETIO_UDP_PORT_ISBCONFERENCE1    1244 /* isbconference1 */
#define NETIO_UDP_PORT_ISBCONFERENCE2    1245 /* isbconference2 */
#define NETIO_UDP_PORT_PAYROUTER         1246 /* payrouter */
#define NETIO_UDP_PORT_VISIONPYRAMID     1247 /* VisionPyramid */
#define NETIO_UDP_PORT_HERMES            1248 /* hermes */
#define NETIO_UDP_PORT_MESAVISTACO       1249 /* Mesa Vista Co */
#define NETIO_UDP_PORT_SWLDY_SIAS        1250 /* swldy-sias */
#define NETIO_UDP_PORT_SERVERGRAPH       1251 /* servergraph */
#define NETIO_UDP_PORT_BSPNE_PCC         1252 /* bspne-pcc */
#define NETIO_UDP_PORT_Q55_PCC           1253 /* q55-pcc */
#define NETIO_UDP_PORT_DE_NOC            1254 /* de-noc */
#define NETIO_UDP_PORT_DE_CACHE_QUERY    1255 /* de-cache-query */
#define NETIO_UDP_PORT_DE_SERVER         1256 /* de-server */
#define NETIO_UDP_PORT_SHOCKWAVE2        1257 /* Shockwave 2 */
#define NETIO_UDP_PORT_OPENNL            1258 /* Open Network Library */
#define NETIO_UDP_PORT_OPENNL_VOICE      1259 /* Open Network Library Voice */
#define NETIO_UDP_PORT_IBM_SSD           1260 /* ibm-ssd */
#define NETIO_UDP_PORT_MPSHRSV           1261 /* mpshrsv */
#define NETIO_UDP_PORT_QNTS_ORB          1262 /* QNTS-ORB */
#define NETIO_UDP_PORT_DKA               1263 /* dka */
#define NETIO_UDP_PORT_PRAT              1264 /* PRAT */
#define NETIO_UDP_PORT_DSSIAPI           1265 /* DSSIAPI */
#define NETIO_UDP_PORT_DELLPWRAPPKS      1266 /* DELLPWRAPPKS */
#define NETIO_UDP_PORT_EPC               1267 /* eTrust Policy Compliance */
#define NETIO_UDP_PORT_PROPEL_MSGSYS     1268 /* PROPEL-MSGSYS */
#define NETIO_UDP_PORT_WATILAPP          1269 /* WATiLaPP */
#define NETIO_UDP_PORT_OPSMGR            1270 /* Microsoft Operations Manager */
#define NETIO_UDP_PORT_EXCW              1271 /* eXcW */
#define NETIO_UDP_PORT_CSPMLOCKMGR       1272 /* CSPMLockMgr */
#define NETIO_UDP_PORT_EMC_GATEWAY       1273 /* EMC-Gateway */
#define NETIO_UDP_PORT_T1DISTPROC        1274 /* t1distproc */
#define NETIO_UDP_PORT_IVCOLLECTOR       1275 /* ivcollector */
#define NETIO_UDP_PORT_MIVA_MQS          1277 /* mqs */
#define NETIO_UDP_PORT_DELLWEBADMIN_1    1278 /* Dell Web Admin 1 */
#define NETIO_UDP_PORT_DELLWEBADMIN_2    1279 /* Dell Web Admin 2 */
#define NETIO_UDP_PORT_PICTROGRAPHY      1280 /* Pictrography */
#define NETIO_UDP_PORT_HEALTHD           1281 /* healthd */
#define NETIO_UDP_PORT_EMPERION          1282 /* Emperion */
#define NETIO_UDP_PORT_PRODUCTINFO       1283 /* Product Information */
#define NETIO_UDP_PORT_IEE_QFX           1284 /* IEE-QFX */
#define NETIO_UDP_PORT_NEOIFACE          1285 /* neoiface */
#define NETIO_UDP_PORT_NETUITIVE         1286 /* netuitive */
#define NETIO_UDP_PORT_ROUTEMATCH        1287 /* RouteMatch Com */
#define NETIO_UDP_PORT_NAVBUDDY          1288 /* NavBuddy */
#define NETIO_UDP_PORT_JWALKSERVER       1289 /* JWalkServer */
#define NETIO_UDP_PORT_WINJASERVER       1290 /* WinJaServer */
#define NETIO_UDP_PORT_SEAGULLLMS        1291 /* SEAGULLLMS */
#define NETIO_UDP_PORT_DSDN              1292 /* dsdn */
#define NETIO_UDP_PORT_PKT_KRB_IPSEC     1293 /* PKT-KRB-IPSec */
#define NETIO_UDP_PORT_CMMDRIVER         1294 /* CMMdriver */
#define NETIO_UDP_PORT_EHTP              1295 /* End-by-Hop Transmission Protocol */
#define NETIO_UDP_PORT_DPROXY            1296 /* dproxy */
#define NETIO_UDP_PORT_SDPROXY           1297 /* sdproxy */
#define NETIO_UDP_PORT_LPCP              1298 /* lpcp */
#define NETIO_UDP_PORT_HP_SCI            1299 /* hp-sci */
#define NETIO_UDP_PORT_H323HOSTCALLSC    1300 /* H.323 Secure Call Control Signalling */
#define NETIO_UDP_PORT_CI3_SOFTWARE_1    1301 /* CI3-Software-1 */
#define NETIO_UDP_PORT_CI3_SOFTWARE_2    1302 /* CI3-Software-2 */
#define NETIO_UDP_PORT_SFTSRV            1303 /* sftsrv */
#define NETIO_UDP_PORT_BOOMERANG         1304 /* Boomerang */
#define NETIO_UDP_PORT_PE_MIKE           1305 /* pe-mike */
#define NETIO_UDP_PORT_RE_CONN_PROTO     1306 /* RE-Conn-Proto */
#define NETIO_UDP_PORT_PACMAND           1307 /* Pacmand */
#define NETIO_UDP_PORT_ODSI              1308 /* Optical Domain Service Interconnect (ODSI) */
#define NETIO_UDP_PORT_JTAG_SERVER       1309 /* JTAG server */
#define NETIO_UDP_PORT_HUSKY             1310 /* Husky */
#define NETIO_UDP_PORT_RXMON             1311 /* RxMon */
#define NETIO_UDP_PORT_STI_ENVISION      1312 /* STI Envision */
#define NETIO_UDP_PORT_BMC_PATROLDB      1313 /* "BMC_PATROLDB */
#define NETIO_UDP_PORT_PDPS              1314 /* Photoscript Distributed Printing System */
#define NETIO_UDP_PORT_ELS               1315 /* "E.L.S. */
#define NETIO_UDP_PORT_EXBIT_ESCP        1316 /* Exbit-ESCP */
#define NETIO_UDP_PORT_VRTS_IPCSERVER    1317 /* vrts-ipcserver */
#define NETIO_UDP_PORT_KRB5GATEKEEPER    1318 /* krb5gatekeeper */
#define NETIO_UDP_PORT_AMX_ICSP          1319 /* AMX-ICSP */
#define NETIO_UDP_PORT_AMX_AXBNET        1320 /* AMX-AXBNET */
#define NETIO_UDP_PORT_PIP2              1321 /* PIP */
#define NETIO_UDP_PORT_NOVATION          1322 /* Novation */
#define NETIO_UDP_PORT_BRCD              1323 /* brcd */
#define NETIO_UDP_PORT_DELTA_MCP         1324 /* delta-mcp */
#define NETIO_UDP_PORT_DX_INSTRUMENT     1325 /* DX-Instrument */
#define NETIO_UDP_PORT_WIMSIC            1326 /* WIMSIC */
#define NETIO_UDP_PORT_ULTREX            1327 /* Ultrex */
#define NETIO_UDP_PORT_EWALL             1328 /* EWALL */
#define NETIO_UDP_PORT_NETDB_EXPORT      1329 /* netdb-export */
#define NETIO_UDP_PORT_STREETPERFECT     1330 /* StreetPerfect */
#define NETIO_UDP_PORT_INTERSAN          1331 /* intersan */
#define NETIO_UDP_PORT_PCIA_RXP_B        1332 /* PCIA RXP-B */
#define NETIO_UDP_PORT_PASSWRD_POLICY    1333 /* Password Policy */
#define NETIO_UDP_PORT_WRITESRV          1334 /* writesrv */
#define NETIO_UDP_PORT_DIGITAL_NOTARY    1335 /* Digital Notary Protocol */
#define NETIO_UDP_PORT_ISCHAT            1336 /* Instant Service Chat */
#define NETIO_UDP_PORT_MENANDMICE_DNS    1337 /* menandmice DNS */
#define NETIO_UDP_PORT_WMC_LOG_SVC       1338 /* WMC-log-svr */
#define NETIO_UDP_PORT_KJTSITESERVER     1339 /* kjtsiteserver */
#define NETIO_UDP_PORT_NAAP              1340 /* NAAP */
#define NETIO_UDP_PORT_QUBES             1341 /* QuBES */
#define NETIO_UDP_PORT_ESBROKER          1342 /* ESBroker */
#define NETIO_UDP_PORT_RE101             1343 /* re101 */
#define NETIO_UDP_PORT_ICAP              1344 /* ICAP */
#define NETIO_UDP_PORT_VPJP              1345 /* VPJP */
#define NETIO_UDP_PORT_ALTA_ANA_LM       1346 /* Alta Analytics License Manager */
#define NETIO_UDP_PORT_BBN_MMC           1347 /* multi media conferencing */
#define NETIO_UDP_PORT_BBN_MMX           1348 /* multi media conferencing */
#define NETIO_UDP_PORT_SBOOK             1349 /* Registration Network Protocol */
#define NETIO_UDP_PORT_EDITBENCH         1350 /* Registration Network Protocol */
#define NETIO_UDP_PORT_EQUATIONBUILDER   1351 /* Digital Tool Works (MIT) */
#define NETIO_UDP_PORT_LOTUSNOTE         1352 /* Lotus Note */
#define NETIO_UDP_PORT_RELIEF            1353 /* Relief Consulting */
#define NETIO_UDP_PORT_XSIP_NETWORK      1354 /* Five Across XSIP Network */
#define NETIO_UDP_PORT_INTUITIVE_EDGE    1355 /* Intuitive Edge */
#define NETIO_UDP_PORT_CUILLAMARTIN      1356 /* CuillaMartin Company */
#define NETIO_UDP_PORT_PEGBOARD          1357 /* Electronic PegBoard */
#define NETIO_UDP_PORT_CONNLCLI          1358 /* CONNLCLI */
#define NETIO_UDP_PORT_FTSRV             1359 /* FTSRV */
#define NETIO_UDP_PORT_MIMER             1360 /* MIMER */
#define NETIO_UDP_PORT_LINX              1361 /* LinX */
#define NETIO_UDP_PORT_TIMEFLIES         1362 /* TimeFlies */
#define NETIO_UDP_PORT_NDM_REQUESTER     1363 /* Network DataMover Requester */
#define NETIO_UDP_PORT_NDM_SERVER        1364 /* Network DataMover Server */
#define NETIO_UDP_PORT_ADAPT_SNA         1365 /* Network Software Associates */
#define NETIO_UDP_PORT_NETWARE_CSP       1366 /* Novell NetWare Comm Service Platform */
#define NETIO_UDP_PORT_DCS               1367 /* DCS */
#define NETIO_UDP_PORT_SCREENCAST        1368 /* ScreenCast */
#define NETIO_UDP_PORT_GV_US             1369 /* GlobalView to Unix Shell */
#define NETIO_UDP_PORT_US_GV             1370 /* Unix Shell to GlobalView */
#define NETIO_UDP_PORT_FC_CLI            1371 /* Fujitsu Config Protocol */
#define NETIO_UDP_PORT_FC_SER            1372 /* Fujitsu Config Protocol */
#define NETIO_UDP_PORT_CHROMAGRAFX       1373 /* Chromagrafx */
#define NETIO_UDP_PORT_MOLLY             1374 /* EPI Software Systems */
#define NETIO_UDP_PORT_BYTEX             1375 /* Bytex */
#define NETIO_UDP_PORT_IBM_PPS           1376 /* IBM Person to Person Software */
#define NETIO_UDP_PORT_CICHLID           1377 /* Cichlid License Manager */
#define NETIO_UDP_PORT_ELAN              1378 /* Elan License Manager */
#define NETIO_UDP_PORT_DBREPORTER        1379 /* Integrity Solutions */
#define NETIO_UDP_PORT_TELESIS_LICMAN    1380 /* Telesis Network License Manager */
#define NETIO_UDP_PORT_APPLE_LICMAN      1381 /* Apple Network License Manager */
#define NETIO_UDP_PORT_UDT_OS            1382 /* "udt_os */
#define NETIO_UDP_PORT_GWHA              1383 /* GW Hannaway Network License Manager */
#define NETIO_UDP_PORT_OS_LICMAN         1384 /* Objective Solutions License Manager */
#define NETIO_UDP_PORT_ATEX_ELMD         1385 /* "Atex Publishing License Manager */
#define NETIO_UDP_PORT_CHECKSUM          1386 /* CheckSum License Manager */
#define NETIO_UDP_PORT_CADSI_LM          1387 /* Computer Aided Design Software Inc LM */
#define NETIO_UDP_PORT_OBJECTIVE_DBC     1388 /* Objective Solutions DataBase Cache */
#define NETIO_UDP_PORT_ICLPV_DM          1389 /* Document Manager */
#define NETIO_UDP_PORT_ICLPV_SC          1390 /* Storage Controller */
#define NETIO_UDP_PORT_ICLPV_SAS         1391 /* Storage Access Server */
#define NETIO_UDP_PORT_ICLPV_PM          1392 /* Print Manager */
#define NETIO_UDP_PORT_ICLPV_NLS         1393 /* Network Log Server */
#define NETIO_UDP_PORT_ICLPV_NLC         1394 /* Network Log Client */
#define NETIO_UDP_PORT_ICLPV_WSM         1395 /* PC Workstation Manager software */
#define NETIO_UDP_PORT_DVL_ACTIVEMAIL    1396 /* DVL Active Mail */
#define NETIO_UDP_PORT_AUDIO_ACTIVMAIL   1397 /* Audio Active Mail */
#define NETIO_UDP_PORT_VIDEO_ACTIVMAIL   1398 /* Video Active Mail */
#define NETIO_UDP_PORT_CADKEY_LICMAN     1399 /* Cadkey License Manager */
#define NETIO_UDP_PORT_CADKEY_TABLET     1400 /* Cadkey Tablet Daemon */
#define NETIO_UDP_PORT_GOLDLEAF_LICMAN   1401 /* Goldleaf License Manager */
#define NETIO_UDP_PORT_PRM_SM_NP         1402 /* Prospero Resource Manager */
#define NETIO_UDP_PORT_PRM_NM_NP         1403 /* Prospero Resource Manager */
#define NETIO_UDP_PORT_IGI_LM            1404 /* Infinite Graphics License Manager */
#define NETIO_UDP_PORT_IBM_RES           1405 /* IBM Remote Execution Starter */
#define NETIO_UDP_PORT_NETLABS_LM        1406 /* NetLabs License Manager */
#define NETIO_UDP_PORT_DBSA_LM           1407 /* DBSA License Manager */
#define NETIO_UDP_PORT_SOPHIA_LM         1408 /* Sophia License Manager */
#define NETIO_UDP_PORT_HERE_LM           1409 /* Here License Manager */
#define NETIO_UDP_PORT_HIQ               1410 /* HiQ License Manager */
#define NETIO_UDP_PORT_AF                1411 /* AudioFile */
#define NETIO_UDP_PORT_INNOSYS           1412 /* InnoSys */
#define NETIO_UDP_PORT_INNOSYS_ACL       1413 /* Innosys-ACL */
#define NETIO_UDP_PORT_IBM_MQSERIES      1414 /* IBM MQSeries */
#define NETIO_UDP_PORT_DBSTAR            1415 /* DBStar */
#define NETIO_UDP_PORT_NOVELL_LU6_2      1416 /* "Novell LU6.2 */
#define NETIO_UDP_PORT_TIMBUKTU_SRV1     1417 /* Timbuktu Service 1 Port */
#define NETIO_UDP_PORT_TIMBUKTU_SRV2     1418 /* Timbuktu Service 2 Port */
#define NETIO_UDP_PORT_TIMBUKTU_SRV3     1419 /* Timbuktu Service 3 Port */
#define NETIO_UDP_PORT_TIMBUKTU_SRV4     1420 /* Timbuktu Service 4 Port */
#define NETIO_UDP_PORT_GANDALF_LM        1421 /* Gandalf License Manager */
#define NETIO_UDP_PORT_AUTODESK_LM       1422 /* Autodesk License Manager */
#define NETIO_UDP_PORT_ESSBASE           1423 /* Essbase Arbor Software */
#define NETIO_UDP_PORT_HYBRID            1424 /* Hybrid Encryption Protocol */
#define NETIO_UDP_PORT_ZION_LM           1425 /* Zion Software License Manager */
#define NETIO_UDP_PORT_SAIS              1426 /* Satellite-data Acquisition System 1 */
#define NETIO_UDP_PORT_MLOADD            1427 /* mloadd monitoring tool */
#define NETIO_UDP_PORT_INFORMATIK_LM     1428 /* Informatik License Manager */
#define NETIO_UDP_PORT_NMS               1429 /* Hypercom NMS */
#define NETIO_UDP_PORT_TPDU              1430 /* Hypercom TPDU */
#define NETIO_UDP_PORT_RGTP              1431 /* Reverse Gossip Transport */
#define NETIO_UDP_PORT_BLUEBERRY_LM      1432 /* Blueberry Software License Manager */
#define NETIO_UDP_PORT_MS_SQL_S          1433 /* Microsoft-SQL-Server */
#define NETIO_UDP_PORT_MS_SQL_M          1434 /* Microsoft-SQL-Monitor */
#define NETIO_UDP_PORT_IBM_CICS          1435 /* IBM CICS */
#define NETIO_UDP_PORT_SAISM             1436 /* Satellite-data Acquisition System 2 */
#define NETIO_UDP_PORT_TABULA            1437 /* Tabula */
#define NETIO_UDP_PORT_EICON_SERVER      1438 /* Eicon Security Agent/Server */
#define NETIO_UDP_PORT_EICON_X25         1439 /* Eicon X25/SNA Gateway */
#define NETIO_UDP_PORT_EICON_SLP         1440 /* Eicon Service Location Protocol */
#define NETIO_UDP_PORT_CADIS_1           1441 /* Cadis License Management */
#define NETIO_UDP_PORT_CADIS_2           1442 /* Cadis License Management */
#define NETIO_UDP_PORT_IES_LM            1443 /* Integrated Engineering Software */
#define NETIO_UDP_PORT_MARCAM_LM         1444 /* Marcam  License Management */
#define NETIO_UDP_PORT_PROXIMA_LM        1445 /* Proxima License Manager */
#define NETIO_UDP_PORT_ORA_LM            1446 /* Optical Research Associates License Manager */
#define NETIO_UDP_PORT_APRI_LM           1447 /* Applied Parallel Research LM */
#define NETIO_UDP_PORT_OC_LM             1448 /* OpenConnect License Manager */
#define NETIO_UDP_PORT_PEPORT            1449 /* PEport */
#define NETIO_UDP_PORT_DWF               1450 /* Tandem Distributed Workbench Facility */
#define NETIO_UDP_PORT_INFOMAN           1451 /* IBM Information Management */
#define NETIO_UDP_PORT_GTEGSC_LM         1452 /* GTE Government Systems License Man */
#define NETIO_UDP_PORT_GENIE_LM          1453 /* Genie License Manager */
#define NETIO_UDP_PORT_INTERHDL_ELMD     1454 /* "interHDL License Manager */
#define NETIO_UDP_PORT_ESL_LM            1455 /* ESL License Manager */
#define NETIO_UDP_PORT_DCA               1456 /* DCA */
#define NETIO_UDP_PORT_VALISYS_LM        1457 /* Valisys License Manager */
#define NETIO_UDP_PORT_NRCABQ_LM         1458 /* Nichols Research Corp. */
#define NETIO_UDP_PORT_PROSHARE1         1459 /* Proshare Notebook Application */
#define NETIO_UDP_PORT_PROSHARE2         1460 /* Proshare Notebook Application */
#define NETIO_UDP_PORT_IBM_WRLESS_LAN    1461 /* "IBM Wireless LAN */
#define NETIO_UDP_PORT_WORLD_LM          1462 /* World License Manager */
#define NETIO_UDP_PORT_NUCLEUS           1463 /* Nucleus */
#define NETIO_UDP_PORT_MSL_LMD           1464 /* "MSL License Manager */
#define NETIO_UDP_PORT_PIPES             1465 /* Pipes Platform */
#define NETIO_UDP_PORT_OCEANSOFT_LM      1466 /* Ocean Software License Manager */
#define NETIO_UDP_PORT_CSDMBASE          1467 /* CSDMBASE */
#define NETIO_UDP_PORT_CSDM              1468 /* CSDM */
#define NETIO_UDP_PORT_AAL_LM            1469 /* Active Analysis Limited License Manager */
#define NETIO_UDP_PORT_UAIACT            1470 /* Universal Analytics */
#define NETIO_UDP_PORT_CSDMBASE2         1471 /* csdmbase */
#define NETIO_UDP_PORT_CSDM2             1472 /* csdm */
#define NETIO_UDP_PORT_OPENMATH          1473 /* OpenMath */
#define NETIO_UDP_PORT_TELEFINDER        1474 /* Telefinder */
#define NETIO_UDP_PORT_TALIGENT_LM       1475 /* Taligent License Manager */
#define NETIO_UDP_PORT_CLVM_CFG          1476 /* clvm-cfg */
#define NETIO_UDP_PORT_MS_SNA_SERVER     1477 /* ms-sna-server */
#define NETIO_UDP_PORT_MS_SNA_BASE       1478 /* ms-sna-base */
#define NETIO_UDP_PORT_DBEREGISTER       1479 /* dberegister */
#define NETIO_UDP_PORT_PACERFORUM        1480 /* PacerForum */
#define NETIO_UDP_PORT_AIRS              1481 /* AIRS */
#define NETIO_UDP_PORT_MITEKSYS_LM       1482 /* Miteksys License Manager */
#define NETIO_UDP_PORT_AFS               1483 /* AFS License Manager */
#define NETIO_UDP_PORT_CONFLUENT         1484 /* Confluent License Manager */
#define NETIO_UDP_PORT_LANSOURCE         1485 /* LANSource */
#define NETIO_UDP_PORT_NMS_TOPO_SERV     1486 /* "nms_topo_serv */
#define NETIO_UDP_PORT_LOCALINFOSRVR     1487 /* LocalInfoSrvr */
#define NETIO_UDP_PORT_DOCSTOR           1488 /* DocStor */
#define NETIO_UDP_PORT_DMDOCBROKER       1489 /* dmdocbroker */
#define NETIO_UDP_PORT_INSITU_CONF       1490 /* insitu-conf */
#define NETIO_UDP_PORT_STONE_DESIGN_1    1492 /* stone-design-1 */
#define NETIO_UDP_PORT_NETMAP_LM         1493 /* "netmap_lm */
#define NETIO_UDP_PORT_ICA               1494 /* ica */
#define NETIO_UDP_PORT_CVC               1495 /* cvc */
#define NETIO_UDP_PORT_LIBERTY_LM        1496 /* liberty-lm */
#define NETIO_UDP_PORT_RFX_LM            1497 /* rfx-lm */
#define NETIO_UDP_PORT_SYBASE_SQLANY     1498 /* Sybase SQL Any */
#define NETIO_UDP_PORT_FHC               1499 /* Federico Heinz Consultora */
#define NETIO_UDP_PORT_VLSI_LM           1500 /* VLSI License Manager */
#define NETIO_UDP_PORT_SAISCM            1501 /* Satellite-data Acquisition System 3 */
#define NETIO_UDP_PORT_SHIVADISCOVERY    1502 /* Shiva */
#define NETIO_UDP_PORT_IMTC_MCS          1503 /* Databeam */
#define NETIO_UDP_PORT_EVB_ELM           1504 /* EVB Software Engineering License Manager */
#define NETIO_UDP_PORT_FUNKPROXY         1505 /* "Funk Software */
#define NETIO_UDP_PORT_UTCD              1506 /* Universal Time daemon (utcd) */
#define NETIO_UDP_PORT_SYMPLEX           1507 /* symplex */
#define NETIO_UDP_PORT_DIAGMOND          1508 /* diagmond */
#define NETIO_UDP_PORT_ROBCAD_LM         1509 /* "Robcad */
#define NETIO_UDP_PORT_MVX_LM            1510 /* Midland Valley Exploration Ltd. Lic. Man. */
#define NETIO_UDP_PORT_3L_L1             1511 /* 3l-l1 */
#define NETIO_UDP_PORT_WINS              1512 /* Microsoft's Windows Internet Name Service */
#define NETIO_UDP_PORT_FUJITSU_DTC       1513 /* "Fujitsu Systems Business of America */
#define NETIO_UDP_PORT_FUJITSU_DTCNS     1514 /* "Fujitsu Systems Business of America */
#define NETIO_UDP_PORT_IFOR_PROTOCOL     1515 /* ifor-protocol */
#define NETIO_UDP_PORT_VPAD              1516 /* Virtual Places Audio data */
#define NETIO_UDP_PORT_VPAC              1517 /* Virtual Places Audio control */
#define NETIO_UDP_PORT_VPVD              1518 /* Virtual Places Video data */
#define NETIO_UDP_PORT_VPVC              1519 /* Virtual Places Video control */
#define NETIO_UDP_PORT_ATM_ZIP_OFFICE    1520 /* atm zip office */
#define NETIO_UDP_PORT_NCUBE_LM          1521 /* nCube License Manager */
#define NETIO_UDP_PORT_RICARDO_LM        1522 /* Ricardo North America License Manager */
#define NETIO_UDP_PORT_CICHILD_LM        1523 /* cichild */
#define NETIO_UDP_PORT_INGRESLOCK        1524 /* ingres */
#define NETIO_UDP_PORT_ORASRV            1525 /* oracle */
#define NETIO_UDP_PORT_PDAP_NP           1526 /* Prospero Data Access Prot non-priv */
#define NETIO_UDP_PORT_TLISRV            1527 /* oracle */
#define NETIO_UDP_PORT_COAUTHOR          1529 /* oracle */
#define NETIO_UDP_PORT_RAP_SERVICE       1530 /* rap-service */
#define NETIO_UDP_PORT_RAP_LISTEN        1531 /* rap-listen */
#define NETIO_UDP_PORT_MIROCONNECT       1532 /* miroconnect */
#define NETIO_UDP_PORT_VIRTUAL_PLACES    1533 /* Virtual Places Software */
#define NETIO_UDP_PORT_MICROMUSE_LM      1534 /* micromuse-lm */
#define NETIO_UDP_PORT_AMPR_INFO         1535 /* ampr-info */
#define NETIO_UDP_PORT_AMPR_INTER        1536 /* ampr-inter */
#define NETIO_UDP_PORT_SDSC_LM           1537 /* isi-lm */
#define NETIO_UDP_PORT_3DS_LM            1538 /* 3ds-lm */
#define NETIO_UDP_PORT_INTELLISTOR_LM    1539 /* Intellistor License Manager */
#define NETIO_UDP_PORT_RDS               1540 /* rds */
#define NETIO_UDP_PORT_RDS2              1541 /* rds2 */
#define NETIO_UDP_PORT_GRIDGEN_ELMD      1542 /* gridgen-elmd */
#define NETIO_UDP_PORT_SIMBA_CS          1543 /* simba-cs */
#define NETIO_UDP_PORT_ASPECLMD          1544 /* aspeclmd */
#define NETIO_UDP_PORT_VISTIUM_SHARE     1545 /* vistium-share */
#define NETIO_UDP_PORT_ABBACCURAY        1546 /* abbaccuray */
#define NETIO_UDP_PORT_LAPLINK           1547 /* laplink */
#define NETIO_UDP_PORT_AXON_LM           1548 /* Axon License Manager */
#define NETIO_UDP_PORT_SHIVASOUND        1549 /* Shiva Sound */
#define NETIO_UDP_PORT_3M_IMAGE_LM       1550 /* Image Storage license manager 3M Company */
#define NETIO_UDP_PORT_HECMTL_DB         1551 /* HECMTL-DB */
#define NETIO_UDP_PORT_PCIARRAY          1552 /* pciarray */
#define NETIO_UDP_PORT_SNA_CS            1553 /* sna-cs */
#define NETIO_UDP_PORT_CACI_LM           1554 /* CACI Products Company License Manager */
#define NETIO_UDP_PORT_LIVELAN           1555 /* livelan */
#define NETIO_UDP_PORT_VERITAS_PBX       1556 /* "VERITAS Private Branch Exchange */
#define NETIO_UDP_PORT_ARBORTEXT_LM      1557 /* ArborText License Manager */
#define NETIO_UDP_PORT_XINGMPEG          1558 /* xingmpeg */
#define NETIO_UDP_PORT_WEB2HOST          1559 /* web2host */
#define NETIO_UDP_PORT_ASCI_VAL          1560 /* ASCI-RemoteSHADOW */
#define NETIO_UDP_PORT_FACILITYVIEW      1561 /* facilityview */
#define NETIO_UDP_PORT_PCONNECTMGR       1562 /* pconnectmgr */
#define NETIO_UDP_PORT_CADABRA_LM        1563 /* Cadabra License Manager */
#define NETIO_UDP_PORT_PAY_PER_VIEW      1564 /* Pay-Per-View */
#define NETIO_UDP_PORT_WINDDLB           1565 /* WinDD */
#define NETIO_UDP_PORT_CORELVIDEO        1566 /* CORELVIDEO */
#define NETIO_UDP_PORT_JLICELMD          1567 /* jlicelmd */
#define NETIO_UDP_PORT_TSSPMAP           1568 /* tsspmap */
#define NETIO_UDP_PORT_ETS               1569 /* ets */
#define NETIO_UDP_PORT_ORBIXD            1570 /* orbixd */
#define NETIO_UDP_PORT_RDB_DBS_DISP      1571 /* Oracle Remote Data Base */
#define NETIO_UDP_PORT_CHIP_LM           1572 /* Chipcom License Manager */
#define NETIO_UDP_PORT_ITSCOMM_NS        1573 /* itscomm-ns */
#define NETIO_UDP_PORT_MVEL_LM           1574 /* mvel-lm */
#define NETIO_UDP_PORT_ORACLENAMES       1575 /* oraclenames */
#define NETIO_UDP_PORT_MOLDFLOW_LM       1576 /* Moldflow License Manager */
#define NETIO_UDP_PORT_HYPERCUBE_LM      1577 /* hypercube-lm */
#define NETIO_UDP_PORT_JACOBUS_LM        1578 /* Jacobus License Manager */
#define NETIO_UDP_PORT_IOC_SEA_LM        1579 /* ioc-sea-lm */
#define NETIO_UDP_PORT_TN_TL_R2          1580 /* tn-tl-r2 */
#define NETIO_UDP_PORT_MIL_2045_47001    1581 /* MIL-2045-47001 */
#define NETIO_UDP_PORT_MSIMS             1582 /* MSIMS */
#define NETIO_UDP_PORT_SIMBAEXPRESS      1583 /* simbaexpress */
#define NETIO_UDP_PORT_TN_TL_FD2         1584 /* tn-tl-fd2 */
#define NETIO_UDP_PORT_INTV              1585 /* intv */
#define NETIO_UDP_PORT_IBM_ABTACT        1586 /* ibm-abtact */
#define NETIO_UDP_PORT_PRA_ELMD          1587 /* "pra_elmd */
#define NETIO_UDP_PORT_TRIQUEST_LM       1588 /* triquest-lm */
#define NETIO_UDP_PORT_VQP               1589 /* VQP */
#define NETIO_UDP_PORT_GEMINI_LM         1590 /* gemini-lm */
#define NETIO_UDP_PORT_NCPM_PM           1591 /* ncpm-pm */
#define NETIO_UDP_PORT_COMMONSPACE       1592 /* commonspace */
#define NETIO_UDP_PORT_MAINSOFT_LM       1593 /* mainsoft-lm */
#define NETIO_UDP_PORT_SIXTRAK           1594 /* sixtrak */
#define NETIO_UDP_PORT_RADIO             1595 /* radio */
#define NETIO_UDP_PORT_RADIO_BC          1596 /* radio-bc */
#define NETIO_UDP_PORT_ORBPLUS_IIOP      1597 /* orbplus-iiop */
#define NETIO_UDP_PORT_PICKNFS           1598 /* picknfs */
#define NETIO_UDP_PORT_SIMBASERVICES     1599 /* simbaservices */
#define NETIO_UDP_PORT_ISSD              1600 /* issd */
#define NETIO_UDP_PORT_AAS               1601 /* aas */
#define NETIO_UDP_PORT_INSPECT           1602 /* inspect */
#define NETIO_UDP_PORT_PICODBC           1603 /* pickodbc */
#define NETIO_UDP_PORT_ICABROWSER        1604 /* icabrowser */
#define NETIO_UDP_PORT_SLP               1605 /* Salutation Manager (Salutation Protocol) */
#define NETIO_UDP_PORT_SLM_API           1606 /* Salutation Manager (SLM-API) */
#define NETIO_UDP_PORT_STT               1607 /* stt */
#define NETIO_UDP_PORT_SMART_LM          1608 /* Smart Corp. License Manager */
#define NETIO_UDP_PORT_ISYSG_LM          1609 /* isysg-lm */
#define NETIO_UDP_PORT_TAURUS_WH         1610 /* taurus-wh */
#define NETIO_UDP_PORT_ILL               1611 /* Inter Library Loan */
#define NETIO_UDP_PORT_NETBILL_TRANS     1612 /* NetBill Transaction Server */
#define NETIO_UDP_PORT_NETBILL_KEYREP    1613 /* NetBill Key Repository */
#define NETIO_UDP_PORT_NETBILL_CRED      1614 /* NetBill Credential Server */
#define NETIO_UDP_PORT_NETBILL_AUTH      1615 /* NetBill Authorization Server */
#define NETIO_UDP_PORT_NETBILL_PROD      1616 /* NetBill Product Server */
#define NETIO_UDP_PORT_NIMROD_AGENT      1617 /* Nimrod Inter-Agent Communication */
#define NETIO_UDP_PORT_SKYTELNET         1618 /* skytelnet */
#define NETIO_UDP_PORT_XS_OPENSTORAGE    1619 /* xs-openstorage */
#define NETIO_UDP_PORT_FAXPORTWINPORT    1620 /* faxportwinport */
#define NETIO_UDP_PORT_SOFTDATAPHONE     1621 /* softdataphone */
#define NETIO_UDP_PORT_ONTIME            1622 /* ontime */
#define NETIO_UDP_PORT_JALEOSND          1623 /* jaleosnd */
#define NETIO_UDP_PORT_UDP_SR_PORT       1624 /* udp-sr-port */
#define NETIO_UDP_PORT_SVS_OMAGENT       1625 /* svs-omagent */
#define NETIO_UDP_PORT_SHOCKWAVE         1626 /* Shockwave */
#define NETIO_UDP_PORT_T128_GATEWAY      1627 /* T.128 Gateway */
#define NETIO_UDP_PORT_LONTALK_NORM      1628 /* LonTalk normal */
#define NETIO_UDP_PORT_LONTALK_URGNT     1629 /* LonTalk urgent */
#define NETIO_UDP_PORT_ORACLENET8CMAN    1630 /* Oracle Net8 Cman */
#define NETIO_UDP_PORT_VISITVIEW         1631 /* Visit view */
#define NETIO_UDP_PORT_PAMMRATC          1632 /* PAMMRATC */
#define NETIO_UDP_PORT_PAMMRPC           1633 /* PAMMRPC */
#define NETIO_UDP_PORT_LOAPROBE          1634 /* Log On America Probe */
#define NETIO_UDP_PORT_EDB_SERVER1       1635 /* EDB Server 1 */
#define NETIO_UDP_PORT_ISDC              1636 /* ISP shared public data control */
#define NETIO_UDP_PORT_ISLC              1637 /* ISP shared local data control */
#define NETIO_UDP_PORT_ISMC              1638 /* ISP shared management control */
#define NETIO_UDP_PORT_CERT_INITIATOR    1639 /* cert-initiator */
#define NETIO_UDP_PORT_CERT_RESPONDER    1640 /* cert-responder */
#define NETIO_UDP_PORT_INVISION          1641 /* InVision */
#define NETIO_UDP_PORT_ISIS_AM           1642 /* isis-am */
#define NETIO_UDP_PORT_ISIS_AMBC         1643 /* isis-ambc */
#define NETIO_UDP_PORT_SAISEH            1644 /* Satellite-data Acquisition System 4 */
#define NETIO_UDP_PORT_SIGHTLINE         1645 /* SightLine */
#define NETIO_UDP_PORT_SA_MSG_PORT       1646 /* sa-msg-port */
#define NETIO_UDP_PORT_RSAP              1647 /* rsap */
#define NETIO_UDP_PORT_CONCURRENT_LM     1648 /* concurrent-lm */
#define NETIO_UDP_PORT_KERMIT            1649 /* kermit */
#define NETIO_UDP_PORT_NKD               1650 /* nkd */
#define NETIO_UDP_PORT_SHIVA_CONFSRVR    1651 /* "shiva_confsrvr */
#define NETIO_UDP_PORT_XNMP              1652 /* xnmp */
#define NETIO_UDP_PORT_ALPHATECH_LM      1653 /* alphatech-lm */
#define NETIO_UDP_PORT_STARGATEALERTS    1654 /* stargatealerts */
#define NETIO_UDP_PORT_DEC_MBADMIN       1655 /* dec-mbadmin */
#define NETIO_UDP_PORT_DEC_MBADMIN_H     1656 /* dec-mbadmin-h */
#define NETIO_UDP_PORT_FUJITSU_MMPDC     1657 /* fujitsu-mmpdc */
#define NETIO_UDP_PORT_SIXNETUDR         1658 /* sixnetudr */
#define NETIO_UDP_PORT_SG_LM             1659 /* Silicon Grail License Manager */
#define NETIO_UDP_PORT_SKIP_MC_GIKREQ    1660 /* skip-mc-gikreq */
#define NETIO_UDP_PORT_NETVIEW_AIX_1     1661 /* netview-aix-1 */
#define NETIO_UDP_PORT_NETVIEW_AIX_2     1662 /* netview-aix-2 */
#define NETIO_UDP_PORT_NETVIEW_AIX_3     1663 /* netview-aix-3 */
#define NETIO_UDP_PORT_NETVIEW_AIX_4     1664 /* netview-aix-4 */
#define NETIO_UDP_PORT_NETVIEW_AIX_5     1665 /* netview-aix-5 */
#define NETIO_UDP_PORT_NETVIEW_AIX_6     1666 /* netview-aix-6 */
#define NETIO_UDP_PORT_NETVIEW_AIX_7     1667 /* netview-aix-7 */
#define NETIO_UDP_PORT_NETVIEW_AIX_8     1668 /* netview-aix-8 */
#define NETIO_UDP_PORT_NETVIEW_AIX_9     1669 /* netview-aix-9 */
#define NETIO_UDP_PORT_NETVIEW_AIX_10    1670 /* netview-aix-10 */
#define NETIO_UDP_PORT_NETVIEW_AIX_11    1671 /* netview-aix-11 */
#define NETIO_UDP_PORT_NETVIEW_AIX_12    1672 /* netview-aix-12 */
#define NETIO_UDP_PORT_PROSHARE_MC_1     1673 /* Intel Proshare Multicast */
#define NETIO_UDP_PORT_PROSHARE_MC_2     1674 /* Intel Proshare Multicast */
#define NETIO_UDP_PORT_PDP               1675 /* Pacific Data Products */
#define NETIO_UDP_PORT_NETCOMM2          1676 /* netcomm2 */
#define NETIO_UDP_PORT_GROUPWISE         1677 /* groupwise */
#define NETIO_UDP_PORT_PROLINK           1678 /* prolink */
#define NETIO_UDP_PORT_DARCORP_LM        1679 /* darcorp-lm */
#define NETIO_UDP_PORT_MICROCOM_SBP      1680 /* microcom-sbp */
#define NETIO_UDP_PORT_SD_ELMD           1681 /* sd-elmd */
#define NETIO_UDP_PORT_LANYON_LANTERN    1682 /* lanyon-lantern */
#define NETIO_UDP_PORT_NCPM_HIP          1683 /* ncpm-hip */
#define NETIO_UDP_PORT_SNARESECURE       1684 /* SnareSecure */
#define NETIO_UDP_PORT_N2NREMOTE         1685 /* n2nremote */
#define NETIO_UDP_PORT_CVMON             1686 /* cvmon */
#define NETIO_UDP_PORT_NSJTP_CTRL        1687 /* nsjtp-ctrl */
#define NETIO_UDP_PORT_NSJTP_DATA        1688 /* nsjtp-data */
#define NETIO_UDP_PORT_FIREFOX           1689 /* firefox */
#define NETIO_UDP_PORT_NG_UMDS           1690 /* ng-umds */
#define NETIO_UDP_PORT_EMPIRE_EMPUMA     1691 /* empire-empuma */
#define NETIO_UDP_PORT_SSTSYS_LM         1692 /* sstsys-lm */
#define NETIO_UDP_PORT_RRIRTR            1693 /* rrirtr */
#define NETIO_UDP_PORT_RRIMWM            1694 /* rrimwm */
#define NETIO_UDP_PORT_RRILWM            1695 /* rrilwm */
#define NETIO_UDP_PORT_RRIFMM            1696 /* rrifmm */
#define NETIO_UDP_PORT_RRISAT            1697 /* rrisat */
#define NETIO_UDP_PORT_RSVP_ENCAP_1      1698 /* RSVP-ENCAPSULATION-1 */
#define NETIO_UDP_PORT_RSVP_ENCAP_2      1699 /* RSVP-ENCAPSULATION-2 */
#define NETIO_UDP_PORT_MPS_RAFT          1700 /* mps-raft */
#define NETIO_UDP_PORT_L2F               1701 /* l2f */
#define NETIO_UDP_PORT_DESKSHARE         1702 /* deskshare */
#define NETIO_UDP_PORT_HB_ENGINE         1703 /* hb-engine */
#define NETIO_UDP_PORT_BCS_BROKER        1704 /* bcs-broker */
#define NETIO_UDP_PORT_SLINGSHOT         1705 /* slingshot */
#define NETIO_UDP_PORT_JETFORM           1706 /* jetform */
#define NETIO_UDP_PORT_VDMPLAY           1707 /* vdmplay */
#define NETIO_UDP_PORT_GAT_LMD           1708 /* gat-lmd */
#define NETIO_UDP_PORT_CENTRA            1709 /* centra */
#define NETIO_UDP_PORT_IMPERA            1710 /* impera */
#define NETIO_UDP_PORT_PPTCONFERENCE     1711 /* pptconference */
#define NETIO_UDP_PORT_REGISTRAR         1712 /* resource monitoring service */
#define NETIO_UDP_PORT_CONFERENCETALK    1713 /* ConferenceTalk */
#define NETIO_UDP_PORT_SESI_LM           1714 /* sesi-lm */
#define NETIO_UDP_PORT_HOUDINI_LM        1715 /* houdini-lm */
#define NETIO_UDP_PORT_XMSG              1716 /* xmsg */
#define NETIO_UDP_PORT_FJ_HDNET          1717 /* fj-hdnet */
#define NETIO_UDP_PORT_H323GATEDISC      1718 /* H.323 Multicast Gatekeeper Discover */
#define NETIO_UDP_PORT_H323GATESTAT      1719 /* H.323 Unicast Gatekeeper Signaling */
#define NETIO_UDP_PORT_H323HOSTCALL      1720 /* H.323 Call Control Signalling */
#define NETIO_UDP_PORT_CAICCI            1721 /* caicci */
#define NETIO_UDP_PORT_HKS_LM            1722 /* HKS License Manager */
#define NETIO_UDP_PORT_PPTP              1723 /* pptp */
#define NETIO_UDP_PORT_CSBPHONEMASTER    1724 /* csbphonemaster */
#define NETIO_UDP_PORT_IDEN_RALP         1725 /* iden-ralp */
#define NETIO_UDP_PORT_IBERIAGAMES       1726 /* IBERIAGAMES */
#define NETIO_UDP_PORT_WINDDX            1727 /* winddx */
#define NETIO_UDP_PORT_TELINDUS          1728 /* TELINDUS */
#define NETIO_UDP_PORT_CITYNL            1729 /* CityNL License Management */
#define NETIO_UDP_PORT_ROKETZ            1730 /* roketz */
#define NETIO_UDP_PORT_MSICCP            1731 /* MSICCP */
#define NETIO_UDP_PORT_PROXIM            1732 /* proxim */
#define NETIO_UDP_PORT_SIIPAT            1733 /* SIMS - SIIPAT Protocol for Alarm Transmission */
#define NETIO_UDP_PORT_CAMBERTX_LM       1734 /* Camber Corporation License Management */
#define NETIO_UDP_PORT_PRIVATECHAT       1735 /* PrivateChat */
#define NETIO_UDP_PORT_STREET_STREAM     1736 /* street-stream */
#define NETIO_UDP_PORT_ULTIMAD           1737 /* ultimad */
#define NETIO_UDP_PORT_GAMEGEN1          1738 /* GameGen1 */
#define NETIO_UDP_PORT_WEBACCESS         1739 /* webaccess */
#define NETIO_UDP_PORT_ENCORE            1740 /* encore */
#define NETIO_UDP_PORT_CISCO_NET_MGMT    1741 /* cisco-net-mgmt */
#define NETIO_UDP_PORT_3COM_NSD          1742 /* 3Com-nsd */
#define NETIO_UDP_PORT_CINEGRFX_LM       1743 /* Cinema Graphics License Manager */
#define NETIO_UDP_PORT_NCPM_FT           1744 /* ncpm-ft */
#define NETIO_UDP_PORT_REMOTE_WINSOCK    1745 /* remote-winsock */
#define NETIO_UDP_PORT_FTRAPID_1         1746 /* ftrapid-1 */
#define NETIO_UDP_PORT_FTRAPID_2         1747 /* ftrapid-2 */
#define NETIO_UDP_PORT_ORACLE_EM1        1748 /* oracle-em1 */
#define NETIO_UDP_PORT_ASPEN_SERVICES    1749 /* aspen-services */
#define NETIO_UDP_PORT_SSLP              1750 /* Simple Socket Library's PortMaster */
#define NETIO_UDP_PORT_SWIFTNET          1751 /* SwiftNet */
#define NETIO_UDP_PORT_LOFR_LM           1752 /* Leap of Faith Research License Manager */
#define NETIO_UDP_PORT_ORACLE_EM2        1754 /* oracle-em2 */
#define NETIO_UDP_PORT_MS_STREAMING      1755 /* ms-streaming */
#define NETIO_UDP_PORT_CAPFAST_LMD       1756 /* capfast-lmd */
#define NETIO_UDP_PORT_CNHRP             1757 /* cnhrp */
#define NETIO_UDP_PORT_TFTP_MCAST        1758 /* tftp-mcast */
#define NETIO_UDP_PORT_SPSS_LM           1759 /* SPSS License Manager */
#define NETIO_UDP_PORT_WWW_LDAP_GW       1760 /* www-ldap-gw */
#define NETIO_UDP_PORT_CFT_0             1761 /* cft-0 */
#define NETIO_UDP_PORT_CFT_1             1762 /* cft-1 */
#define NETIO_UDP_PORT_CFT_2             1763 /* cft-2 */
#define NETIO_UDP_PORT_CFT_3             1764 /* cft-3 */
#define NETIO_UDP_PORT_CFT_4             1765 /* cft-4 */
#define NETIO_UDP_PORT_CFT_5             1766 /* cft-5 */
#define NETIO_UDP_PORT_CFT_6             1767 /* cft-6 */
#define NETIO_UDP_PORT_CFT_7             1768 /* cft-7 */
#define NETIO_UDP_PORT_BMC_NET_ADM       1769 /* bmc-net-adm */
#define NETIO_UDP_PORT_BMC_NET_SVC       1770 /* bmc-net-svc */
#define NETIO_UDP_PORT_VAULTBASE         1771 /* vaultbase */
#define NETIO_UDP_PORT_ESSWEB_GW         1772 /* EssWeb Gateway */
#define NETIO_UDP_PORT_KMSCONTROL        1773 /* KMSControl */
#define NETIO_UDP_PORT_GLOBAL_DTSERV     1774 /* global-dtserv */
#define NETIO_UDP_PORT_FEMIS             1776 /* Federal Emergency Management Information System */
#define NETIO_UDP_PORT_POWERGUARDIAN     1777 /* powerguardian */
#define NETIO_UDP_PORT_PRODIGY_INTRNET   1778 /* prodigy-internet */
#define NETIO_UDP_PORT_PHARMASOFT        1779 /* pharmasoft */
#define NETIO_UDP_PORT_DPKEYSERV         1780 /* dpkeyserv */
#define NETIO_UDP_PORT_ANSWERSOFT_LM     1781 /* answersoft-lm */
#define NETIO_UDP_PORT_HP_HCIP           1782 /* hp-hcip */
#define NETIO_UDP_PORT_FINLE_LM          1784 /* Finle License Manager */
#define NETIO_UDP_PORT_WINDLM            1785 /* Wind River Systems License Manager */
#define NETIO_UDP_PORT_FUNK_LOGGER       1786 /* funk-logger */
#define NETIO_UDP_PORT_FUNK_LICENSE      1787 /* funk-license */
#define NETIO_UDP_PORT_PSMOND            1788 /* psmond */
#define NETIO_UDP_PORT_HELLO             1789 /* hello */
#define NETIO_UDP_PORT_NMSP2             1790 /* Narrative Media Streaming Protocol */
#define NETIO_UDP_PORT_EA1               1791 /* EA1 */
#define NETIO_UDP_PORT_IBM_DT_2          1792 /* ibm-dt-2 */
#define NETIO_UDP_PORT_RSC_ROBOT         1793 /* rsc-robot */
#define NETIO_UDP_PORT_CERA_BCM          1794 /* cera-bcm */
#define NETIO_UDP_PORT_DPI_PROXY         1795 /* dpi-proxy */
#define NETIO_UDP_PORT_VOCALTEC_ADMIN    1796 /* Vocaltec Server Administration */
#define NETIO_UDP_PORT_UMA2              1797 /* UMA */
#define NETIO_UDP_PORT_ETP               1798 /* Event Transfer Protocol */
#define NETIO_UDP_PORT_NETRISK           1799 /* NETRISK */
#define NETIO_UDP_PORT_ANSYS_LM          1800 /* ANSYS-License manager */
#define NETIO_UDP_PORT_MSMQ              1801 /* Microsoft Message Que */
#define NETIO_UDP_PORT_CONCOMP1          1802 /* ConComp1 */
#define NETIO_UDP_PORT_HP_HCIP_GWY       1803 /* HP-HCIP-GWY */
#define NETIO_UDP_PORT_ENL               1804 /* ENL */
#define NETIO_UDP_PORT_ENL_NAME          1805 /* ENL-Name */
#define NETIO_UDP_PORT_MUSICONLINE       1806 /* Musiconline */
#define NETIO_UDP_PORT_FHSP              1807 /* Fujitsu Hot Standby Protocol */
#define NETIO_UDP_PORT_ORACLE_VP2        1808 /* Oracle-VP2 */
#define NETIO_UDP_PORT_ORACLE_VP1        1809 /* Oracle-VP1 */
#define NETIO_UDP_PORT_JERAND_LM         1810 /* Jerand License Manager */
#define NETIO_UDP_PORT_SCIENTIA_SDB      1811 /* Scientia-SDB */
#define NETIO_UDP_PORT_RADIUS            1812 /* RADIUS */
#define NETIO_UDP_PORT_RADIUS_ACCT       1813 /* RADIUS Accounting */
#define NETIO_UDP_PORT_TDP_SUITE         1814 /* TDP Suite */
#define NETIO_UDP_PORT_MMPFT             1815 /* MMPFT */
#define NETIO_UDP_PORT_HARP              1816 /* HARP */
#define NETIO_UDP_PORT_RKB_OSCS          1817 /* RKB-OSCS */
#define NETIO_UDP_PORT_ETFTP             1818 /* Enhanced Trivial File Transfer Protocol */
#define NETIO_UDP_PORT_PLATO_LM          1819 /* Plato License Manager */
#define NETIO_UDP_PORT_MCAGENT           1820 /* mcagent */
#define NETIO_UDP_PORT_DONNYWORLD        1821 /* donnyworld */
#define NETIO_UDP_PORT_ES_ELMD           1822 /* es-elmd */
#define NETIO_UDP_PORT_UNISYS_LM         1823 /* Unisys Natural Language License Manager */
#define NETIO_UDP_PORT_METRICS_PAS       1824 /* metrics-pas */
#define NETIO_UDP_PORT_DIRECPC_VIDEO     1825 /* DirecPC Video */
#define NETIO_UDP_PORT_ARDT              1826 /* ARDT */
#define NETIO_UDP_PORT_ASI               1827 /* ASI */
#define NETIO_UDP_PORT_ITM_MCELL_U       1828 /* itm-mcell-u */
#define NETIO_UDP_PORT_OPTIKA_EMEDIA     1829 /* Optika eMedia */
#define NETIO_UDP_PORT_NET8_CMAN         1830 /* Oracle Net8 CMan Admin */
#define NETIO_UDP_PORT_MYRTLE            1831 /* Myrtle */
#define NETIO_UDP_PORT_THT_TREASURE      1832 /* ThoughtTreasure */
#define NETIO_UDP_PORT_UDPRADIO          1833 /* udpradio */
#define NETIO_UDP_PORT_ARDUSUNI          1834 /* ARDUS Unicast */
#define NETIO_UDP_PORT_ARDUSMUL          1835 /* ARDUS Multicast */
#define NETIO_UDP_PORT_STE_SMSC          1836 /* ste-smsc */
#define NETIO_UDP_PORT_CSOFT1            1837 /* csoft1 */
#define NETIO_UDP_PORT_TALNET            1838 /* TALNET */
#define NETIO_UDP_PORT_NETOPIA_VO1       1839 /* netopia-vo1 */
#define NETIO_UDP_PORT_NETOPIA_VO2       1840 /* netopia-vo2 */
#define NETIO_UDP_PORT_NETOPIA_VO3       1841 /* netopia-vo3 */
#define NETIO_UDP_PORT_NETOPIA_VO4       1842 /* netopia-vo4 */
#define NETIO_UDP_PORT_NETOPIA_VO5       1843 /* netopia-vo5 */
#define NETIO_UDP_PORT_DIRECPC_DLL       1844 /* DirecPC-DLL */
#define NETIO_UDP_PORT_ALTALINK          1845 /* altalink */
#define NETIO_UDP_PORT_TUNSTALL_PNC      1846 /* Tunstall PNC */
#define NETIO_UDP_PORT_SLP_NOTIFY        1847 /* SLP Notification */
#define NETIO_UDP_PORT_FJDOCDIST         1848 /* fjdocdist */
#define NETIO_UDP_PORT_ALPHA_SMS         1849 /* ALPHA-SMS */
#define NETIO_UDP_PORT_GSI               1850 /* GSI */
#define NETIO_UDP_PORT_CTCD              1851 /* ctcd */
#define NETIO_UDP_PORT_VIRTUAL_TIME      1852 /* Virtual Time */
#define NETIO_UDP_PORT_VIDS_AVTP         1853 /* VIDS-AVTP */
#define NETIO_UDP_PORT_BUDDY_DRAW        1854 /* Buddy Draw */
#define NETIO_UDP_PORT_FIORANO_RTRSVC    1855 /* Fiorano RtrSvc */
#define NETIO_UDP_PORT_FIORANO_MSGSVC    1856 /* Fiorano MsgSvc */
#define NETIO_UDP_PORT_DATACAPTOR        1857 /* DataCaptor */
#define NETIO_UDP_PORT_PRIVATEARK        1858 /* PrivateArk */
#define NETIO_UDP_PORT_GAMMAFETCHSVR     1859 /* Gamma Fetcher Server */
#define NETIO_UDP_PORT_SUNSCALAR_SVC     1860 /* SunSCALAR Services */
#define NETIO_UDP_PORT_LECROY_VICP       1861 /* LeCroy VICP */
#define NETIO_UDP_PORT_MYSQL_CM_AGENT    1862 /* MySQL Cluster Manager Agent */
#define NETIO_UDP_PORT_MSNP              1863 /* MSNP */
#define NETIO_UDP_PORT_PARADYM_31PORT    1864 /* Paradym 31 Port */
#define NETIO_UDP_PORT_ENTP              1865 /* ENTP */
#define NETIO_UDP_PORT_SWRMI             1866 /* swrmi */
#define NETIO_UDP_PORT_UDRIVE            1867 /* UDRIVE */
#define NETIO_UDP_PORT_VIZIBLEBROWSER    1868 /* VizibleBrowser */
#define NETIO_UDP_PORT_TRANSACT          1869 /* TransAct */
#define NETIO_UDP_PORT_SUNSCALAR_DNS     1870 /* SunSCALAR DNS Service */
#define NETIO_UDP_PORT_CANOCENTRAL0      1871 /* Cano Central 0 */
#define NETIO_UDP_PORT_CANOCENTRAL1      1872 /* Cano Central 1 */
#define NETIO_UDP_PORT_FJMPJPS           1873 /* Fjmpjps */
#define NETIO_UDP_PORT_FJSWAPSNP         1874 /* Fjswapsnp */
#define NETIO_UDP_PORT_WESTELL_STATS     1875 /* westell stats */
#define NETIO_UDP_PORT_EWCAPPSRV         1876 /* ewcappsrv */
#define NETIO_UDP_PORT_HP_WEBQOSDB       1877 /* hp-webqosdb */
#define NETIO_UDP_PORT_DRMSMC            1878 /* drmsmc */
#define NETIO_UDP_PORT_NETTGAIN_NMS      1879 /* NettGain NMS */
#define NETIO_UDP_PORT_VSAT_CONTROL      1880 /* Gilat VSAT Control */
#define NETIO_UDP_PORT_IBM_MQSERIES2     1881 /* IBM WebSphere MQ Everyplace */
#define NETIO_UDP_PORT_ECSQDMN           1882 /* CA eTrust Common Services */
#define NETIO_UDP_PORT_IBM_MQISDP        1883 /* IBM MQSeries SCADA */
#define NETIO_UDP_PORT_IDMAPS            1884 /* Internet Distance Map Svc */
#define NETIO_UDP_PORT_VRTSTRAPSERVER    1885 /* Veritas Trap Server */
#define NETIO_UDP_PORT_LEOIP             1886 /* Leonardo over IP */
#define NETIO_UDP_PORT_FILEX_LPORT       1887 /* FileX Listening Port */
#define NETIO_UDP_PORT_NCCONFIG          1888 /* NC Config Port */
#define NETIO_UDP_PORT_UNIFY_ADAPTER     1889 /* Unify Web Adapter Service */
#define NETIO_UDP_PORT_WILKENLISTENER    1890 /* wilkenListener */
#define NETIO_UDP_PORT_CHILDKEY_NOTIF    1891 /* ChildKey Notification */
#define NETIO_UDP_PORT_CHILDKEY_CTRL     1892 /* ChildKey Control */
#define NETIO_UDP_PORT_ELAD              1893 /* ELAD Protocol */
#define NETIO_UDP_PORT_O2SERVER_PORT     1894 /* O2Server Port */
#define NETIO_UDP_PORT_B_NOVATIVE_LS     1896 /* b-novative license server */
#define NETIO_UDP_PORT_METAAGENT         1897 /* MetaAgent */
#define NETIO_UDP_PORT_CYMTEC_PORT       1898 /* Cymtec secure management */
#define NETIO_UDP_PORT_MC2STUDIOS        1899 /* MC2Studios */
#define NETIO_UDP_PORT_SSDP              1900 /* SSDP */
#define NETIO_UDP_PORT_FJICL_TEP_A       1901 /* Fujitsu ICL Terminal Emulator Program A */
#define NETIO_UDP_PORT_FJICL_TEP_B       1902 /* Fujitsu ICL Terminal Emulator Program B */
#define NETIO_UDP_PORT_LINKNAME          1903 /* Local Link Name Resolution */
#define NETIO_UDP_PORT_FJICL_TEP_C       1904 /* Fujitsu ICL Terminal Emulator Program C */
#define NETIO_UDP_PORT_SUGP              1905 /* Secure UP.Link Gateway Protocol */
#define NETIO_UDP_PORT_TPMD              1906 /* TPortMapperReq */
#define NETIO_UDP_PORT_INTRASTAR         1907 /* IntraSTAR */
#define NETIO_UDP_PORT_DAWN              1908 /* Dawn */
#define NETIO_UDP_PORT_GLOBAL_WLINK      1909 /* Global World Link */
#define NETIO_UDP_PORT_ULTRABAC          1910 /* UltraBac Software communications port */
#define NETIO_UDP_PORT_MTP               1911 /* Starlight Networks Multimedia Transport Protocol */
#define NETIO_UDP_PORT_RHP_IIBP          1912 /* rhp-iibp */
#define NETIO_UDP_PORT_ARMADP            1913 /* armadp */
#define NETIO_UDP_PORT_ELM_MOMENTUM      1914 /* Elm-Momentum */
#define NETIO_UDP_PORT_FACELINK          1915 /* FACELINK */
#define NETIO_UDP_PORT_PERSONA           1916 /* Persoft Persona */
#define NETIO_UDP_PORT_NOAGENT           1917 /* nOAgent */
#define NETIO_UDP_PORT_CAN_NDS           1918 /* IBM Tivole Directory Service - NDS */
#define NETIO_UDP_PORT_CAN_DCH           1919 /* IBM Tivoli Directory Service - DCH */
#define NETIO_UDP_PORT_CAN_FERRET        1920 /* IBM Tivoli Directory Service - FERRET */
#define NETIO_UDP_PORT_NOADMIN           1921 /* NoAdmin */
#define NETIO_UDP_PORT_TAPESTRY          1922 /* Tapestry */
#define NETIO_UDP_PORT_SPICE             1923 /* SPICE */
#define NETIO_UDP_PORT_XIIP              1924 /* XIIP */
#define NETIO_UDP_PORT_DISCOVERY_PORT    1925 /* Surrogate Discovery Port */
#define NETIO_UDP_PORT_EGS               1926 /* Evolution Game Server */
#define NETIO_UDP_PORT_VIDETE_CIPC       1927 /* Videte CIPC Port */
#define NETIO_UDP_PORT_EMSD_PORT         1928 /* Expnd Maui Srvr Dscovr */
#define NETIO_UDP_PORT_BANDWIZ_SYSTEM    1929 /* Bandwiz System - Server */
#define NETIO_UDP_PORT_DRIVEAPPSERVER    1930 /* Drive AppServer */
#define NETIO_UDP_PORT_AMDSCHED          1931 /* AMD SCHED */
#define NETIO_UDP_PORT_CTT_BROKER        1932 /* CTT Broker */
#define NETIO_UDP_PORT_XMAPI             1933 /* IBM LM MT Agent */
#define NETIO_UDP_PORT_XAAPI             1934 /* IBM LM Appl Agent */
#define NETIO_UDP_PORT_MACROMEDIA_FCS    1935 /* Macromedia Flash Communications server MX */
#define NETIO_UDP_PORT_JETCMESERVER      1936 /* JetCmeServer Server Port */
#define NETIO_UDP_PORT_JWSERVER          1937 /* JetVWay Server Port */
#define NETIO_UDP_PORT_JWCLIENT          1938 /* JetVWay Client Port */
#define NETIO_UDP_PORT_JVSERVER          1939 /* JetVision Server Port */
#define NETIO_UDP_PORT_JVCLIENT          1940 /* JetVision Client Port */
#define NETIO_UDP_PORT_DIC_AIDA          1941 /* DIC-Aida */
#define NETIO_UDP_PORT_RES               1942 /* Real Enterprise Service */
#define NETIO_UDP_PORT_BEEYOND_MEDIA     1943 /* Beeyond Media */
#define NETIO_UDP_PORT_CLOSE_COMBAT      1944 /* close-combat */
#define NETIO_UDP_PORT_DIALOGIC_ELMD     1945 /* dialogic-elmd */
#define NETIO_UDP_PORT_TEKPLS            1946 /* tekpls */
#define NETIO_UDP_PORT_SENTINELSRM       1947 /* SentinelSRM */
#define NETIO_UDP_PORT_EYE2EYE           1948 /* eye2eye */
#define NETIO_UDP_PORT_ISMAEASDAQLIVE    1949 /* ISMA Easdaq Live */
#define NETIO_UDP_PORT_ISMAEASDAQTEST    1950 /* ISMA Easdaq Test */
#define NETIO_UDP_PORT_BCS_LMSERVER      1951 /* bcs-lmserver */
#define NETIO_UDP_PORT_MPNJSC            1952 /* mpnjsc */
#define NETIO_UDP_PORT_RAPIDBASE         1953 /* Rapid Base */
#define NETIO_UDP_PORT_ABR_API           1954 /* ABR-API (diskbridge) */
#define NETIO_UDP_PORT_ABR_SECURE        1955 /* ABR-Secure Data (diskbridge) */
#define NETIO_UDP_PORT_VRTL_VMF_DS       1956 /* Vertel VMF DS */
#define NETIO_UDP_PORT_UNIX_STATUS       1957 /* unix-status */
#define NETIO_UDP_PORT_DXADMIND          1958 /* CA Administration Daemon */
#define NETIO_UDP_PORT_SIMP_ALL          1959 /* SIMP Channel */
#define NETIO_UDP_PORT_NASMANAGER        1960 /* Merit DAC NASmanager */
#define NETIO_UDP_PORT_BTS_APPSERVER     1961 /* BTS APPSERVER */
#define NETIO_UDP_PORT_BIAP_MP           1962 /* BIAP-MP */
#define NETIO_UDP_PORT_WEBMACHINE        1963 /* WebMachine */
#define NETIO_UDP_PORT_SOLID_E_ENGINE    1964 /* SOLID E ENGINE */
#define NETIO_UDP_PORT_TIVOLI_NPM        1965 /* Tivoli NPM */
#define NETIO_UDP_PORT_SLUSH             1966 /* Slush */
#define NETIO_UDP_PORT_SNS_QUOTE         1967 /* SNS Quote */
#define NETIO_UDP_PORT_LIPSINC           1968 /* LIPSinc */
#define NETIO_UDP_PORT_LIPSINC1          1969 /* LIPSinc 1 */
#define NETIO_UDP_PORT_NETOP_RC          1970 /* NetOp Remote Control */
#define NETIO_UDP_PORT_NETOP_SCHOOL      1971 /* NetOp School */
#define NETIO_UDP_PORT_INTERSYS_CACHE    1972 /* Cache */
#define NETIO_UDP_PORT_DLSRAP            1973 /* Data Link Switching Remote Access Protocol */
#define NETIO_UDP_PORT_DRP               1974 /* DRP */
#define NETIO_UDP_PORT_TCOFLASHAGENT     1975 /* TCO Flash Agent */
#define NETIO_UDP_PORT_TCOREGAGENT       1976 /* TCO Reg Agent */
#define NETIO_UDP_PORT_TCOADDRESSBOOK    1977 /* TCO Address Book */
#define NETIO_UDP_PORT_UNISQL            1978 /* UniSQL */
#define NETIO_UDP_PORT_UNISQL_JAVA       1979 /* UniSQL Java */
#define NETIO_UDP_PORT_PEARLDOC_XACT     1980 /* PearlDoc XACT */
#define NETIO_UDP_PORT_P2PQ              1981 /* p2pQ */
#define NETIO_UDP_PORT_ESTAMP            1982 /* Evidentiary Timestamp */
#define NETIO_UDP_PORT_LHTP              1983 /* Loophole Test Protocol */
#define NETIO_UDP_PORT_BB                1984 /* BB */
#define NETIO_UDP_PORT_HSRP              1985 /* Hot Standby Router Protocol */
#define NETIO_UDP_PORT_LICENSEDAEMON     1986 /* cisco license management */
#define NETIO_UDP_PORT_TR_RSRB_P1        1987 /* cisco RSRB Priority 1 port */
#define NETIO_UDP_PORT_TR_RSRB_P2        1988 /* cisco RSRB Priority 2 port */
#define NETIO_UDP_PORT_TR_RSRB_P3        1989 /* cisco RSRB Priority 3 port */
#define NETIO_UDP_PORT_STUN_P1           1990 /* cisco STUN Priority 1 port */
#define NETIO_UDP_PORT_STUN_P2           1991 /* cisco STUN Priority 2 port */
#define NETIO_UDP_PORT_STUN_P3           1992 /* cisco STUN Priority 3 port */
#define NETIO_UDP_PORT_SNMP_TCP_PORT     1993 /* cisco SNMP TCP port */
#define NETIO_UDP_PORT_STUN_PORT         1994 /* cisco serial tunnel port */
#define NETIO_UDP_PORT_PERF_PORT         1995 /* cisco perf port */
#define NETIO_UDP_PORT_TR_RSRB_PORT      1996 /* cisco Remote SRB port */
#define NETIO_UDP_PORT_GDP_PORT          1997 /* cisco Gateway Discovery Protocol */
#define NETIO_UDP_PORT_X25_SVC_PORT      1998 /* cisco X.25 service (XOT) */
#define NETIO_UDP_PORT_TCP_ID_PORT       1999 /* cisco identification port */
#define NETIO_UDP_PORT_CISCO_SCCP        2000 /* Cisco SCCp */
#define NETIO_UDP_PORT_WIZARD            2001 /* curry */
#define NETIO_UDP_PORT_BRUTUS            2003 /* Brutus Server */
#define NETIO_UDP_PORT_EMCE              2004 /* CCWS mm conf */
#define NETIO_UDP_PORT_RAID_CD           2006 /* raid */
#define NETIO_UDP_PORT_PIPE_SERVER       2010 /* "IANA assigned this well-formed service name as a replacement for ""pipe_server""." */
#define NETIO_UDP_PORT_HSRPV6            2029 /* Hot Standby Router Protocol IPv6 */
#define NETIO_UDP_PORT_MOBRIEN_CHAT      2031 /* mobrien-chat */
#define NETIO_UDP_PORT_E_DPNET           2036 /* Ethernet WS DP network */
#define NETIO_UDP_PORT_APPLUS            2037 /* APplus Application Server */
#define NETIO_UDP_PORT_PRIZMA            2039 /* Prizma Monitoring Service */
#define NETIO_UDP_PORT_ISIS              2042 /* isis */
#define NETIO_UDP_PORT_ISIS_BCAST        2043 /* isis-bcast */
#define NETIO_UDP_PORT_NFS               2049 /* Network File System - Sun Microsystems */
#define NETIO_UDP_PORT_AV_EMB_CONFIG     2050 /* Avaya EMB Config Port */
#define NETIO_UDP_PORT_EPNSDP            2051 /* EPNSDP */
#define NETIO_UDP_PORT_CLEARVISN         2052 /* clearVisn Services Port */
#define NETIO_UDP_PORT_LOT105_DS_UPD     2053 /* Lot105 DSuper Updates */
#define NETIO_UDP_PORT_WEBLOGIN          2054 /* Weblogin Port */
#define NETIO_UDP_PORT_IOP               2055 /* Iliad-Odyssey Protocol */
#define NETIO_UDP_PORT_OMNISKY           2056 /* OmniSky Port */
#define NETIO_UDP_PORT_RICH_CP           2057 /* Rich Content Protocol */
#define NETIO_UDP_PORT_NEWWAVESEARCH     2058 /* NewWaveSearchables RMI */
#define NETIO_UDP_PORT_BMC_MESSAGING     2059 /* BMC Messaging Service */
#define NETIO_UDP_PORT_TELENIUMDAEMON    2060 /* Telenium Daemon IF */
#define NETIO_UDP_PORT_NETMOUNT          2061 /* NetMount */
#define NETIO_UDP_PORT_ICG_SWP           2062 /* ICG SWP Port */
#define NETIO_UDP_PORT_ICG_BRIDGE        2063 /* ICG Bridge Port */
#define NETIO_UDP_PORT_ICG_IPRELAY       2064 /* ICG IP Relay Port */
#define NETIO_UDP_PORT_DLSRPN            2065 /* Data Link Switch Read Port Number */
#define NETIO_UDP_PORT_AURA              2066 /* AVM USB Remote Architecture */
#define NETIO_UDP_PORT_DLSWPN            2067 /* Data Link Switch Write Port Number */
#define NETIO_UDP_PORT_AVAUTHSRVPRTCL    2068 /* Avocent AuthSrv Protocol */
#define NETIO_UDP_PORT_EVENT_PORT        2069 /* HTTP Event Port */
#define NETIO_UDP_PORT_AH_ESP_ENCAP      2070 /* AH and ESP Encapsulated in UDP packet */
#define NETIO_UDP_PORT_ACP_PORT          2071 /* Axon Control Protocol */
#define NETIO_UDP_PORT_MSYNC             2072 /* GlobeCast mSync */
#define NETIO_UDP_PORT_GXS_DATA_PORT     2073 /* DataReel Database Socket */
#define NETIO_UDP_PORT_VRTL_VMF_SA       2074 /* Vertel VMF SA */
#define NETIO_UDP_PORT_NEWLIXENGINE      2075 /* Newlix ServerWare Engine */
#define NETIO_UDP_PORT_NEWLIXCONFIG      2076 /* Newlix JSPConfig */
#define NETIO_UDP_PORT_TSRMAGT           2077 /* Old Tivoli Storage Manager */
#define NETIO_UDP_PORT_TPCSRVR           2078 /* IBM Total Productivity Center Server */
#define NETIO_UDP_PORT_IDWARE_ROUTER     2079 /* IDWARE Router Port */
#define NETIO_UDP_PORT_AUTODESK_NLM      2080 /* Autodesk NLM (FLEXlm) */
#define NETIO_UDP_PORT_KME_TRAP_PORT     2081 /* KME PRINTER TRAP PORT */
#define NETIO_UDP_PORT_INFOWAVE          2082 /* Infowave Mobility Server */
#define NETIO_UDP_PORT_RADSEC            2083 /* Secure Radius Service */
#define NETIO_UDP_PORT_SUNCLUSTERGEO     2084 /* SunCluster Geographic */
#define NETIO_UDP_PORT_ADA_CIP           2085 /* ADA Control */
#define NETIO_UDP_PORT_GNUNET            2086 /* GNUnet */
#define NETIO_UDP_PORT_ELI               2087 /* ELI - Event Logging Integration */
#define NETIO_UDP_PORT_IP_BLF            2088 /* IP Busy Lamp Field */
#define NETIO_UDP_PORT_SEP               2089 /* Security Encapsulation Protocol - SEP */
#define NETIO_UDP_PORT_LRP               2090 /* Load Report Protocol */
#define NETIO_UDP_PORT_PRP               2091 /* PRP */
#define NETIO_UDP_PORT_DESCENT3          2092 /* Descent 3 */
#define NETIO_UDP_PORT_NBX_CC            2093 /* NBX CC */
#define NETIO_UDP_PORT_NBX_AU            2094 /* NBX AU */
#define NETIO_UDP_PORT_NBX_SER           2095 /* NBX SER */
#define NETIO_UDP_PORT_NBX_DIR           2096 /* NBX DIR */
#define NETIO_UDP_PORT_JETFORMPREVIEW    2097 /* Jet Form Preview */
#define NETIO_UDP_PORT_DIALOG_PORT       2098 /* Dialog Port */
#define NETIO_UDP_PORT_H2250_ANNEX_G     2099 /* H.225.0 Annex G Signalling */
#define NETIO_UDP_PORT_AMIGANETFS        2100 /* Amiga Network Filesystem */
#define NETIO_UDP_PORT_RTCM_SC104        2101 /* rtcm-sc104 */
#define NETIO_UDP_PORT_ZEPHYR_SRV        2102 /* Zephyr server */
#define NETIO_UDP_PORT_ZEPHYR_CLT        2103 /* Zephyr serv-hm connection */
#define NETIO_UDP_PORT_ZEPHYR_HM         2104 /* Zephyr hostmanager */
#define NETIO_UDP_PORT_MINIPAY           2105 /* MiniPay */
#define NETIO_UDP_PORT_MZAP              2106 /* MZAP */
#define NETIO_UDP_PORT_BINTEC_ADMIN      2107 /* BinTec Admin */
#define NETIO_UDP_PORT_COMCAM            2108 /* Comcam */
#define NETIO_UDP_PORT_ERGOLIGHT         2109 /* Ergolight */
#define NETIO_UDP_PORT_UMSP              2110 /* UMSP */
#define NETIO_UDP_PORT_DSATP             2111 /* OPNET Dynamic Sampling Agent Transaction Protocol */
#define NETIO_UDP_PORT_IDONIX_METANET    2112 /* Idonix MetaNet */
#define NETIO_UDP_PORT_HSL_STORM         2113 /* HSL StoRM */
#define NETIO_UDP_PORT_NEWHEIGHTS        2114 /* NEWHEIGHTS */
#define NETIO_UDP_PORT_KDM               2115 /* Key Distribution Manager */
#define NETIO_UDP_PORT_CCOWCMR           2116 /* CCOWCMR */
#define NETIO_UDP_PORT_MENTACLIENT       2117 /* MENTACLIENT */
#define NETIO_UDP_PORT_MENTASERVER       2118 /* MENTASERVER */
#define NETIO_UDP_PORT_GSIGATEKEEPER     2119 /* GSIGATEKEEPER */
#define NETIO_UDP_PORT_QENCP             2120 /* Quick Eagle Networks CP */
#define NETIO_UDP_PORT_SCIENTIA_SSDB     2121 /* SCIENTIA-SSDB */
#define NETIO_UDP_PORT_CAUPC_REMOTE      2122 /* CauPC Remote Control */
#define NETIO_UDP_PORT_GTP_CONTROL       2123 /* GTP-Control Plane (3GPP) */
#define NETIO_UDP_PORT_ELATELINK         2124 /* ELATELINK */
#define NETIO_UDP_PORT_LOCKSTEP          2125 /* LOCKSTEP */
#define NETIO_UDP_PORT_PKTCABLE_COPS     2126 /* PktCable-COPS */
#define NETIO_UDP_PORT_INDEX_PC_WB       2127 /* INDEX-PC-WB */
#define NETIO_UDP_PORT_NET_STEWARD       2128 /* Net Steward Control */
#define NETIO_UDP_PORT_CS_LIVE           2129 /* cs-live.com */
#define NETIO_UDP_PORT_XDS               2130 /* XDS */
#define NETIO_UDP_PORT_AVANTAGEB2B       2131 /* Avantageb2b */
#define NETIO_UDP_PORT_SOLERA_EPMAP      2132 /* SoleraTec End Point Map */
#define NETIO_UDP_PORT_ZYMED_ZPP         2133 /* ZYMED-ZPP */
#define NETIO_UDP_PORT_AVENUE            2134 /* AVENUE */
#define NETIO_UDP_PORT_GRIS              2135 /* Grid Resource Information Server */
#define NETIO_UDP_PORT_APPWORXSRV        2136 /* APPWORXSRV */
#define NETIO_UDP_PORT_CONNECT           2137 /* CONNECT */
#define NETIO_UDP_PORT_UNBIND_CLUSTER    2138 /* UNBIND-CLUSTER */
#define NETIO_UDP_PORT_IAS_AUTH          2139 /* IAS-AUTH */
#define NETIO_UDP_PORT_IAS_REG           2140 /* IAS-REG */
#define NETIO_UDP_PORT_IAS_ADMIND        2141 /* IAS-ADMIND */
#define NETIO_UDP_PORT_TDMOIP            2142 /* TDM OVER IP */
#define NETIO_UDP_PORT_LV_JC             2143 /* Live Vault Job Control */
#define NETIO_UDP_PORT_LV_FFX            2144 /* Live Vault Fast Object Transfer */
#define NETIO_UDP_PORT_LV_PICI           2145 /* Live Vault Remote Diagnostic Console Support */
#define NETIO_UDP_PORT_LV_NOT            2146 /* Live Vault Admin Event Notification */
#define NETIO_UDP_PORT_LV_AUTH           2147 /* Live Vault Authentication */
#define NETIO_UDP_PORT_VERITAS_UCL       2148 /* VERITAS UNIVERSAL COMMUNICATION LAYER */
#define NETIO_UDP_PORT_ACPTSYS           2149 /* ACPTSYS */
#define NETIO_UDP_PORT_DYNAMIC3D         2150 /* DYNAMIC3D */
#define NETIO_UDP_PORT_DOCENT            2151 /* DOCENT */
#define NETIO_UDP_PORT_GTP_USER          2152 /* GTP-User Plane (3GPP) */
#define NETIO_UDP_PORT_CTLPTC            2153 /* Control Protocol */
#define NETIO_UDP_PORT_STDPTC            2154 /* Standard Protocol */
#define NETIO_UDP_PORT_BRDPTC            2155 /* Bridge Protocol */
#define NETIO_UDP_PORT_TRP               2156 /* Talari Reliable Protocol */
#define NETIO_UDP_PORT_XNDS              2157 /* Xerox Network Document Scan Protocol */
#define NETIO_UDP_PORT_TOUCHNETPLUS      2158 /* TouchNetPlus Service */
#define NETIO_UDP_PORT_GDBREMOTE         2159 /* GDB Remote Debug Port */
#define NETIO_UDP_PORT_APC_2160          2160 /* APC 2160 */
#define NETIO_UDP_PORT_APC_2161          2161 /* APC 2161 */
#define NETIO_UDP_PORT_NAVISPHERE        2162 /* Navisphere */
#define NETIO_UDP_PORT_NAVISPHERE_SEC    2163 /* Navisphere Secure */
#define NETIO_UDP_PORT_DDNS_V3           2164 /* Dynamic DNS Version 3 */
#define NETIO_UDP_PORT_X_BONE_API        2165 /* X-Bone API */
#define NETIO_UDP_PORT_IWSERVER          2166 /* iwserver */
#define NETIO_UDP_PORT_RAW_SERIAL        2167 /* Raw Async Serial Link */
#define NETIO_UDP_PORT_EASY_SOFT_MUX     2168 /* easy-soft Multiplexer */
#define NETIO_UDP_PORT_BRAIN             2169 /* Backbone for Academic Information Notification (BRAIN) */
#define NETIO_UDP_PORT_EYETV             2170 /* EyeTV Server Port */
#define NETIO_UDP_PORT_MSFW_STORAGE      2171 /* MS Firewall Storage */
#define NETIO_UDP_PORT_MSFW_S_STORAGE    2172 /* MS Firewall SecureStorage */
#define NETIO_UDP_PORT_MSFW_REPLICA      2173 /* MS Firewall Replication */
#define NETIO_UDP_PORT_MSFW_ARRAY        2174 /* MS Firewall Intra Array */
#define NETIO_UDP_PORT_AIRSYNC           2175 /* Microsoft Desktop AirSync Protocol */
#define NETIO_UDP_PORT_RAPI              2176 /* Microsoft ActiveSync Remote API */
#define NETIO_UDP_PORT_QWAVE             2177 /* qWAVE Bandwidth Estimate */
#define NETIO_UDP_PORT_BITSPEER          2178 /* Peer Services for BITS */
#define NETIO_UDP_PORT_VMRDP             2179 /* Microsoft RDP for virtual machines */
#define NETIO_UDP_PORT_MC_GT_SRV         2180 /* Millicent Vendor Gateway Server */
#define NETIO_UDP_PORT_EFORWARD          2181 /* eforward */
#define NETIO_UDP_PORT_CGN_STAT          2182 /* CGN status */
#define NETIO_UDP_PORT_CGN_CONFIG        2183 /* Code Green configuration */
#define NETIO_UDP_PORT_NVD               2184 /* NVD User */
#define NETIO_UDP_PORT_ONBASE_DDS        2185 /* OnBase Distributed Disk Services */
#define NETIO_UDP_PORT_GTAUA             2186 /* Guy-Tek Automated Update Applications */
#define NETIO_UDP_PORT_SSMD              2187 /* Sepehr System Management Data */
#define NETIO_UDP_PORT_TIVOCONNECT       2190 /* TiVoConnect Beacon */
#define NETIO_UDP_PORT_TVBUS             2191 /* TvBus Messaging */
#define NETIO_UDP_PORT_ASDIS             2192 /* ASDIS software management */
#define NETIO_UDP_PORT_DRWCS             2193 /* Dr.Web Enterprise Management Service */
#define NETIO_UDP_PORT_MNP_EXCHANGE      2197 /* MNP data exchange */
#define NETIO_UDP_PORT_ONEHOME_REMOTE    2198 /* OneHome Remote Access */
#define NETIO_UDP_PORT_ONEHOME_HELP      2199 /* OneHome Service Port */
#define NETIO_UDP_PORT_ICI               2200 /* ICI */
#define NETIO_UDP_PORT_ATS               2201 /* Advanced Training System Program */
#define NETIO_UDP_PORT_IMTC_MAP          2202 /* Int. Multimedia Teleconferencing Cosortium */
#define NETIO_UDP_PORT_B2_RUNTIME        2203 /* b2 Runtime Protocol */
#define NETIO_UDP_PORT_B2_LICENSE        2204 /* b2 License Server */
#define NETIO_UDP_PORT_JPS               2205 /* Java Presentation Server */
#define NETIO_UDP_PORT_HPOCBUS           2206 /* HP OpenCall bus */
#define NETIO_UDP_PORT_HPSSD             2207 /* HP Status and Services */
#define NETIO_UDP_PORT_HPIOD             2208 /* HP I/O Backend */
#define NETIO_UDP_PORT_RIMF_PS           2209 /* HP RIM for Files Portal Service */
#define NETIO_UDP_PORT_NOAAPORT          2210 /* NOAAPORT Broadcast Network */
#define NETIO_UDP_PORT_EMWIN             2211 /* EMWIN */
#define NETIO_UDP_PORT_LEECOPOSSERVER    2212 /* LeeCO POS Server Service */
#define NETIO_UDP_PORT_KALI              2213 /* Kali */
#define NETIO_UDP_PORT_RPI               2214 /* RDQ Protocol Interface */
#define NETIO_UDP_PORT_IPCORE            2215 /* IPCore.co.za GPRS */
#define NETIO_UDP_PORT_VTU_COMMS         2216 /* VTU data service */
#define NETIO_UDP_PORT_GOTODEVICE        2217 /* GoToDevice Device Management */
#define NETIO_UDP_PORT_BOUNZZA           2218 /* Bounzza IRC Proxy */
#define NETIO_UDP_PORT_NETIQ_NCAP        2219 /* NetIQ NCAP Protocol */
#define NETIO_UDP_PORT_NETIQ             2220 /* NetIQ End2End */
#define NETIO_UDP_PORT_ROCKWELL_CSP1     2221 /* Rockwell CSP1 */
#define NETIO_UDP_PORT_ETHERNET_IP_1     2222 /* "EtherNet/IP I/O */
#define NETIO_UDP_PORT_ROCKWELL_CSP2     2223 /* Rockwell CSP2 */
#define NETIO_UDP_PORT_EFI_MG            2224 /* Easy Flexible Internet/Multiplayer Games */
#define NETIO_UDP_PORT_DI_DRM            2226 /* Digital Instinct DRM */
#define NETIO_UDP_PORT_DI_MSG            2227 /* DI Messaging Service */
#define NETIO_UDP_PORT_EHOME_MS          2228 /* eHome Message Server */
#define NETIO_UDP_PORT_DATALENS          2229 /* DataLens Service */
#define NETIO_UDP_PORT_QUEUEADM          2230 /* MetaSoft Job Queue Administration Service */
#define NETIO_UDP_PORT_WIMAXASNCP        2231 /* WiMAX ASN Control Plane Protocol */
#define NETIO_UDP_PORT_IVS_VIDEO         2232 /* IVS Video default */
#define NETIO_UDP_PORT_INFOCRYPT         2233 /* INFOCRYPT */
#define NETIO_UDP_PORT_DIRECTPLAY        2234 /* DirectPlay */
#define NETIO_UDP_PORT_SERCOMM_WLINK     2235 /* Sercomm-WLink */
#define NETIO_UDP_PORT_NANI              2236 /* Nani */
#define NETIO_UDP_PORT_OPTECH_PORT1_LM   2237 /* Optech Port1 License Manager */
#define NETIO_UDP_PORT_AVIVA_SNA         2238 /* AVIVA SNA SERVER */
#define NETIO_UDP_PORT_IMAGEQUERY        2239 /* Image Query */
#define NETIO_UDP_PORT_RECIPE            2240 /* RECIPe */
#define NETIO_UDP_PORT_IVSD              2241 /* IVS Daemon */
#define NETIO_UDP_PORT_FOLIOCORP         2242 /* Folio Remote Server */
#define NETIO_UDP_PORT_MAGICOM           2243 /* Magicom Protocol */
#define NETIO_UDP_PORT_NMSSERVER         2244 /* NMS Server */
#define NETIO_UDP_PORT_HAO               2245 /* HaO */
#define NETIO_UDP_PORT_PC_MTA_ADDRMAP    2246 /* PacketCable MTA Addr Map */
#define NETIO_UDP_PORT_ANTIDOTEMGRSVR    2247 /* Antidote Deployment Manager Service */
#define NETIO_UDP_PORT_UMS               2248 /* User Management Service */
#define NETIO_UDP_PORT_RFMP              2249 /* RISO File Manager Protocol */
#define NETIO_UDP_PORT_REMOTE_COLLAB     2250 /* remote-collab */
#define NETIO_UDP_PORT_DIF_PORT          2251 /* Distributed Framework Port */
#define NETIO_UDP_PORT_NJENET_SSL        2252 /* NJENET using SSL */
#define NETIO_UDP_PORT_DTV_CHAN_REQ      2253 /* DTV Channel Request */
#define NETIO_UDP_PORT_SEISPOC           2254 /* Seismic P.O.C. Port */
#define NETIO_UDP_PORT_VRTP              2255 /* VRTP - ViRtue Transfer Protocol */
#define NETIO_UDP_PORT_PCC_MFP           2256 /* PCC MFP */
#define NETIO_UDP_PORT_SIMPLE_TX_RX      2257 /* simple text/file transfer */
#define NETIO_UDP_PORT_RCTS              2258 /* Rotorcraft Communications Test System */
#define NETIO_UDP_PORT_APC_2260          2260 /* APC 2260 */
#define NETIO_UDP_PORT_COMOTIONMASTER    2261 /* CoMotion Master Server */
#define NETIO_UDP_PORT_COMOTIONBACK      2262 /* CoMotion Backup Server */
#define NETIO_UDP_PORT_ECWCFG            2263 /* ECweb Configuration Service */
#define NETIO_UDP_PORT_APX500API_1       2264 /* Audio Precision Apx500 API Port 1 */
#define NETIO_UDP_PORT_APX500API_2       2265 /* Audio Precision Apx500 API Port 2 */
#define NETIO_UDP_PORT_MFSERVER          2266 /* M-files Server */
#define NETIO_UDP_PORT_ONTOBROKER        2267 /* OntoBroker */
#define NETIO_UDP_PORT_AMT               2268 /* AMT */
#define NETIO_UDP_PORT_MIKEY             2269 /* MIKEY */
#define NETIO_UDP_PORT_STARSCHOOL        2270 /* starSchool */
#define NETIO_UDP_PORT_MMCALS            2271 /* Secure Meeting Maker Scheduling */
#define NETIO_UDP_PORT_MMCAL             2272 /* Meeting Maker Scheduling */
#define NETIO_UDP_PORT_MYSQL_IM          2273 /* MySQL Instance Manager */
#define NETIO_UDP_PORT_PCTTUNNELL        2274 /* PCTTunneller */
#define NETIO_UDP_PORT_IBRIDGE_DATA      2275 /* iBridge Conferencing */
#define NETIO_UDP_PORT_IBRIDGE_MGMT      2276 /* iBridge Management */
#define NETIO_UDP_PORT_BLUECTRLPROXY     2277 /* Bt device control proxy */
#define NETIO_UDP_PORT_S3DB              2278 /* Simple Stacked Sequences Database */
#define NETIO_UDP_PORT_XMQUERY           2279 /* xmquery */
#define NETIO_UDP_PORT_LNVPOLLER         2280 /* LNVPOLLER */
#define NETIO_UDP_PORT_LNVCONSOLE        2281 /* LNVCONSOLE */
#define NETIO_UDP_PORT_LNVALARM          2282 /* LNVALARM */
#define NETIO_UDP_PORT_LNVSTATUS         2283 /* LNVSTATUS */
#define NETIO_UDP_PORT_LNVMAPS           2284 /* LNVMAPS */
#define NETIO_UDP_PORT_LNVMAILMON        2285 /* LNVMAILMON */
#define NETIO_UDP_PORT_NAS_METERING      2286 /* NAS-Metering */
#define NETIO_UDP_PORT_DNA               2287 /* DNA */
#define NETIO_UDP_PORT_NETML             2288 /* NETML */
#define NETIO_UDP_PORT_DICT_LOOKUP       2289 /* Lookup dict server */
#define NETIO_UDP_PORT_SONUS_LOGGING     2290 /* Sonus Logging Services */
#define NETIO_UDP_PORT_EAPSP             2291 /* EPSON Advanced Printer Share Protocol */
#define NETIO_UDP_PORT_MIB_STREAMING     2292 /* Sonus Element Management Services */
#define NETIO_UDP_PORT_NPDBGMNGR         2293 /* Network Platform Debug Manager */
#define NETIO_UDP_PORT_KONSHUS_LM        2294 /* Konshus License Manager (FLEX) */
#define NETIO_UDP_PORT_ADVANT_LM         2295 /* Advant License Manager */
#define NETIO_UDP_PORT_THETA_LM          2296 /* Theta License Manager (Rainbow) */
#define NETIO_UDP_PORT_D2K_DATAMOVER1    2297 /* D2K DataMover 1 */
#define NETIO_UDP_PORT_D2K_DATAMOVER2    2298 /* D2K DataMover 2 */
#define NETIO_UDP_PORT_PC_TELECOMMUTE    2299 /* PC Telecommute */
#define NETIO_UDP_PORT_CVMMON            2300 /* CVMMON */
#define NETIO_UDP_PORT_CPQ_WBEM          2301 /* Compaq HTTP */
#define NETIO_UDP_PORT_BINDERYSUPPORT    2302 /* Bindery Support */
#define NETIO_UDP_PORT_PROXY_GATEWAY     2303 /* Proxy Gateway */
#define NETIO_UDP_PORT_ATTACHMATE_UTS    2304 /* Attachmate UTS */
#define NETIO_UDP_PORT_MT_SCALESERVER    2305 /* MT ScaleServer */
#define NETIO_UDP_PORT_TAPPI_BOXNET      2306 /* TAPPI BoxNet */
#define NETIO_UDP_PORT_PEHELP            2307 /* pehelp */
#define NETIO_UDP_PORT_SDHELP            2308 /* sdhelp */
#define NETIO_UDP_PORT_SDSERVER          2309 /* SD Server */
#define NETIO_UDP_PORT_SDCLIENT          2310 /* SD Client */
#define NETIO_UDP_PORT_MESSAGESERVICE    2311 /* Message Service */
#define NETIO_UDP_PORT_WANSCALER         2312 /* WANScaler Communication Service */
#define NETIO_UDP_PORT_IAPP              2313 /* IAPP (Inter Access Point Protocol) */
#define NETIO_UDP_PORT_CR_WEBSYSTEMS     2314 /* CR WebSystems */
#define NETIO_UDP_PORT_PRECISE_SFT       2315 /* Precise Sft. */
#define NETIO_UDP_PORT_SENT_LM           2316 /* SENT License Manager */
#define NETIO_UDP_PORT_ATTACHMATE_G32    2317 /* Attachmate G32 */
#define NETIO_UDP_PORT_CADENCECONTROL    2318 /* Cadence Control */
#define NETIO_UDP_PORT_INFOLIBRIA        2319 /* InfoLibria */
#define NETIO_UDP_PORT_SIEBEL_NS         2320 /* Siebel NS */
#define NETIO_UDP_PORT_RDLAP             2321 /* RDLAP */
#define NETIO_UDP_PORT_OFSD              2322 /* ofsd */
#define NETIO_UDP_PORT_3D_NFSD           2323 /* 3d-nfsd */
#define NETIO_UDP_PORT_COSMOCALL         2324 /* Cosmocall */
#define NETIO_UDP_PORT_ANSYSLI           2325 /* ANSYS Licensing Interconnect */
#define NETIO_UDP_PORT_IDCP              2326 /* IDCP */
#define NETIO_UDP_PORT_XINGCSM           2327 /* xingcsm */
#define NETIO_UDP_PORT_NETRIX_SFTM       2328 /* Netrix SFTM */
#define NETIO_UDP_PORT_NVD2              2329 /* NVD */
#define NETIO_UDP_PORT_TSCCHAT           2330 /* TSCCHAT */
#define NETIO_UDP_PORT_AGENTVIEW         2331 /* AGENTVIEW */
#define NETIO_UDP_PORT_RCC_HOST          2332 /* RCC Host */
#define NETIO_UDP_PORT_SNAPP             2333 /* SNAPP */
#define NETIO_UDP_PORT_ACE_CLIENT        2334 /* ACE Client Auth */
#define NETIO_UDP_PORT_ACE_PROXY         2335 /* ACE Proxy */
#define NETIO_UDP_PORT_APPLEUGCONTROL    2336 /* Apple UG Control */
#define NETIO_UDP_PORT_IDEESRV           2337 /* ideesrv */
#define NETIO_UDP_PORT_NORTON_LAMBERT    2338 /* Norton Lambert */
#define NETIO_UDP_PORT_3COM_WEBVIEW      2339 /* 3Com WebView */
#define NETIO_UDP_PORT_WRS_REGISTRY      2340 /* "WRS Registry */
#define NETIO_UDP_PORT_XIOSTATUS         2341 /* XIO Status */
#define NETIO_UDP_PORT_MANAGE_EXEC       2342 /* Seagate Manage Exec */
#define NETIO_UDP_PORT_NATI_LOGOS        2343 /* nati logos */
#define NETIO_UDP_PORT_FCMSYS            2344 /* fcmsys */
#define NETIO_UDP_PORT_DBM               2345 /* dbm */
#define NETIO_UDP_PORT_REDSTORM_JOIN     2346 /* "Game Connection Port */
#define NETIO_UDP_PORT_REDSTORM_FIND     2347 /* "Game Announcement and Location */
#define NETIO_UDP_PORT_REDSTORM_INFO     2348 /* "Information to query for game status */
#define NETIO_UDP_PORT_REDSTORM_DIAG     2349 /* "Diagnostics Port */
#define NETIO_UDP_PORT_PSBSERVER         2350 /* Pharos Booking Server */
#define NETIO_UDP_PORT_PSRSERVER         2351 /* psrserver */
#define NETIO_UDP_PORT_PSLSERVER         2352 /* pslserver */
#define NETIO_UDP_PORT_PSPSERVER         2353 /* pspserver */
#define NETIO_UDP_PORT_PSPRSERVER        2354 /* psprserver */
#define NETIO_UDP_PORT_PSDBSERVER        2355 /* psdbserver */
#define NETIO_UDP_PORT_GXTELMD           2356 /* GXT License Managemant */
#define NETIO_UDP_PORT_UNIHUB_SERVER     2357 /* UniHub Server */
#define NETIO_UDP_PORT_FUTRIX            2358 /* Futrix */
#define NETIO_UDP_PORT_FLUKESERVER       2359 /* FlukeServer */
#define NETIO_UDP_PORT_NEXSTORINDLTD     2360 /* NexstorIndLtd */
#define NETIO_UDP_PORT_TL1               2361 /* TL1 */
#define NETIO_UDP_PORT_DIGIMAN           2362 /* digiman */
#define NETIO_UDP_PORT_MEDIACNTRLNFSD    2363 /* Media Central NFSD */
#define NETIO_UDP_PORT_OI_2000           2364 /* OI-2000 */
#define NETIO_UDP_PORT_DBREF             2365 /* dbref */
#define NETIO_UDP_PORT_QIP_LOGIN         2366 /* qip-login */
#define NETIO_UDP_PORT_SERVICE_CTRL      2367 /* Service Control */
#define NETIO_UDP_PORT_OPENTABLE         2368 /* OpenTable */
#define NETIO_UDP_PORT_L3_HBMON          2370 /* L3-HBMon */
#define NETIO_UDP_PORT_LANMESSENGER      2372 /* LanMessenger */
#define NETIO_UDP_PORT_COMPAQ_HTTPS      2381 /* Compaq HTTPS */
#define NETIO_UDP_PORT_MS_OLAP3          2382 /* Microsoft OLAP */
#define NETIO_UDP_PORT_MS_OLAP4          2383 /* Microsoft OLAP */
#define NETIO_UDP_PORT_SD_CAPACITY       2384 /* SD-CAPACITY */
#define NETIO_UDP_PORT_SD_DATA           2385 /* SD-DATA */
#define NETIO_UDP_PORT_VIRTUALTAPE       2386 /* Virtual Tape */
#define NETIO_UDP_PORT_VSAMREDIRECTOR    2387 /* VSAM Redirector */
#define NETIO_UDP_PORT_MYNAHAUTOSTART    2388 /* MYNAH AutoStart */
#define NETIO_UDP_PORT_OVSESSIONMGR      2389 /* OpenView Session Mgr */
#define NETIO_UDP_PORT_RSMTP             2390 /* RSMTP */
#define NETIO_UDP_PORT_3COM_NET_MGMT     2391 /* 3COM Net Management */
#define NETIO_UDP_PORT_TACTICALAUTH      2392 /* Tactical Auth */
#define NETIO_UDP_PORT_MS_OLAP1          2393 /* MS OLAP 1 */
#define NETIO_UDP_PORT_MS_OLAP2          2394 /* MS OLAP 2 */
#define NETIO_UDP_PORT_LAN900_REMOTE     2395 /* "LAN900 Remote */
#define NETIO_UDP_PORT_WUSAGE            2396 /* Wusage */
#define NETIO_UDP_PORT_NCL               2397 /* NCL */
#define NETIO_UDP_PORT_ORBITER           2398 /* Orbiter */
#define NETIO_UDP_PORT_FMPRO_FDAL        2399 /* "FileMaker */
#define NETIO_UDP_PORT_OPEQUUS_SERVER    2400 /* OpEquus Server */
#define NETIO_UDP_PORT_CVSPSERVER        2401 /* cvspserver */
#define NETIO_UDP_PORT_TASKMASTER2000S   2402 /* TaskMaster 2000 Server */
#define NETIO_UDP_PORT_TASKMASTER2000W   2403 /* TaskMaster 2000 Web */
#define NETIO_UDP_PORT_IEC_104           2404 /* IEC 60870-5-104 process control over IP */
#define NETIO_UDP_PORT_TRC_NETPOLL       2405 /* TRC Netpoll */
#define NETIO_UDP_PORT_JEDISERVER        2406 /* JediServer */
#define NETIO_UDP_PORT_ORION             2407 /* Orion */
#define NETIO_UDP_PORT_SNS_PROTOCOL      2409 /* SNS Protocol */
#define NETIO_UDP_PORT_VRTS_REGISTRY     2410 /* VRTS Registry */
#define NETIO_UDP_PORT_NETWAVE_AP_MGMT   2411 /* Netwave AP Management */
#define NETIO_UDP_PORT_CDN               2412 /* CDN */
#define NETIO_UDP_PORT_ORION_RMI_REG     2413 /* orion-rmi-reg */
#define NETIO_UDP_PORT_BEEYOND           2414 /* Beeyond */
#define NETIO_UDP_PORT_CODIMA_RTP        2415 /* Codima Remote Transaction Protocol */
#define NETIO_UDP_PORT_RMTSERVER         2416 /* RMT Server */
#define NETIO_UDP_PORT_COMPOSIT_SERVER   2417 /* Composit Server */
#define NETIO_UDP_PORT_CAS               2418 /* cas */
#define NETIO_UDP_PORT_ATTACHMATE_S2S    2419 /* Attachmate S2S */
#define NETIO_UDP_PORT_DSLREMOTE_MGMT    2420 /* DSL Remote Management */
#define NETIO_UDP_PORT_G_TALK            2421 /* G-Talk */
#define NETIO_UDP_PORT_CRMSBITS          2422 /* CRMSBITS */
#define NETIO_UDP_PORT_RNRP              2423 /* RNRP */
#define NETIO_UDP_PORT_KOFAX_SVR         2424 /* KOFAX-SVR */
#define NETIO_UDP_PORT_FJITSUAPPMGR      2425 /* Fujitsu App Manager */
#define NETIO_UDP_PORT_MGCP_GATEWAY      2427 /* Media Gateway Control Protocol Gateway */
#define NETIO_UDP_PORT_OTT               2428 /* One Way Trip Time */
#define NETIO_UDP_PORT_FT_ROLE           2429 /* FT-ROLE */
#define NETIO_UDP_PORT_VENUS             2430 /* venus */
#define NETIO_UDP_PORT_VENUS_SE          2431 /* venus-se */
#define NETIO_UDP_PORT_CODASRV           2432 /* codasrv */
#define NETIO_UDP_PORT_CODASRV_SE        2433 /* codasrv-se */
#define NETIO_UDP_PORT_PXC_EPMAP         2434 /* pxc-epmap */
#define NETIO_UDP_PORT_OPTILOGIC         2435 /* OptiLogic */
#define NETIO_UDP_PORT_TOPX              2436 /* TOP/X */
#define NETIO_UDP_PORT_UNICONTROL        2437 /* UniControl */
#define NETIO_UDP_PORT_MSP2              2438 /* MSP */
#define NETIO_UDP_PORT_SYBASEDBSYNCH     2439 /* SybaseDBSynch */
#define NETIO_UDP_PORT_SPEARWAY          2440 /* Spearway Lockers */
#define NETIO_UDP_PORT_PVSW_INET         2441 /* Pervasive I*net Data Server */
#define NETIO_UDP_PORT_NETANGEL          2442 /* Netangel */
#define NETIO_UDP_PORT_POWERCLIENTCSF    2443 /* PowerClient Central Storage Facility */
#define NETIO_UDP_PORT_BTPP2SECTRANS     2444 /* BT PP2 Sectrans */
#define NETIO_UDP_PORT_DTN1              2445 /* DTN1 */
#define NETIO_UDP_PORT_BUES_SERVICE      2446 /* "bues_service */
#define NETIO_UDP_PORT_OVWDB             2447 /* OpenView NNM daemon */
#define NETIO_UDP_PORT_HPPPSSVR          2448 /* hpppsvr */
#define NETIO_UDP_PORT_RATL              2449 /* RATL */
#define NETIO_UDP_PORT_NETADMIN          2450 /* netadmin */
#define NETIO_UDP_PORT_NETCHAT           2451 /* netchat */
#define NETIO_UDP_PORT_SNIFFERCLIENT     2452 /* SnifferClient */
#define NETIO_UDP_PORT_MADGE_LTD         2453 /* madge ltd */
#define NETIO_UDP_PORT_INDX_DDS          2454 /* IndX-DDS */
#define NETIO_UDP_PORT_WAGO_IO_SYSTEM    2455 /* WAGO-IO-SYSTEM */
#define NETIO_UDP_PORT_ALTAV_REMMGT      2456 /* altav-remmgt */
#define NETIO_UDP_PORT_RAPIDO_IP         2457 /* Rapido_IP */
#define NETIO_UDP_PORT_GRIFFIN           2458 /* griffin */
#define NETIO_UDP_PORT_COMMUNITY         2459 /* Community */
#define NETIO_UDP_PORT_MS_THEATER        2460 /* ms-theater */
#define NETIO_UDP_PORT_QADMIFOPER        2461 /* qadmifoper */
#define NETIO_UDP_PORT_QADMIFEVENT       2462 /* qadmifevent */
#define NETIO_UDP_PORT_LSI_RAID_MGMT     2463 /* LSI RAID Management */
#define NETIO_UDP_PORT_DIRECPC_SI        2464 /* DirecPC SI */
#define NETIO_UDP_PORT_LBM               2465 /* Load Balance Management */
#define NETIO_UDP_PORT_LBF               2466 /* Load Balance Forwarding */
#define NETIO_UDP_PORT_HIGH_CRITERIA     2467 /* High Criteria */
#define NETIO_UDP_PORT_QIP_MSGD          2468 /* qip_msgd */
#define NETIO_UDP_PORT_MTI_TCS_COMM      2469 /* MTI-TCS-COMM */
#define NETIO_UDP_PORT_TASKMAN_PORT      2470 /* taskman port */
#define NETIO_UDP_PORT_SEAODBC           2471 /* SeaODBC */
#define NETIO_UDP_PORT_C3                2472 /* C3 */
#define NETIO_UDP_PORT_AKER_CDP          2473 /* Aker-cdp */
#define NETIO_UDP_PORT_VITALANALYSIS     2474 /* Vital Analysis */
#define NETIO_UDP_PORT_ACE_SERVER        2475 /* ACE Server */
#define NETIO_UDP_PORT_ACE_SVR_PROP      2476 /* ACE Server Propagation */
#define NETIO_UDP_PORT_SSM_CVS           2477 /* SecurSight Certificate Valifation Service */
#define NETIO_UDP_PORT_SSM_CSSPS         2478 /* SecurSight Authentication Server (SSL) */
#define NETIO_UDP_PORT_SSM_ELS           2479 /* SecurSight Event Logging Server (SSL) */
#define NETIO_UDP_PORT_POWEREXCHANGE     2480 /* Informatica PowerExchange Listener */
#define NETIO_UDP_PORT_GIOP              2481 /* Oracle GIOP */
#define NETIO_UDP_PORT_GIOP_SSL          2482 /* Oracle GIOP SSL */
#define NETIO_UDP_PORT_TTC               2483 /* Oracle TTC */
#define NETIO_UDP_PORT_TTC_SSL           2484 /* Oracle TTC SSL */
#define NETIO_UDP_PORT_NETOBJECTS1       2485 /* Net Objects1 */
#define NETIO_UDP_PORT_NETOBJECTS2       2486 /* Net Objects2 */
#define NETIO_UDP_PORT_PNS               2487 /* Policy Notice Service */
#define NETIO_UDP_PORT_MOY_CORP          2488 /* Moy Corporation */
#define NETIO_UDP_PORT_TSILB             2489 /* TSILB */
#define NETIO_UDP_PORT_QIP_QDHCP         2490 /* qip_qdhcp */
#define NETIO_UDP_PORT_CONCLAVE_CPP      2491 /* Conclave CPP */
#define NETIO_UDP_PORT_GROOVE            2492 /* GROOVE */
#define NETIO_UDP_PORT_TALARIAN_MQS      2493 /* Talarian MQS */
#define NETIO_UDP_PORT_BMC_AR            2494 /* BMC AR */
#define NETIO_UDP_PORT_FAST_REM_SERV     2495 /* Fast Remote Services */
#define NETIO_UDP_PORT_DIRGIS            2496 /* DIRGIS */
#define NETIO_UDP_PORT_QUADDB            2497 /* Quad DB */
#define NETIO_UDP_PORT_ODN_CASTRAQ       2498 /* ODN-CasTraq */
#define NETIO_UDP_PORT_UNICONTROL2       2499 /* UniControl */
#define NETIO_UDP_PORT_RTSSERV           2500 /* Resource Tracking system server */
#define NETIO_UDP_PORT_RTSCLIENT         2501 /* Resource Tracking system client */
#define NETIO_UDP_PORT_KENTROX_PROT      2502 /* Kentrox Protocol */
#define NETIO_UDP_PORT_NMS_DPNSS         2503 /* NMS-DPNSS */
#define NETIO_UDP_PORT_WLBS              2504 /* WLBS */
#define NETIO_UDP_PORT_PPCONTROL         2505 /* PowerPlay Control */
#define NETIO_UDP_PORT_JBROKER           2506 /* jbroker */
#define NETIO_UDP_PORT_SPOCK             2507 /* spock */
#define NETIO_UDP_PORT_JDATASTORE        2508 /* JDataStore */
#define NETIO_UDP_PORT_FJMPSS            2509 /* fjmpss */
#define NETIO_UDP_PORT_FJAPPMGRBULK      2510 /* fjappmgrbulk */
#define NETIO_UDP_PORT_METASTORM         2511 /* Metastorm */
#define NETIO_UDP_PORT_CITRIXIMA         2512 /* Citrix IMA */
#define NETIO_UDP_PORT_CITRIXADMIN       2513 /* Citrix ADMIN */
#define NETIO_UDP_PORT_FACSYS_NTP        2514 /* Facsys NTP */
#define NETIO_UDP_PORT_FACSYS_ROUTER     2515 /* Facsys Router */
#define NETIO_UDP_PORT_MAINCONTROL       2516 /* Main Control */
#define NETIO_UDP_PORT_CALL_SIG_TRANS    2517 /* H.323 Annex E Call Control Signalling Transport */
#define NETIO_UDP_PORT_WILLY             2518 /* Willy */
#define NETIO_UDP_PORT_GLOBMSGSVC        2519 /* globmsgsvc */
#define NETIO_UDP_PORT_PVSW              2520 /* Pervasive Listener */
#define NETIO_UDP_PORT_ADAPTECMGR        2521 /* Adaptec Manager */
#define NETIO_UDP_PORT_WINDB             2522 /* WinDb */
#define NETIO_UDP_PORT_QKE_LLC_V3        2523 /* Qke LLC V.3 */
#define NETIO_UDP_PORT_OPTIWAVE_LM       2524 /* Optiwave License Management */
#define NETIO_UDP_PORT_MS_V_WORLDS       2525 /* MS V-Worlds */
#define NETIO_UDP_PORT_EMA_SENT_LM       2526 /* EMA License Manager */
#define NETIO_UDP_PORT_IQSERVER          2527 /* IQ Server */
#define NETIO_UDP_PORT_NCR_CCL           2528 /* "NCR CCL */
#define NETIO_UDP_PORT_UTSFTP            2529 /* UTS FTP */
#define NETIO_UDP_PORT_VRCOMMERCE        2530 /* VR Commerce */
#define NETIO_UDP_PORT_ITO_E_GUI         2531 /* ITO-E GUI */
#define NETIO_UDP_PORT_OVTOPMD           2532 /* OVTOPMD */
#define NETIO_UDP_PORT_SNIFFERSERVER     2533 /* SnifferServer */
#define NETIO_UDP_PORT_COMBOX_WEB_ACC    2534 /* Combox Web Access */
#define NETIO_UDP_PORT_MADCAP            2535 /* MADCAP */
#define NETIO_UDP_PORT_BTPP2AUDCTR1      2536 /* btpp2audctr1 */
#define NETIO_UDP_PORT_UPGRADE           2537 /* Upgrade Protocol */
#define NETIO_UDP_PORT_VNWK_PRAPI        2538 /* vnwk-prapi */
#define NETIO_UDP_PORT_VSIADMIN          2539 /* VSI Admin */
#define NETIO_UDP_PORT_LONWORKS          2540 /* LonWorks */
#define NETIO_UDP_PORT_LONWORKS2         2541 /* LonWorks2 */
#define NETIO_UDP_PORT_UDRAWGRAPH        2542 /* uDraw(Graph) */
#define NETIO_UDP_PORT_REFTEK            2543 /* REFTEK */
#define NETIO_UDP_PORT_NOVELL_ZEN        2544 /* Management Daemon Refresh */
#define NETIO_UDP_PORT_SIS_EMT           2545 /* sis-emt */
#define NETIO_UDP_PORT_VYTALVAULTBRTP    2546 /* vytalvaultbrtp */
#define NETIO_UDP_PORT_VYTALVAULTVSMP    2547 /* vytalvaultvsmp */
#define NETIO_UDP_PORT_VYTALVAULTPIPE    2548 /* vytalvaultpipe */
#define NETIO_UDP_PORT_IPASS             2549 /* IPASS */
#define NETIO_UDP_PORT_ADS               2550 /* ADS */
#define NETIO_UDP_PORT_ISG_UDA_SERVER    2551 /* ISG UDA Server */
#define NETIO_UDP_PORT_CALL_LOGGING      2552 /* Call Logging */
#define NETIO_UDP_PORT_EFIDININGPORT     2553 /* efidiningport */
#define NETIO_UDP_PORT_VCNET_LINK_V10    2554 /* VCnet-Link v10 */
#define NETIO_UDP_PORT_COMPAQ_WCP        2555 /* Compaq WCP */
#define NETIO_UDP_PORT_NICETEC_NMSVC     2556 /* nicetec-nmsvc */
#define NETIO_UDP_PORT_NICETEC_MGMT      2557 /* nicetec-mgmt */
#define NETIO_UDP_PORT_PCLEMULTIMEDIA    2558 /* PCLE Multi Media */
#define NETIO_UDP_PORT_LSTP              2559 /* LSTP */
#define NETIO_UDP_PORT_LABRAT            2560 /* labrat */
#define NETIO_UDP_PORT_MOSAIXCC          2561 /* MosaixCC */
#define NETIO_UDP_PORT_DELIBO            2562 /* Delibo */
#define NETIO_UDP_PORT_CTI_REDWOOD       2563 /* CTI Redwood */
#define NETIO_UDP_PORT_HP_3000_TELNET    2564 /* HP 3000 NS/VT block mode telnet */
#define NETIO_UDP_PORT_COORD_SVR         2565 /* Coordinator Server */
#define NETIO_UDP_PORT_PCS_PCW           2566 /* pcs-pcw */
#define NETIO_UDP_PORT_CLP               2567 /* Cisco Line Protocol */
#define NETIO_UDP_PORT_SPAMTRAP          2568 /* SPAM TRAP */
#define NETIO_UDP_PORT_SONUSCALLSIG      2569 /* Sonus Call Signal */
#define NETIO_UDP_PORT_HS_PORT           2570 /* HS Port */
#define NETIO_UDP_PORT_CECSVC            2571 /* CECSVC */
#define NETIO_UDP_PORT_IBP               2572 /* IBP */
#define NETIO_UDP_PORT_TRUSTESTABLISH    2573 /* Trust Establish */
#define NETIO_UDP_PORT_BLOCKADE_BPSP     2574 /* Blockade BPSP */
#define NETIO_UDP_PORT_HL7               2575 /* HL7 */
#define NETIO_UDP_PORT_TCLPRODEBUGGER    2576 /* TCL Pro Debugger */
#define NETIO_UDP_PORT_SCIPTICSLSRVR     2577 /* Scriptics Lsrvr */
#define NETIO_UDP_PORT_RVS_ISDN_DCP      2578 /* RVS ISDN DCP */
#define NETIO_UDP_PORT_MPFONCL           2579 /* mpfoncl */
#define NETIO_UDP_PORT_TRIBUTARY         2580 /* Tributary */
#define NETIO_UDP_PORT_ARGIS_TE          2581 /* ARGIS TE */
#define NETIO_UDP_PORT_ARGIS_DS          2582 /* ARGIS DS */
#define NETIO_UDP_PORT_MON               2583 /* MON */
#define NETIO_UDP_PORT_CYASERV           2584 /* cyaserv */
#define NETIO_UDP_PORT_NETX_SERVER       2585 /* NETX Server */
#define NETIO_UDP_PORT_NETX_AGENT        2586 /* NETX Agent */
#define NETIO_UDP_PORT_MASC              2587 /* MASC */
#define NETIO_UDP_PORT_PRIVILEGE         2588 /* Privilege */
#define NETIO_UDP_PORT_QUARTUS_TCL       2589 /* quartus tcl */
#define NETIO_UDP_PORT_IDOTDIST          2590 /* idotdist */
#define NETIO_UDP_PORT_MAYTAGSHUFFLE     2591 /* Maytag Shuffle */
#define NETIO_UDP_PORT_NETREK            2592 /* netrek */
#define NETIO_UDP_PORT_MNS_MAIL          2593 /* MNS Mail Notice Service */
#define NETIO_UDP_PORT_DTS               2594 /* Data Base Server */
#define NETIO_UDP_PORT_WORLDFUSION1      2595 /* World Fusion 1 */
#define NETIO_UDP_PORT_WORLDFUSION2      2596 /* World Fusion 2 */
#define NETIO_UDP_PORT_HOMESTEADGLORY    2597 /* Homestead Glory */
#define NETIO_UDP_PORT_CITRIXIMACLIENT   2598 /* Citrix MA Client */
#define NETIO_UDP_PORT_SNAPD             2599 /* Snap Discovery */
#define NETIO_UDP_PORT_HPSTGMGR          2600 /* HPSTGMGR */
#define NETIO_UDP_PORT_DISCP_CLIENT      2601 /* discp client */
#define NETIO_UDP_PORT_DISCP_SERVER      2602 /* discp server */
#define NETIO_UDP_PORT_SERVICEMETER      2603 /* Service Meter */
#define NETIO_UDP_PORT_NSC_CCS           2604 /* NSC CCS */
#define NETIO_UDP_PORT_NSC_POSA          2605 /* NSC POSA */
#define NETIO_UDP_PORT_NETMON            2606 /* Dell Netmon */
#define NETIO_UDP_PORT_CONNECTION        2607 /* Dell Connection */
#define NETIO_UDP_PORT_WAG_SERVICE       2608 /* Wag Service */
#define NETIO_UDP_PORT_SYSTEM_MONITOR    2609 /* System Monitor */
#define NETIO_UDP_PORT_VERSA_TEK         2610 /* VersaTek */
#define NETIO_UDP_PORT_LIONHEAD          2611 /* LIONHEAD */
#define NETIO_UDP_PORT_QPASA_AGENT       2612 /* Qpasa Agent */
#define NETIO_UDP_PORT_SMNTUBOOTSTRAP    2613 /* SMNTUBootstrap */
#define NETIO_UDP_PORT_NEVEROFFLINE      2614 /* Never Offline */
#define NETIO_UDP_PORT_FIREPOWER         2615 /* firepower */
#define NETIO_UDP_PORT_APPSWITCH_EMP     2616 /* appswitch-emp */
#define NETIO_UDP_PORT_CMADMIN           2617 /* Clinical Context Managers */
#define NETIO_UDP_PORT_PRIORITY_E_COM    2618 /* Priority E-Com */
#define NETIO_UDP_PORT_BRUCE             2619 /* bruce */
#define NETIO_UDP_PORT_LPSRECOMMENDER    2620 /* LPSRecommender */
#define NETIO_UDP_PORT_MILES_APART       2621 /* Miles Apart Jukebox Server */
#define NETIO_UDP_PORT_METRICADBC        2622 /* MetricaDBC */
#define NETIO_UDP_PORT_LMDP              2623 /* LMDP */
#define NETIO_UDP_PORT_ARIA              2624 /* Aria */
#define NETIO_UDP_PORT_BLWNKL_PORT       2625 /* Blwnkl Port */
#define NETIO_UDP_PORT_GBJD816           2626 /* gbjd816 */
#define NETIO_UDP_PORT_MOSHEBEERI        2627 /* Moshe Beeri */
#define NETIO_UDP_PORT_DICT              2628 /* DICT */
#define NETIO_UDP_PORT_SITARASERVER      2629 /* Sitara Server */
#define NETIO_UDP_PORT_SITARAMGMT        2630 /* Sitara Management */
#define NETIO_UDP_PORT_SITARADIR         2631 /* Sitara Dir */
#define NETIO_UDP_PORT_IRDG_POST         2632 /* IRdg Post */
#define NETIO_UDP_PORT_INTERINTELLI      2633 /* InterIntelli */
#define NETIO_UDP_PORT_PK_ELECTRONICS    2634 /* PK Electronics */
#define NETIO_UDP_PORT_BACKBURNER        2635 /* Back Burner */
#define NETIO_UDP_PORT_SOLVE             2636 /* Solve */
#define NETIO_UDP_PORT_IMDOCSVC          2637 /* Import Document Service */
#define NETIO_UDP_PORT_SYBASEANYWHERE    2638 /* Sybase Anywhere */
#define NETIO_UDP_PORT_AMINET            2639 /* AMInet */
#define NETIO_UDP_PORT_SAI_SENTLM        2640 /* "Sabbagh Associates Licence Manager */
#define NETIO_UDP_PORT_HDL_SRV           2641 /* HDL Server */
#define NETIO_UDP_PORT_TRAGIC            2642 /* Tragic */
#define NETIO_UDP_PORT_GTE_SAMP          2643 /* GTE-SAMP */
#define NETIO_UDP_PORT_TRAVSOFT_IPX_T    2644 /* Travsoft IPX Tunnel */
#define NETIO_UDP_PORT_NOVELL_IPX_CMD    2645 /* Novell IPX CMD */
#define NETIO_UDP_PORT_AND_LM            2646 /* AND License Manager */
#define NETIO_UDP_PORT_SYNCSERVER        2647 /* SyncServer */
#define NETIO_UDP_PORT_UPSNOTIFYPROT     2648 /* Upsnotifyprot */
#define NETIO_UDP_PORT_VPSIPPORT         2649 /* VPSIPPORT */
#define NETIO_UDP_PORT_ERISTWOGUNS       2650 /* eristwoguns */
#define NETIO_UDP_PORT_EBINSITE          2651 /* EBInSite */
#define NETIO_UDP_PORT_INTERPATHPANEL    2652 /* InterPathPanel */
#define NETIO_UDP_PORT_SONUS             2653 /* Sonus */
#define NETIO_UDP_PORT_COREL_VNCADMIN    2654 /* "Corel VNC Admin */
#define NETIO_UDP_PORT_UNGLUE            2655 /* UNIX Nt Glue */
#define NETIO_UDP_PORT_KANA              2656 /* Kana */
#define NETIO_UDP_PORT_SNS_DISPATCHER    2657 /* SNS Dispatcher */
#define NETIO_UDP_PORT_SNS_ADMIN         2658 /* SNS Admin */
#define NETIO_UDP_PORT_SNS_QUERY         2659 /* SNS Query */
#define NETIO_UDP_PORT_GCMONITOR         2660 /* GC Monitor */
#define NETIO_UDP_PORT_OLHOST            2661 /* OLHOST */
#define NETIO_UDP_PORT_BINTEC_CAPI       2662 /* BinTec-CAPI */
#define NETIO_UDP_PORT_BINTEC_TAPI       2663 /* BinTec-TAPI */
#define NETIO_UDP_PORT_PATROL_MQ_GM      2664 /* Patrol for MQ GM */
#define NETIO_UDP_PORT_PATROL_MQ_NM      2665 /* Patrol for MQ NM */
#define NETIO_UDP_PORT_EXTENSIS          2666 /* extensis */
#define NETIO_UDP_PORT_ALARM_CLOCK_S     2667 /* Alarm Clock Server */
#define NETIO_UDP_PORT_ALARM_CLOCK_C     2668 /* Alarm Clock Client */
#define NETIO_UDP_PORT_TOAD              2669 /* TOAD */
#define NETIO_UDP_PORT_TVE_ANNOUNCE      2670 /* TVE Announce */
#define NETIO_UDP_PORT_NEWLIXREG         2671 /* newlixreg */
#define NETIO_UDP_PORT_NHSERVER          2672 /* nhserver */
#define NETIO_UDP_PORT_FIRSTCALL42       2673 /* First Call 42 */
#define NETIO_UDP_PORT_EWNN              2674 /* ewnn */
#define NETIO_UDP_PORT_TTC_ETAP          2675 /* TTC ETAP */
#define NETIO_UDP_PORT_SIMSLINK          2676 /* SIMSLink */
#define NETIO_UDP_PORT_GADGETGATE1WAY    2677 /* Gadget Gate 1 Way */
#define NETIO_UDP_PORT_GADGETGATE2WAY    2678 /* Gadget Gate 2 Way */
#define NETIO_UDP_PORT_SYNCSERVERSSL     2679 /* Sync Server SSL */
#define NETIO_UDP_PORT_PXC_SAPXOM        2680 /* pxc-sapxom */
#define NETIO_UDP_PORT_MPNJSOMB          2681 /* mpnjsomb */
#define NETIO_UDP_PORT_NCDLOADBALANCE    2683 /* NCDLoadBalance */
#define NETIO_UDP_PORT_MPNJSOSV          2684 /* mpnjsosv */
#define NETIO_UDP_PORT_MPNJSOCL          2685 /* mpnjsocl */
#define NETIO_UDP_PORT_MPNJSOMG          2686 /* mpnjsomg */
#define NETIO_UDP_PORT_PQ_LIC_MGMT       2687 /* pq-lic-mgmt */
#define NETIO_UDP_PORT_MD_CG_HTTP        2688 /* md-cf-http */
#define NETIO_UDP_PORT_FASTLYNX          2689 /* FastLynx */
#define NETIO_UDP_PORT_HP_NNM_DATA       2690 /* HP NNM Embedded Database */
#define NETIO_UDP_PORT_ITINTERNET        2691 /* ITInternet ISM Server */
#define NETIO_UDP_PORT_ADMINS_LMS        2692 /* Admins LMS */
#define NETIO_UDP_PORT_PWRSEVENT         2694 /* pwrsevent */
#define NETIO_UDP_PORT_VSPREAD           2695 /* VSPREAD */
#define NETIO_UDP_PORT_UNIFYADMIN        2696 /* Unify Admin */
#define NETIO_UDP_PORT_OCE_SNMP_TRAP     2697 /* Oce SNMP Trap Port */
#define NETIO_UDP_PORT_MCK_IVPIP         2698 /* MCK-IVPIP */
#define NETIO_UDP_PORT_CSOFT_PLUSCLNT    2699 /* Csoft Plus Client */
#define NETIO_UDP_PORT_TQDATA            2700 /* tqdata */
#define NETIO_UDP_PORT_SMS_RCINFO        2701 /* SMS RCINFO */
#define NETIO_UDP_PORT_SMS_XFER          2702 /* SMS XFER */
#define NETIO_UDP_PORT_SMS_CHAT          2703 /* SMS CHAT */
#define NETIO_UDP_PORT_SMS_REMCTRL       2704 /* SMS REMCTRL */
#define NETIO_UDP_PORT_SDS_ADMIN         2705 /* SDS Admin */
#define NETIO_UDP_PORT_NCDMIRRORING      2706 /* NCD Mirroring */
#define NETIO_UDP_PORT_EMCSYMAPIPORT     2707 /* EMCSYMAPIPORT */
#define NETIO_UDP_PORT_BANYAN_NET        2708 /* Banyan-Net */
#define NETIO_UDP_PORT_SUPERMON          2709 /* Supermon */
#define NETIO_UDP_PORT_SSO_SERVICE       2710 /* SSO Service */
#define NETIO_UDP_PORT_SSO_CONTROL       2711 /* SSO Control */
#define NETIO_UDP_PORT_AOCP              2712 /* Axapta Object Communication Protocol */
#define NETIO_UDP_PORT_RAVENTBS          2713 /* Raven Trinity Broker Service */
#define NETIO_UDP_PORT_RAVENTDM          2714 /* Raven Trinity Data Mover */
#define NETIO_UDP_PORT_HPSTGMGR2         2715 /* HPSTGMGR2 */
#define NETIO_UDP_PORT_INOVA_IP_DISCO    2716 /* Inova IP Disco */
#define NETIO_UDP_PORT_PN_REQUESTER      2717 /* PN REQUESTER */
#define NETIO_UDP_PORT_PN_REQUESTER2     2718 /* PN REQUESTER 2 */
#define NETIO_UDP_PORT_SCAN_CHANGE       2719 /* Scan & Change */
#define NETIO_UDP_PORT_WKARS             2720 /* wkars */
#define NETIO_UDP_PORT_SMART_DIAGNOSE    2721 /* Smart Diagnose */
#define NETIO_UDP_PORT_PROACTIVESRVR     2722 /* Proactive Server */
#define NETIO_UDP_PORT_WATCHDOG_NT       2723 /* WatchDog NT Protocol */
#define NETIO_UDP_PORT_QOTPS             2724 /* qotps */
#define NETIO_UDP_PORT_MSOLAP_PTP2       2725 /* MSOLAP PTP2 */
#define NETIO_UDP_PORT_TAMS              2726 /* TAMS */
#define NETIO_UDP_PORT_MGCP_CALLAGENT    2727 /* Media Gateway Control Protocol Call Agent */
#define NETIO_UDP_PORT_SQDR              2728 /* SQDR */
#define NETIO_UDP_PORT_TCIM_CONTROL      2729 /* TCIM Control */
#define NETIO_UDP_PORT_NEC_RAIDPLUS      2730 /* NEC RaidPlus */
#define NETIO_UDP_PORT_FYRE_MESSANGER    2731 /* Fyre Messagner */
#define NETIO_UDP_PORT_G5M               2732 /* G5M */
#define NETIO_UDP_PORT_SIGNET_CTF        2733 /* Signet CTF */
#define NETIO_UDP_PORT_CCS_SOFTWARE      2734 /* CCS Software */
#define NETIO_UDP_PORT_NETIQ_MC          2735 /* NetIQ Monitor Console */
#define NETIO_UDP_PORT_RADWIZ_NMS_SRV    2736 /* RADWIZ NMS SRV */
#define NETIO_UDP_PORT_SRP_FEEDBACK      2737 /* SRP Feedback */
#define NETIO_UDP_PORT_NDL_TCP_OIS_GW    2738 /* NDL TCP-OSI Gateway */
#define NETIO_UDP_PORT_TN_TIMING         2739 /* TN Timing */
#define NETIO_UDP_PORT_ALARM             2740 /* Alarm */
#define NETIO_UDP_PORT_TSB               2741 /* TSB */
#define NETIO_UDP_PORT_TSB2              2742 /* TSB2 */
#define NETIO_UDP_PORT_MURX              2743 /* murx */
#define NETIO_UDP_PORT_HONYAKU           2744 /* honyaku */
#define NETIO_UDP_PORT_URBISNET          2745 /* URBISNET */
#define NETIO_UDP_PORT_CPUDPENCAP        2746 /* CPUDPENCAP */
#define NETIO_UDP_PORT_RSISYSACCESS      2752 /* RSISYS ACCESS */
#define NETIO_UDP_PORT_DE_SPOT           2753 /* de-spot */
#define NETIO_UDP_PORT_APOLLO_CC         2754 /* APOLLO CC */
#define NETIO_UDP_PORT_EXPRESSPAY        2755 /* Express Pay */
#define NETIO_UDP_PORT_SIMPLEMENT_TIE    2756 /* simplement-tie */
#define NETIO_UDP_PORT_CNRP              2757 /* CNRP */
#define NETIO_UDP_PORT_APOLLO_STATUS     2758 /* APOLLO Status */
#define NETIO_UDP_PORT_APOLLO_GMS        2759 /* APOLLO GMS */
#define NETIO_UDP_PORT_SABAMS            2760 /* Saba MS */
#define NETIO_UDP_PORT_DICOM_ISCL        2761 /* DICOM ISCL */
#define NETIO_UDP_PORT_DICOM_TLS         2762 /* DICOM TLS */
#define NETIO_UDP_PORT_DESKTOP_DNA       2763 /* Desktop DNA */
#define NETIO_UDP_PORT_DATA_INSURANCE    2764 /* Data Insurance */
#define NETIO_UDP_PORT_QIP_AUDUP         2765 /* qip-audup */
#define NETIO_UDP_PORT_COMPAQ_SCP        2766 /* Compaq SCP */
#define NETIO_UDP_PORT_UADTC             2767 /* UADTC */
#define NETIO_UDP_PORT_UACS              2768 /* UACS */
#define NETIO_UDP_PORT_EXCE              2769 /* eXcE */
#define NETIO_UDP_PORT_VERONICA          2770 /* Veronica */
#define NETIO_UDP_PORT_VERGENCECM        2771 /* Vergence CM */
#define NETIO_UDP_PORT_AURIS             2772 /* auris */
#define NETIO_UDP_PORT_RBAKCUP1          2773 /* RBackup Remote Backup */
#define NETIO_UDP_PORT_RBAKCUP2          2774 /* RBackup Remote Backup */
#define NETIO_UDP_PORT_SMPP              2775 /* SMPP */
#define NETIO_UDP_PORT_RIDGEWAY1         2776 /* Ridgeway Systems & Software */
#define NETIO_UDP_PORT_RIDGEWAY2         2777 /* Ridgeway Systems & Software */
#define NETIO_UDP_PORT_GWEN_SONYA        2778 /* Gwen-Sonya */
#define NETIO_UDP_PORT_LBC_SYNC          2779 /* LBC Sync */
#define NETIO_UDP_PORT_LBC_CONTROL       2780 /* LBC Control */
#define NETIO_UDP_PORT_WHOSELLS          2781 /* whosells */
#define NETIO_UDP_PORT_EVERYDAYRC        2782 /* everydayrc */
#define NETIO_UDP_PORT_AISES             2783 /* AISES */
#define NETIO_UDP_PORT_WWW_DEV           2784 /* world wide web - development */
#define NETIO_UDP_PORT_AIC_NP            2785 /* aic-np */
#define NETIO_UDP_PORT_AIC_ONCRPC        2786 /* aic-oncrpc - Destiny MCD database */
#define NETIO_UDP_PORT_PICCOLO           2787 /* piccolo - Cornerstone Software */
#define NETIO_UDP_PORT_FRYESERV          2788 /* NetWare Loadable Module - Seagate Software */
#define NETIO_UDP_PORT_MEDIA_AGENT       2789 /* Media Agent */
#define NETIO_UDP_PORT_PLGPROXY          2790 /* PLG Proxy */
#define NETIO_UDP_PORT_MTPORT_REGIST     2791 /* MT Port Registrator */
#define NETIO_UDP_PORT_F5_GLOBALSITE     2792 /* f5-globalsite */
#define NETIO_UDP_PORT_INITLSMSAD        2793 /* initlsmsad */
#define NETIO_UDP_PORT_LIVESTATS         2795 /* LiveStats */
#define NETIO_UDP_PORT_AC_TECH           2796 /* ac-tech */
#define NETIO_UDP_PORT_ESP_ENCAP         2797 /* esp-encap */
#define NETIO_UDP_PORT_TMESIS_UPSHOT     2798 /* TMESIS-UPShot */
#define NETIO_UDP_PORT_ICON_DISCOVER     2799 /* ICON Discover */
#define NETIO_UDP_PORT_ACC_RAID          2800 /* ACC RAID */
#define NETIO_UDP_PORT_IGCP              2801 /* IGCP */
#define NETIO_UDP_PORT_VERITAS_UDP1      2802 /* Veritas UDP1 */
#define NETIO_UDP_PORT_BTPRJCTRL         2803 /* btprjctrl */
#define NETIO_UDP_PORT_DVR_ESM           2804 /* March Networks Digital Video Recorders and Enterprise Service Manager products */
#define NETIO_UDP_PORT_WTA_WSP_S         2805 /* WTA WSP-S */
#define NETIO_UDP_PORT_CSPUNI            2806 /* cspuni */
#define NETIO_UDP_PORT_CSPMULTI          2807 /* cspmulti */
#define NETIO_UDP_PORT_J_LAN_P           2808 /* J-LAN-P */
#define NETIO_UDP_PORT_CORBALOC          2809 /* CORBA LOC */
#define NETIO_UDP_PORT_NETSTEWARD        2810 /* Active Net Steward */
#define NETIO_UDP_PORT_GSIFTP            2811 /* GSI FTP */
#define NETIO_UDP_PORT_ATMTCP            2812 /* atmtcp */
#define NETIO_UDP_PORT_LLM_PASS          2813 /* llm-pass */
#define NETIO_UDP_PORT_LLM_CSV           2814 /* llm-csv */
#define NETIO_UDP_PORT_LBC_MEASURE       2815 /* LBC Measurement */
#define NETIO_UDP_PORT_LBC_WATCHDOG      2816 /* LBC Watchdog */
#define NETIO_UDP_PORT_NMSIGPORT         2817 /* NMSig Port */
#define NETIO_UDP_PORT_RMLNK             2818 /* rmlnk */
#define NETIO_UDP_PORT_FC_FAULTNOTIFY    2819 /* FC Fault Notification */
#define NETIO_UDP_PORT_UNIVISION         2820 /* UniVision */
#define NETIO_UDP_PORT_VRTS_AT_PORT      2821 /* VERITAS Authentication Service */
#define NETIO_UDP_PORT_KA0WUC            2822 /* ka0wuc */
#define NETIO_UDP_PORT_CQG_NETLAN        2823 /* CQG Net/LAN */
#define NETIO_UDP_PORT_CQG_NETLAN_1      2824 /* CQG Net/Lan 1 */
#define NETIO_UDP_PORT_SLC_SYSTEMLOG     2826 /* slc systemlog */
#define NETIO_UDP_PORT_SLC_CTRLRLOOPS    2827 /* slc ctrlrloops */
#define NETIO_UDP_PORT_ITM_LM            2828 /* ITM License Manager */
#define NETIO_UDP_PORT_SILKP1            2829 /* silkp1 */
#define NETIO_UDP_PORT_SILKP2            2830 /* silkp2 */
#define NETIO_UDP_PORT_SILKP3            2831 /* silkp3 */
#define NETIO_UDP_PORT_SILKP4            2832 /* silkp4 */
#define NETIO_UDP_PORT_GLISHD            2833 /* glishd */
#define NETIO_UDP_PORT_EVTP              2834 /* EVTP */
#define NETIO_UDP_PORT_EVTP_DATA         2835 /* EVTP-DATA */
#define NETIO_UDP_PORT_CATALYST          2836 /* catalyst */
#define NETIO_UDP_PORT_REPLIWEB          2837 /* Repliweb */
#define NETIO_UDP_PORT_STARBOT           2838 /* Starbot */
#define NETIO_UDP_PORT_NMSIGPORT2        2839 /* NMSigPort */
#define NETIO_UDP_PORT_L3_EXPRT          2840 /* l3-exprt */
#define NETIO_UDP_PORT_L3_RANGER         2841 /* l3-ranger */
#define NETIO_UDP_PORT_L3_HAWK           2842 /* l3-hawk */
#define NETIO_UDP_PORT_PDNET             2843 /* PDnet */
#define NETIO_UDP_PORT_BPCP_POLL         2844 /* BPCP POLL */
#define NETIO_UDP_PORT_BPCP_TRAP         2845 /* BPCP TRAP */
#define NETIO_UDP_PORT_AIMPP_HELLO       2846 /* AIMPP Hello */
#define NETIO_UDP_PORT_AIMPP_PORT_REQ    2847 /* AIMPP Port Req */
#define NETIO_UDP_PORT_AMT_BLC_PORT      2848 /* AMT-BLC-PORT */
#define NETIO_UDP_PORT_FXP2              2849 /* FXP */
#define NETIO_UDP_PORT_METACONSOLE       2850 /* MetaConsole */
#define NETIO_UDP_PORT_WEBEMSHTTP        2851 /* webemshttp */
#define NETIO_UDP_PORT_BEARS_01          2852 /* bears-01 */
#define NETIO_UDP_PORT_ISPIPES           2853 /* ISPipes */
#define NETIO_UDP_PORT_INFOMOVER         2854 /* InfoMover */
#define NETIO_UDP_PORT_CESDINV           2856 /* cesdinv */
#define NETIO_UDP_PORT_SIMCTLP           2857 /* SimCtIP */
#define NETIO_UDP_PORT_ECNP              2858 /* ECNP */
#define NETIO_UDP_PORT_ACTIVEMEMORY      2859 /* Active Memory */
#define NETIO_UDP_PORT_DIALPAD_VOICE1    2860 /* Dialpad Voice 1 */
#define NETIO_UDP_PORT_DIALPAD_VOICE2    2861 /* Dialpad Voice 2 */
#define NETIO_UDP_PORT_TTG_PROTOCOL      2862 /* TTG Protocol */
#define NETIO_UDP_PORT_SONARDATA         2863 /* Sonar Data */
#define NETIO_UDP_PORT_ASTROMED_MAIN     2864 /* main 5001 cmd */
#define NETIO_UDP_PORT_PIT_VPN           2865 /* pit-vpn */
#define NETIO_UDP_PORT_IWLISTENER        2866 /* iwlistener */
#define NETIO_UDP_PORT_ESPS_PORTAL       2867 /* esps-portal */
#define NETIO_UDP_PORT_NPEP_MESSAGING    2868 /* Norman Proprietaqry Events Protocol */
#define NETIO_UDP_PORT_ICSLAP            2869 /* ICSLAP */
#define NETIO_UDP_PORT_DAISHI            2870 /* daishi */
#define NETIO_UDP_PORT_MSI_SELECTPLAY    2871 /* MSI Select Play */
#define NETIO_UDP_PORT_RADIX             2872 /* RADIX */
#define NETIO_UDP_PORT_DXMESSAGEBASE1    2874 /* DX Message Base Transport Protocol */
#define NETIO_UDP_PORT_DXMESSAGEBASE2    2875 /* DX Message Base Transport Protocol */
#define NETIO_UDP_PORT_SPS_TUNNEL        2876 /* SPS Tunnel */
#define NETIO_UDP_PORT_BLUELANCE         2877 /* BLUELANCE */
#define NETIO_UDP_PORT_AAP               2878 /* AAP */
#define NETIO_UDP_PORT_UCENTRIC_DS       2879 /* ucentric-ds */
#define NETIO_UDP_PORT_SYNAPSE           2880 /* Synapse Transport */
#define NETIO_UDP_PORT_NDSP              2881 /* NDSP */
#define NETIO_UDP_PORT_NDTP              2882 /* NDTP */
#define NETIO_UDP_PORT_NDNP              2883 /* NDNP */
#define NETIO_UDP_PORT_FLASHMSG          2884 /* Flash Msg */
#define NETIO_UDP_PORT_TOPFLOW           2885 /* TopFlow */
#define NETIO_UDP_PORT_RESPONSELOGIC     2886 /* RESPONSELOGIC */
#define NETIO_UDP_PORT_AIRONETDDP        2887 /* aironet */
#define NETIO_UDP_PORT_SPCSDLOBBY        2888 /* SPCSDLOBBY */
#define NETIO_UDP_PORT_RSOM              2889 /* RSOM */
#define NETIO_UDP_PORT_CSPCLMULTI        2890 /* CSPCLMULTI */
#define NETIO_UDP_PORT_CINEGRFX_ELMD     2891 /* CINEGRFX-ELMD License Manager */
#define NETIO_UDP_PORT_SNIFFERDATA       2892 /* SNIFFERDATA */
#define NETIO_UDP_PORT_VSECONNECTOR      2893 /* VSECONNECTOR */
#define NETIO_UDP_PORT_ABACUS_REMOTE     2894 /* ABACUS-REMOTE */
#define NETIO_UDP_PORT_NATUSLINK         2895 /* NATUS LINK */
#define NETIO_UDP_PORT_ECOVISIONG6_1     2896 /* ECOVISIONG6-1 */
#define NETIO_UDP_PORT_CITRIX_RTMP       2897 /* Citrix RTMP */
#define NETIO_UDP_PORT_APPLIANCE_CFG     2898 /* APPLIANCE-CFG */
#define NETIO_UDP_PORT_POWERGEMPLUS      2899 /* POWERGEMPLUS */
#define NETIO_UDP_PORT_QUICKSUITE        2900 /* QUICKSUITE */
#define NETIO_UDP_PORT_ALLSTORCNS        2901 /* ALLSTORCNS */
#define NETIO_UDP_PORT_NETASPI           2902 /* NET ASPI */
#define NETIO_UDP_PORT_SUITCASE          2903 /* SUITCASE */
#define NETIO_UDP_PORT_M2UA              2904 /* M2UA */
#define NETIO_UDP_PORT_CALLER9           2906 /* CALLER9 */
#define NETIO_UDP_PORT_WEBMETHODS_B2B    2907 /* WEBMETHODS B2B */
#define NETIO_UDP_PORT_MAO               2908 /* mao */
#define NETIO_UDP_PORT_FUNK_DIALOUT      2909 /* Funk Dialout */
#define NETIO_UDP_PORT_TDACCESS          2910 /* TDAccess */
#define NETIO_UDP_PORT_BLOCKADE          2911 /* Blockade */
#define NETIO_UDP_PORT_EPICON            2912 /* Epicon */
#define NETIO_UDP_PORT_BOOSTERWARE       2913 /* Booster Ware */
#define NETIO_UDP_PORT_GAMELOBBY         2914 /* Game Lobby */
#define NETIO_UDP_PORT_TKSOCKET          2915 /* TK Socket */
#define NETIO_UDP_PORT_ELVIN_SERVER      2916 /* "Elvin Server */
#define NETIO_UDP_PORT_ELVIN_CLIENT      2917 /* "Elvin Client */
#define NETIO_UDP_PORT_KASTENCHASEPAD    2918 /* Kasten Chase Pad */
#define NETIO_UDP_PORT_ROBOER            2919 /* roboER */
#define NETIO_UDP_PORT_ROBOEDA           2920 /* roboEDA */
#define NETIO_UDP_PORT_CESDCDMAN         2921 /* CESD Contents Delivery Management */
#define NETIO_UDP_PORT_CESDCDTRN         2922 /* CESD Contents Delivery Data Transfer */
#define NETIO_UDP_PORT_WTA_WSP_WTP_S     2923 /* WTA-WSP-WTP-S */
#define NETIO_UDP_PORT_PRECISE_VIP       2924 /* PRECISE-VIP */
#define NETIO_UDP_PORT_MOBILE_FILE_DL    2926 /* MOBILE-FILE-DL */
#define NETIO_UDP_PORT_UNIMOBILECTRL     2927 /* UNIMOBILECTRL */
#define NETIO_UDP_PORT_REDSTONE_CPSS     2928 /* REDSTONE-CPSS */
#define NETIO_UDP_PORT_AMX_WEBADMIN      2929 /* AMX-WEBADMIN */
#define NETIO_UDP_PORT_AMX_WEBLINX       2930 /* AMX-WEBLINX */
#define NETIO_UDP_PORT_CIRCLE_X          2931 /* Circle-X */
#define NETIO_UDP_PORT_INCP              2932 /* INCP */
#define NETIO_UDP_PORT_4_TIEROPMGW       2933 /* 4-TIER OPM GW */
#define NETIO_UDP_PORT_4_TIEROPMCLI      2934 /* 4-TIER OPM CLI */
#define NETIO_UDP_PORT_QTP               2935 /* QTP */
#define NETIO_UDP_PORT_OTPATCH           2936 /* OTPatch */
#define NETIO_UDP_PORT_PNACONSULT_LM     2937 /* PNACONSULT-LM */
#define NETIO_UDP_PORT_SM_PAS_1          2938 /* SM-PAS-1 */
#define NETIO_UDP_PORT_SM_PAS_2          2939 /* SM-PAS-2 */
#define NETIO_UDP_PORT_SM_PAS_3          2940 /* SM-PAS-3 */
#define NETIO_UDP_PORT_SM_PAS_4          2941 /* SM-PAS-4 */
#define NETIO_UDP_PORT_SM_PAS_5          2942 /* SM-PAS-5 */
#define NETIO_UDP_PORT_TTNREPOSITORY     2943 /* TTNRepository */
#define NETIO_UDP_PORT_MEGACO_H248       2944 /* Megaco H-248 */
#define NETIO_UDP_PORT_H248_BINARY       2945 /* H248 Binary */
#define NETIO_UDP_PORT_FJSVMPOR          2946 /* FJSVmpor */
#define NETIO_UDP_PORT_GPSD              2947 /* GPS Daemon request/response protocol */
#define NETIO_UDP_PORT_WAP_PUSH          2948 /* WAP PUSH */
#define NETIO_UDP_PORT_WAP_PUSHSECURE    2949 /* WAP PUSH SECURE */
#define NETIO_UDP_PORT_ESIP              2950 /* ESIP */
#define NETIO_UDP_PORT_OTTP              2951 /* OTTP */
#define NETIO_UDP_PORT_MPFWSAS           2952 /* MPFWSAS */
#define NETIO_UDP_PORT_OVALARMSRV        2953 /* OVALARMSRV */
#define NETIO_UDP_PORT_OVALARMSRV_CMD    2954 /* OVALARMSRV-CMD */
#define NETIO_UDP_PORT_CSNOTIFY          2955 /* CSNOTIFY */
#define NETIO_UDP_PORT_OVRIMOSDBMAN      2956 /* OVRIMOSDBMAN */
#define NETIO_UDP_PORT_JMACT5            2957 /* JAMCT5 */
#define NETIO_UDP_PORT_JMACT6            2958 /* JAMCT6 */
#define NETIO_UDP_PORT_RMOPAGT           2959 /* RMOPAGT */
#define NETIO_UDP_PORT_DFOXSERVER        2960 /* DFOXSERVER */
#define NETIO_UDP_PORT_BOLDSOFT_LM       2961 /* BOLDSOFT-LM */
#define NETIO_UDP_PORT_IPH_POLICY_CLI    2962 /* IPH-POLICY-CLI */
#define NETIO_UDP_PORT_IPH_POLICY_ADM    2963 /* IPH-POLICY-ADM */
#define NETIO_UDP_PORT_BULLANT_SRAP      2964 /* BULLANT SRAP */
#define NETIO_UDP_PORT_BULLANT_RAP       2965 /* BULLANT RAP */
#define NETIO_UDP_PORT_IDP_INFOTRIEVE    2966 /* IDP-INFOTRIEVE */
#define NETIO_UDP_PORT_SSC_AGENT         2967 /* SSC-AGENT */
#define NETIO_UDP_PORT_ENPP              2968 /* ENPP */
#define NETIO_UDP_PORT_ESSP              2969 /* ESSP */
#define NETIO_UDP_PORT_INDEX_NET         2970 /* INDEX-NET */
#define NETIO_UDP_PORT_NETCLIP           2971 /* NetClip clipboard daemon */
#define NETIO_UDP_PORT_PMSM_WEBRCTL      2972 /* PMSM Webrctl */
#define NETIO_UDP_PORT_SVNETWORKS        2973 /* SV Networks */
#define NETIO_UDP_PORT_SIGNAL            2974 /* Signal */
#define NETIO_UDP_PORT_FJMPCM            2975 /* Fujitsu Configuration Management Service */
#define NETIO_UDP_PORT_CNS_SRV_PORT      2976 /* CNS Server Port */
#define NETIO_UDP_PORT_TTC_ETAP_NS       2977 /* TTCs Enterprise Test Access Protocol - NS */
#define NETIO_UDP_PORT_TTC_ETAP_DS       2978 /* TTCs Enterprise Test Access Protocol - DS */
#define NETIO_UDP_PORT_H263_VIDEO        2979 /* H.263 Video Streaming */
#define NETIO_UDP_PORT_WIMD              2980 /* Instant Messaging Service */
#define NETIO_UDP_PORT_MYLXAMPORT        2981 /* MYLXAMPORT */
#define NETIO_UDP_PORT_IWB_WHITEBOARD    2982 /* IWB-WHITEBOARD */
#define NETIO_UDP_PORT_NETPLAN           2983 /* NETPLAN */
#define NETIO_UDP_PORT_HPIDSADMIN        2984 /* HPIDSADMIN */
#define NETIO_UDP_PORT_HPIDSAGENT        2985 /* HPIDSAGENT */
#define NETIO_UDP_PORT_STONEFALLS        2986 /* STONEFALLS */
#define NETIO_UDP_PORT_IDENTIFY          2987 /* identify */
#define NETIO_UDP_PORT_HIPPAD            2988 /* HIPPA Reporting Protocol */
#define NETIO_UDP_PORT_ZARKOV            2989 /* ZARKOV Intelligent Agent Communication */
#define NETIO_UDP_PORT_BOSCAP            2990 /* BOSCAP */
#define NETIO_UDP_PORT_WKSTN_MON         2991 /* WKSTN-MON */
#define NETIO_UDP_PORT_AVENYO            2992 /* Avenyo Server */
#define NETIO_UDP_PORT_VERITAS_VIS1      2993 /* VERITAS VIS1 */
#define NETIO_UDP_PORT_VERITAS_VIS2      2994 /* VERITAS VIS2 */
#define NETIO_UDP_PORT_IDRS              2995 /* IDRS */
#define NETIO_UDP_PORT_VSIXML            2996 /* vsixml */
#define NETIO_UDP_PORT_REBOL             2997 /* REBOL */
#define NETIO_UDP_PORT_REALSECURE        2998 /* Real Secure */
#define NETIO_UDP_PORT_REMOTEWARE_UN     2999 /* RemoteWare Unassigned */
#define NETIO_UDP_PORT_HBCI              3000 /* HBCI */
#define NETIO_UDP_PORT_EXLM_AGENT        3002 /* EXLM Agent */
#define NETIO_UDP_PORT_CGMS              3003 /* CGMS */
#define NETIO_UDP_PORT_CSOFTRAGENT       3004 /* Csoft Agent */
#define NETIO_UDP_PORT_GENIUSLM          3005 /* Genius License Manager */
#define NETIO_UDP_PORT_II_ADMIN          3006 /* Instant Internet Admin */
#define NETIO_UDP_PORT_LOTUSMTAP         3007 /* Lotus Mail Tracking Agent Protocol */
#define NETIO_UDP_PORT_MIDNIGHT_TECH     3008 /* Midnight Technologies */
#define NETIO_UDP_PORT_PXC_NTFY          3009 /* PXC-NTFY */
#define NETIO_UDP_PORT_PING_PONG         3010 /* Telerate Workstation */
#define NETIO_UDP_PORT_TRUSTED_WEB       3011 /* Trusted Web */
#define NETIO_UDP_PORT_TWSDSS            3012 /* Trusted Web Client */
#define NETIO_UDP_PORT_GILATSKYSURFER    3013 /* Gilat Sky Surfer */
#define NETIO_UDP_PORT_BROKER_SERVICE    3014 /* "Broker Service */
#define NETIO_UDP_PORT_NATI_DSTP         3015 /* NATI DSTP */
#define NETIO_UDP_PORT_NOTIFY_SRVR       3016 /* "Notify Server */
#define NETIO_UDP_PORT_EVENT_LISTENER    3017 /* "Event Listener */
#define NETIO_UDP_PORT_SRVC_REGISTRY     3018 /* "Service Registry */
#define NETIO_UDP_PORT_RESOURCE_MGR      3019 /* "Resource Manager */
#define NETIO_UDP_PORT_CIFS              3020 /* CIFS */
#define NETIO_UDP_PORT_AGRISERVER        3021 /* AGRI Server */
#define NETIO_UDP_PORT_CSREGAGENT        3022 /* CSREGAGENT */
#define NETIO_UDP_PORT_MAGICNOTES        3023 /* magicnotes */
#define NETIO_UDP_PORT_NDS_SSO           3024 /* "NDS_SSO */
#define NETIO_UDP_PORT_AREPA_RAFT        3025 /* Arepa Raft */
#define NETIO_UDP_PORT_AGRI_GATEWAY      3026 /* AGRI Gateway */
#define NETIO_UDP_PORT_LIEBDEVMGMT_C     3027 /* "LiebDevMgmt_C */
#define NETIO_UDP_PORT_LIEBDEVMGMT_DM    3028 /* "LiebDevMgmt_DM */
#define NETIO_UDP_PORT_LIEBDEVMGMT_A     3029 /* "LiebDevMgmt_A */
#define NETIO_UDP_PORT_AREPA_CAS         3030 /* Arepa Cas */
#define NETIO_UDP_PORT_EPPC              3031 /* Remote AppleEvents/PPC Toolbox */
#define NETIO_UDP_PORT_REDWOOD_CHAT      3032 /* Redwood Chat */
#define NETIO_UDP_PORT_PDB               3033 /* PDB */
#define NETIO_UDP_PORT_OSMOSIS_AEEA      3034 /* Osmosis / Helix (R) AEEA Port */
#define NETIO_UDP_PORT_FJSV_GSSAGT       3035 /* FJSV gssagt */
#define NETIO_UDP_PORT_HAGEL_DUMP        3036 /* Hagel DUMP */
#define NETIO_UDP_PORT_HP_SAN_MGMT       3037 /* HP SAN Mgmt */
#define NETIO_UDP_PORT_SANTAK_UPS        3038 /* Santak UPS */
#define NETIO_UDP_PORT_COGITATE          3039 /* "Cogitate */
#define NETIO_UDP_PORT_TOMATO_SPRINGS    3040 /* Tomato Springs */
#define NETIO_UDP_PORT_DI_TRACEWARE      3041 /* di-traceware */
#define NETIO_UDP_PORT_JOURNEE           3042 /* journee */
#define NETIO_UDP_PORT_BRP               3043 /* Broadcast Routing Protocol */
#define NETIO_UDP_PORT_EPP2              3044 /* EndPoint Protocol */
#define NETIO_UDP_PORT_RESPONSENET       3045 /* ResponseNet */
#define NETIO_UDP_PORT_DI_ASE            3046 /* di-ase */
#define NETIO_UDP_PORT_HLSERVER          3047 /* Fast Security HL Server */
#define NETIO_UDP_PORT_PCTRADER          3048 /* Sierra Net PC Trader */
#define NETIO_UDP_PORT_NSWS              3049 /* NSWS */
#define NETIO_UDP_PORT_GDS_DB            3050 /* "gds_db */
#define NETIO_UDP_PORT_GALAXY_SERVER     3051 /* Galaxy Server */
#define NETIO_UDP_PORT_APC_3052          3052 /* APC 3052 */
#define NETIO_UDP_PORT_DSOM_SERVER       3053 /* dsom-server */
#define NETIO_UDP_PORT_AMT_CNF_PROT      3054 /* AMT CNF PROT */
#define NETIO_UDP_PORT_POLICYSERVER      3055 /* Policy Server */
#define NETIO_UDP_PORT_CDL_SERVER        3056 /* CDL Server */
#define NETIO_UDP_PORT_GOAHEAD_FLDUP     3057 /* GoAhead FldUp */
#define NETIO_UDP_PORT_VIDEOBEANS        3058 /* videobeans */
#define NETIO_UDP_PORT_QSOFT             3059 /* qsoft */
#define NETIO_UDP_PORT_INTERSERVER       3060 /* interserver */
#define NETIO_UDP_PORT_CAUTCPD           3061 /* cautcpd */
#define NETIO_UDP_PORT_NCACN_IP_TCP      3062 /* ncacn-ip-tcp */
#define NETIO_UDP_PORT_NCADG_IP_UDP      3063 /* ncadg-ip-udp */
#define NETIO_UDP_PORT_RPRT              3064 /* Remote Port Redirector */
#define NETIO_UDP_PORT_SLINTERBASE       3065 /* slinterbase */
#define NETIO_UDP_PORT_NETATTACHSDMP     3066 /* NETATTACHSDMP */
#define NETIO_UDP_PORT_FJHPJP            3067 /* FJHPJP */
#define NETIO_UDP_PORT_LS3BCAST          3068 /* ls3 Broadcast */
#define NETIO_UDP_PORT_LS3               3069 /* ls3 */
#define NETIO_UDP_PORT_MGXSWITCH         3070 /* MGXSWITCH */
#define NETIO_UDP_PORT_CSD_MGMT_PORT     3071 /* ContinuStor Manager Port */
#define NETIO_UDP_PORT_CSD_MONITOR       3072 /* ContinuStor Monitor Port */
#define NETIO_UDP_PORT_VCRP              3073 /* Very simple chatroom prot */
#define NETIO_UDP_PORT_XBOX              3074 /* Xbox game port */
#define NETIO_UDP_PORT_ORBIX_LOCATOR     3075 /* Orbix 2000 Locator */
#define NETIO_UDP_PORT_ORBIX_CONFIG      3076 /* Orbix 2000 Config */
#define NETIO_UDP_PORT_ORBIX_LOC_SSL     3077 /* Orbix 2000 Locator SSL */
#define NETIO_UDP_PORT_ORBIX_CFG_SSL     3078 /* Orbix 2000 Locator SSL */
#define NETIO_UDP_PORT_LV_FRONTPANEL     3079 /* LV Front Panel */
#define NETIO_UDP_PORT_STM_PPROC         3080 /* "stm_pproc */
#define NETIO_UDP_PORT_TL1_LV            3081 /* TL1-LV */
#define NETIO_UDP_PORT_TL1_RAW           3082 /* TL1-RAW */
#define NETIO_UDP_PORT_TL1_TELNET        3083 /* TL1-TELNET */
#define NETIO_UDP_PORT_ITM_MCCS          3084 /* ITM-MCCS */
#define NETIO_UDP_PORT_PCIHREQ           3085 /* PCIHReq */
#define NETIO_UDP_PORT_JDL_DBKITCHEN     3086 /* JDL-DBKitchen */
#define NETIO_UDP_PORT_ASOKI_SMA         3087 /* Asoki SMA */
#define NETIO_UDP_PORT_XDTP              3088 /* eXtensible Data Transfer Protocol */
#define NETIO_UDP_PORT_PTK_ALINK         3089 /* ParaTek Agent Linking */
#define NETIO_UDP_PORT_STSS              3090 /* Senforce Session Services */
#define NETIO_UDP_PORT_1CI_SMCS          3091 /* 1Ci Server Management */
#define NETIO_UDP_PORT_RAPIDMQ_CENTER    3093 /* Jiiva RapidMQ Center */
#define NETIO_UDP_PORT_RAPIDMQ_REG       3094 /* Jiiva RapidMQ Registry */
#define NETIO_UDP_PORT_PANASAS           3095 /* Panasas rendevous port */
#define NETIO_UDP_PORT_NDL_APS           3096 /* Active Print Server Port */
#define NETIO_UDP_PORT_UMM_PORT          3098 /* Universal Message Manager */
#define NETIO_UDP_PORT_CHMD              3099 /* CHIPSY Machine Daemon */
#define NETIO_UDP_PORT_OPCON_XPS         3100 /* OpCon/xps */
#define NETIO_UDP_PORT_HP_PXPIB          3101 /* HP PolicyXpert PIB Server */
#define NETIO_UDP_PORT_SLSLAVEMON        3102 /* SoftlinK Slave Mon Port */
#define NETIO_UDP_PORT_AUTOCUESMI        3103 /* Autocue SMI Protocol */
#define NETIO_UDP_PORT_AUTOCUETIME       3104 /* Autocue Time Service */
#define NETIO_UDP_PORT_CARDBOX           3105 /* Cardbox */
#define NETIO_UDP_PORT_CARDBOX_HTTP      3106 /* Cardbox HTTP */
#define NETIO_UDP_PORT_BUSINESS          3107 /* Business protocol */
#define NETIO_UDP_PORT_GEOLOCATE         3108 /* Geolocate protocol */
#define NETIO_UDP_PORT_PERSONNEL         3109 /* Personnel protocol */
#define NETIO_UDP_PORT_SIM_CONTROL       3110 /* simulator control port */
#define NETIO_UDP_PORT_WSYNCH            3111 /* Web Synchronous Services */
#define NETIO_UDP_PORT_KSYSGUARD         3112 /* KDE System Guard */
#define NETIO_UDP_PORT_CS_AUTH_SVR       3113 /* CS-Authenticate Svr Port */
#define NETIO_UDP_PORT_CCMAD             3114 /* CCM AutoDiscover */
#define NETIO_UDP_PORT_MCTET_MASTER      3115 /* MCTET Master */
#define NETIO_UDP_PORT_MCTET_GATEWAY     3116 /* MCTET Gateway */
#define NETIO_UDP_PORT_MCTET_JSERV       3117 /* MCTET Jserv */
#define NETIO_UDP_PORT_PKAGENT           3118 /* PKAgent */
#define NETIO_UDP_PORT_D2000KERNEL       3119 /* D2000 Kernel Port */
#define NETIO_UDP_PORT_D2000WEBSERVER    3120 /* D2000 Webserver Port */
#define NETIO_UDP_PORT_VTR_EMULATOR      3122 /* MTI VTR Emulator port */
#define NETIO_UDP_PORT_EDIX              3123 /* EDI Translation Protocol */
#define NETIO_UDP_PORT_BEACON_PORT       3124 /* Beacon Port */
#define NETIO_UDP_PORT_A13_AN            3125 /* A13-AN Interface */
#define NETIO_UDP_PORT_CTX_BRIDGE        3127 /* CTX Bridge Port */
#define NETIO_UDP_PORT_NDL_AAS           3128 /* Active API Server Port */
#define NETIO_UDP_PORT_NETPORT_ID        3129 /* NetPort Discovery Port */
#define NETIO_UDP_PORT_ICPV2             3130 /* ICPv2 */
#define NETIO_UDP_PORT_NETBOOKMARK       3131 /* Net Book Mark */
#define NETIO_UDP_PORT_MS_RULE_ENGINE    3132 /* Microsoft Business Rule Engine Update Service */
#define NETIO_UDP_PORT_PRISM_DEPLOY      3133 /* Prism Deploy User Port */
#define NETIO_UDP_PORT_ECP               3134 /* Extensible Code Protocol */
#define NETIO_UDP_PORT_PEERBOOK_PORT     3135 /* PeerBook Port */
#define NETIO_UDP_PORT_GRUBD             3136 /* Grub Server Port */
#define NETIO_UDP_PORT_RTNT_1            3137 /* rtnt-1 data packets */
#define NETIO_UDP_PORT_RTNT_2            3138 /* rtnt-2 data packets */
#define NETIO_UDP_PORT_INCOGNITORV       3139 /* Incognito Rendez-Vous */
#define NETIO_UDP_PORT_ARILIAMULTI       3140 /* Arilia Multiplexor */
#define NETIO_UDP_PORT_VMODEM            3141 /* VMODEM */
#define NETIO_UDP_PORT_RDC_WH_EOS        3142 /* RDC WH EOS */
#define NETIO_UDP_PORT_SEAVIEW           3143 /* Sea View */
#define NETIO_UDP_PORT_TARANTELLA        3144 /* Tarantella */
#define NETIO_UDP_PORT_CSI_LFAP          3145 /* CSI-LFAP */
#define NETIO_UDP_PORT_BEARS_02          3146 /* bears-02 */
#define NETIO_UDP_PORT_RFIO              3147 /* RFIO */
#define NETIO_UDP_PORT_NM_GAME_ADMIN     3148 /* NetMike Game Administrator */
#define NETIO_UDP_PORT_NM_GAME_SERVER    3149 /* NetMike Game Server */
#define NETIO_UDP_PORT_NM_ASSES_ADMIN    3150 /* NetMike Assessor Administrator */
#define NETIO_UDP_PORT_NM_ASSESSOR       3151 /* NetMike Assessor */
#define NETIO_UDP_PORT_FEITIANROCKEY     3152 /* FeiTian Port */
#define NETIO_UDP_PORT_S8_CLIENT_PORT    3153 /* S8Cargo Client Port */
#define NETIO_UDP_PORT_CCMRMI            3154 /* ON RMI Registry */
#define NETIO_UDP_PORT_JPEGMPEG          3155 /* JpegMpeg Port */
#define NETIO_UDP_PORT_INDURA            3156 /* Indura Collector */
#define NETIO_UDP_PORT_E3CONSULTANTS     3157 /* CCC Listener Port */
#define NETIO_UDP_PORT_STVP              3158 /* SmashTV Protocol */
#define NETIO_UDP_PORT_NAVEGAWEB_PORT    3159 /* NavegaWeb Tarification */
#define NETIO_UDP_PORT_TIP_APP_SERVER    3160 /* TIP Application Server */
#define NETIO_UDP_PORT_DOC1LM            3161 /* DOC1 License Manager */
#define NETIO_UDP_PORT_SFLM              3162 /* SFLM */
#define NETIO_UDP_PORT_RES_SAP           3163 /* RES-SAP */
#define NETIO_UDP_PORT_IMPRS             3164 /* IMPRS */
#define NETIO_UDP_PORT_NEWGENPAY         3165 /* Newgenpay Engine Service */
#define NETIO_UDP_PORT_SOSSECOLLECTOR    3166 /* Quest Spotlight Out-Of-Process Collector */
#define NETIO_UDP_PORT_NOWCONTACT        3167 /* Now Contact Public Server */
#define NETIO_UDP_PORT_POWERONNUD        3168 /* Now Up-to-Date Public Server */
#define NETIO_UDP_PORT_SERVERVIEW_AS     3169 /* SERVERVIEW-AS */
#define NETIO_UDP_PORT_SERVERVIEW_ASN    3170 /* SERVERVIEW-ASN */
#define NETIO_UDP_PORT_SERVERVIEW_GF     3171 /* SERVERVIEW-GF */
#define NETIO_UDP_PORT_SERVERVIEW_RM     3172 /* SERVERVIEW-RM */
#define NETIO_UDP_PORT_SERVERVIEW_ICC    3173 /* SERVERVIEW-ICC */
#define NETIO_UDP_PORT_ARMI_SERVER       3174 /* ARMI Server */
#define NETIO_UDP_PORT_T1_E1_OVER_IP     3175 /* T1_E1_Over_IP */
#define NETIO_UDP_PORT_ARS_MASTER        3176 /* ARS Master */
#define NETIO_UDP_PORT_PHONEX_PORT       3177 /* Phonex Protocol */
#define NETIO_UDP_PORT_RADCLIENTPORT     3178 /* Radiance UltraEdge Port */
#define NETIO_UDP_PORT_H2GF_W_2M         3179 /* H2GF W.2m Handover prot. */
#define NETIO_UDP_PORT_MC_BRK_SRV        3180 /* Millicent Broker Server */
#define NETIO_UDP_PORT_BMCPATROLAGENT    3181 /* BMC Patrol Agent */
#define NETIO_UDP_PORT_BMCPATROLRNVU     3182 /* BMC Patrol Rendezvous */
#define NETIO_UDP_PORT_COPS_TLS          3183 /* COPS/TLS */
#define NETIO_UDP_PORT_APOGEEX_PORT      3184 /* ApogeeX Port */
#define NETIO_UDP_PORT_SMPPPD            3185 /* SuSE Meta PPPD */
#define NETIO_UDP_PORT_IIW_PORT          3186 /* IIW Monitor User Port */
#define NETIO_UDP_PORT_ODI_PORT          3187 /* Open Design Listen Port */
#define NETIO_UDP_PORT_BRCM_COMM_PORT    3188 /* Broadcom Port */
#define NETIO_UDP_PORT_PCLE_INFEX        3189 /* Pinnacle Sys InfEx Port */
#define NETIO_UDP_PORT_CSVR_PROXY        3190 /* ConServR Proxy */
#define NETIO_UDP_PORT_CSVR_SSLPROXY     3191 /* ConServR SSL Proxy */
#define NETIO_UDP_PORT_FIREMONRCC        3192 /* FireMon Revision Control */
#define NETIO_UDP_PORT_SPANDATAPORT      3193 /* SpanDataPort */
#define NETIO_UDP_PORT_MAGBIND           3194 /* Rockstorm MAG protocol */
#define NETIO_UDP_PORT_NCU_1             3195 /* Network Control Unit */
#define NETIO_UDP_PORT_NCU_2             3196 /* Network Control Unit */
#define NETIO_UDP_PORT_EMBRACE_DP_S      3197 /* Embrace Device Protocol Server */
#define NETIO_UDP_PORT_EMBRACE_DP_C      3198 /* Embrace Device Protocol Client */
#define NETIO_UDP_PORT_DMOD_WORKSPACE    3199 /* DMOD WorkSpace */
#define NETIO_UDP_PORT_TICK_PORT         3200 /* Press-sense Tick Port */
#define NETIO_UDP_PORT_CPQ_TASKSMART     3201 /* CPQ-TaskSmart */
#define NETIO_UDP_PORT_INTRAINTRA        3202 /* IntraIntra */
#define NETIO_UDP_PORT_NETWATCHER_MON    3203 /* Network Watcher Monitor */
#define NETIO_UDP_PORT_NETWATCHER_DB     3204 /* Network Watcher DB Access */
#define NETIO_UDP_PORT_ISNS              3205 /* iSNS Server Port */
#define NETIO_UDP_PORT_IRONMAIL          3206 /* IronMail POP Proxy */
#define NETIO_UDP_PORT_VX_AUTH_PORT      3207 /* Veritas Authentication Port */
#define NETIO_UDP_PORT_PFU_PRCALLBACK    3208 /* PFU PR Callback */
#define NETIO_UDP_PORT_NETWKPATHENGINE   3209 /* HP OpenView Network Path Engine Server */
#define NETIO_UDP_PORT_FLAMENCO_PROXY    3210 /* Flamenco Networks Proxy */
#define NETIO_UDP_PORT_AVSECUREMGMT      3211 /* Avocent Secure Management */
#define NETIO_UDP_PORT_SURVEYINST        3212 /* Survey Instrument */
#define NETIO_UDP_PORT_NEON24X7          3213 /* NEON 24X7 Mission Control */
#define NETIO_UDP_PORT_JMQ_DAEMON_1      3214 /* JMQ Daemon Port 1 */
#define NETIO_UDP_PORT_JMQ_DAEMON_2      3215 /* JMQ Daemon Port 2 */
#define NETIO_UDP_PORT_FERRARI_FOAM      3216 /* Ferrari electronic FOAM */
#define NETIO_UDP_PORT_UNITE             3217 /* Unified IP & Telecom Environment */
#define NETIO_UDP_PORT_SMARTPACKETS      3218 /* EMC SmartPackets */
#define NETIO_UDP_PORT_WMS_MESSENGER     3219 /* WMS Messenger */
#define NETIO_UDP_PORT_XNM_SSL           3220 /* XML NM over SSL */
#define NETIO_UDP_PORT_XNM_CLEAR_TEXT    3221 /* XML NM over TCP */
#define NETIO_UDP_PORT_GLBP              3222 /* Gateway Load Balancing Pr */
#define NETIO_UDP_PORT_DIGIVOTE          3223 /* DIGIVOTE (R) Vote-Server */
#define NETIO_UDP_PORT_AES_DISCOVERY     3224 /* AES Discovery Port */
#define NETIO_UDP_PORT_FCIP_PORT         3225 /* FCIP */
#define NETIO_UDP_PORT_ISI_IRP           3226 /* ISI Industry Software IRP */
#define NETIO_UDP_PORT_DWNMSHTTP         3227 /* DiamondWave NMS Server */
#define NETIO_UDP_PORT_DWMSGSERVER       3228 /* DiamondWave MSG Server */
#define NETIO_UDP_PORT_GLOBAL_CD_PORT    3229 /* Global CD Port */
#define NETIO_UDP_PORT_SFTDST_PORT       3230 /* Software Distributor Port */
#define NETIO_UDP_PORT_VIDIGO            3231 /* VidiGo communication (previous was: Delta Solutions Direct) */
#define NETIO_UDP_PORT_MDTP              3232 /* MDT port */
#define NETIO_UDP_PORT_WHISKER           3233 /* WhiskerControl main port */
#define NETIO_UDP_PORT_ALCHEMY           3234 /* Alchemy Server */
#define NETIO_UDP_PORT_MDAP_PORT         3235 /* MDAP Port */
#define NETIO_UDP_PORT_APPARENET_TS      3236 /* appareNet Test Server */
#define NETIO_UDP_PORT_APPARENET_TPS     3237 /* appareNet Test Packet Sequencer */
#define NETIO_UDP_PORT_APPARENET_AS      3238 /* appareNet Analysis Server */
#define NETIO_UDP_PORT_APPARENET_UI      3239 /* appareNet User Interface */
#define NETIO_UDP_PORT_TRIOMOTION        3240 /* Trio Motion Control Port */
#define NETIO_UDP_PORT_SYSORB            3241 /* SysOrb Monitoring Server */
#define NETIO_UDP_PORT_SDP_ID_PORT       3242 /* Session Description ID */
#define NETIO_UDP_PORT_TIMELOT           3243 /* Timelot Port */
#define NETIO_UDP_PORT_ONESAF            3244 /* OneSAF */
#define NETIO_UDP_PORT_VIEO_FE           3245 /* VIEO Fabric Executive */
#define NETIO_UDP_PORT_DVT_SYSTEM        3246 /* DVT SYSTEM PORT */
#define NETIO_UDP_PORT_DVT_DATA          3247 /* DVT DATA LINK */
#define NETIO_UDP_PORT_PROCOS_LM         3248 /* PROCOS LM */
#define NETIO_UDP_PORT_SSP               3249 /* State Sync Protocol */
#define NETIO_UDP_PORT_HICP              3250 /* HMS hicp port */
#define NETIO_UDP_PORT_SYSSCANNER        3251 /* Sys Scanner */
#define NETIO_UDP_PORT_DHE               3252 /* DHE port */
#define NETIO_UDP_PORT_PDA_DATA          3253 /* PDA Data */
#define NETIO_UDP_PORT_PDA_SYS           3254 /* PDA System */
#define NETIO_UDP_PORT_SEMAPHORE         3255 /* Semaphore Connection Port */
#define NETIO_UDP_PORT_CPQRPM_AGENT      3256 /* Compaq RPM Agent Port */
#define NETIO_UDP_PORT_CPQRPM_SERVER     3257 /* Compaq RPM Server Port */
#define NETIO_UDP_PORT_IVECON_PORT       3258 /* Ivecon Server Port */
#define NETIO_UDP_PORT_EPNCDP2           3259 /* Epson Network Common Devi */
#define NETIO_UDP_PORT_ISCSI_TARGET      3260 /* iSCSI port */
#define NETIO_UDP_PORT_WINSHADOW         3261 /* winShadow */
#define NETIO_UDP_PORT_NECP              3262 /* NECP */
#define NETIO_UDP_PORT_ECOLOR_IMAGER     3263 /* E-Color Enterprise Imager */
#define NETIO_UDP_PORT_CCMAIL            3264 /* cc:mail/lotus */
#define NETIO_UDP_PORT_ALTAV_TUNNEL      3265 /* Altav Tunnel */
#define NETIO_UDP_PORT_NS_CFG_SERVER     3266 /* NS CFG Server */
#define NETIO_UDP_PORT_IBM_DIAL_OUT      3267 /* IBM Dial Out */
#define NETIO_UDP_PORT_MSFT_GC           3268 /* Microsoft Global Catalog */
#define NETIO_UDP_PORT_MSFT_GC_SSL       3269 /* Microsoft Global Catalog with LDAP/SSL */
#define NETIO_UDP_PORT_VERISMART         3270 /* Verismart */
#define NETIO_UDP_PORT_CSOFT_PREV        3271 /* CSoft Prev Port */
#define NETIO_UDP_PORT_USER_MANAGER      3272 /* Fujitsu User Manager */
#define NETIO_UDP_PORT_SXMP              3273 /* Simple Extensible Multiplexed Protocol */
#define NETIO_UDP_PORT_ORDINOX_SERVER    3274 /* Ordinox Server */
#define NETIO_UDP_PORT_SAMD              3275 /* SAMD */
#define NETIO_UDP_PORT_MAXIM_ASICS       3276 /* Maxim ASICs */
#define NETIO_UDP_PORT_AWG_PROXY         3277 /* AWG Proxy */
#define NETIO_UDP_PORT_LKCMSERVER        3278 /* LKCM Server */
#define NETIO_UDP_PORT_ADMIND            3279 /* admind */
#define NETIO_UDP_PORT_VS_SERVER         3280 /* VS Server */
#define NETIO_UDP_PORT_SYSOPT            3281 /* SYSOPT */
#define NETIO_UDP_PORT_DATUSORB          3282 /* Datusorb */
#define NETIO_UDP_PORT_APPLE_REMOTE_DESKTOP 3283 /* Net Assistant */
#define NETIO_UDP_PORT_4TALK             3284 /* 4Talk */
#define NETIO_UDP_PORT_PLATO             3285 /* Plato */
#define NETIO_UDP_PORT_E_NET             3286 /* E-Net */
#define NETIO_UDP_PORT_DIRECTVDATA       3287 /* DIRECTVDATA */
#define NETIO_UDP_PORT_COPS              3288 /* COPS */
#define NETIO_UDP_PORT_ENPC              3289 /* ENPC */
#define NETIO_UDP_PORT_CAPS_LM           3290 /* CAPS LOGISTICS TOOLKIT - LM */
#define NETIO_UDP_PORT_SAH_LM            3291 /* S A Holditch & Associates - LM */
#define NETIO_UDP_PORT_CART_O_RAMA       3292 /* Cart O Rama */
#define NETIO_UDP_PORT_FG_FPS            3293 /* fg-fps */
#define NETIO_UDP_PORT_FG_GIP            3294 /* fg-gip */
#define NETIO_UDP_PORT_DYNIPLOOKUP       3295 /* Dynamic IP Lookup */
#define NETIO_UDP_PORT_RIB_SLM           3296 /* Rib License Manager */
#define NETIO_UDP_PORT_CYTEL_LM          3297 /* Cytel License Manager */
#define NETIO_UDP_PORT_DESKVIEW          3298 /* DeskView */
#define NETIO_UDP_PORT_PDRNCS            3299 /* pdrncs */
#define NETIO_UDP_PORT_MCS_FASTMAIL      3302 /* MCS Fastmail */
#define NETIO_UDP_PORT_OPSESSION_CLNT    3303 /* OP Session Client */
#define NETIO_UDP_PORT_OPSESSION_SRVR    3304 /* OP Session Server */
#define NETIO_UDP_PORT_ODETTE_FTP        3305 /* ODETTE-FTP */
#define NETIO_UDP_PORT_MYSQL             3306 /* MySQL */
#define NETIO_UDP_PORT_OPSESSION_PRXY    3307 /* OP Session Proxy */
#define NETIO_UDP_PORT_TNS_SERVER        3308 /* TNS Server */
#define NETIO_UDP_PORT_TNS_ADV           3309 /* TNS ADV */
#define NETIO_UDP_PORT_DYNA_ACCESS       3310 /* Dyna Access */
#define NETIO_UDP_PORT_MCNS_TEL_RET      3311 /* MCNS Tel Ret */
#define NETIO_UDP_PORT_APPMAN_SERVER     3312 /* Application Management Server */
#define NETIO_UDP_PORT_UORB              3313 /* Unify Object Broker */
#define NETIO_UDP_PORT_UOHOST            3314 /* Unify Object Host */
#define NETIO_UDP_PORT_CDID              3315 /* CDID */
#define NETIO_UDP_PORT_AICC_CMI          3316 /* AICC/CMI */
#define NETIO_UDP_PORT_VSAIPORT          3317 /* VSAI PORT */
#define NETIO_UDP_PORT_SSRIP             3318 /* Swith to Swith Routing Information Protocol */
#define NETIO_UDP_PORT_SDT_LMD           3319 /* SDT License Manager */
#define NETIO_UDP_PORT_OFFICELINK2000    3320 /* Office Link 2000 */
#define NETIO_UDP_PORT_VNSSTR            3321 /* VNSSTR */
#define NETIO_UDP_PORT_SFTU              3326 /* SFTU */
#define NETIO_UDP_PORT_BBARS             3327 /* BBARS */
#define NETIO_UDP_PORT_EGPTLM            3328 /* Eaglepoint License Manager */
#define NETIO_UDP_PORT_HP_DEVICE_DISC    3329 /* HP Device Disc */
#define NETIO_UDP_PORT_MCS_CALYPSOICF    3330 /* MCS Calypso ICF */
#define NETIO_UDP_PORT_MCS_MESSAGING     3331 /* MCS Messaging */
#define NETIO_UDP_PORT_MCS_MAILSVR       3332 /* MCS Mail Server */
#define NETIO_UDP_PORT_DEC_NOTES         3333 /* DEC Notes */
#define NETIO_UDP_PORT_DIRECTV_WEB       3334 /* Direct TV Webcasting */
#define NETIO_UDP_PORT_DIRECTV_SOFT      3335 /* Direct TV Software Updates */
#define NETIO_UDP_PORT_DIRECTV_TICK      3336 /* Direct TV Tickers */
#define NETIO_UDP_PORT_DIRECTV_CATLG     3337 /* Direct TV Data Catalog */
#define NETIO_UDP_PORT_ANET_B            3338 /* OMF data b */
#define NETIO_UDP_PORT_ANET_L            3339 /* OMF data l */
#define NETIO_UDP_PORT_ANET_M            3340 /* OMF data m */
#define NETIO_UDP_PORT_ANET_H            3341 /* OMF data h */
#define NETIO_UDP_PORT_WEBTIE            3342 /* WebTIE */
#define NETIO_UDP_PORT_MS_CLUSTER_NET    3343 /* MS Cluster Net */
#define NETIO_UDP_PORT_BNT_MANAGER       3344 /* BNT Manager */
#define NETIO_UDP_PORT_INFLUENCE         3345 /* Influence */
#define NETIO_UDP_PORT_TRNSPRNTPROXY     3346 /* Trnsprnt Proxy */
#define NETIO_UDP_PORT_PHOENIX_RPC       3347 /* Phoenix RPC */
#define NETIO_UDP_PORT_PANGOLIN_LASER    3348 /* Pangolin Laser */
#define NETIO_UDP_PORT_CHEVINSERVICES    3349 /* Chevin Services */
#define NETIO_UDP_PORT_FINDVIATV         3350 /* FINDVIATV */
#define NETIO_UDP_PORT_BTRIEVE           3351 /* Btrieve port */
#define NETIO_UDP_PORT_SSQL              3352 /* Scalable SQL */
#define NETIO_UDP_PORT_FATPIPE           3353 /* FATPIPE */
#define NETIO_UDP_PORT_SUITJD            3354 /* SUITJD */
#define NETIO_UDP_PORT_ORDINOX_DBASE     3355 /* Ordinox Dbase */
#define NETIO_UDP_PORT_UPNOTIFYPS        3356 /* UPNOTIFYPS */
#define NETIO_UDP_PORT_ADTECH_TEST       3357 /* Adtech Test IP */
#define NETIO_UDP_PORT_MPSYSRMSVR        3358 /* Mp Sys Rmsvr */
#define NETIO_UDP_PORT_WG_NETFORCE       3359 /* WG NetForce */
#define NETIO_UDP_PORT_KV_SERVER         3360 /* KV Server */
#define NETIO_UDP_PORT_KV_AGENT          3361 /* KV Agent */
#define NETIO_UDP_PORT_DJ_ILM            3362 /* DJ ILM */
#define NETIO_UDP_PORT_NATI_VI_SERVER    3363 /* NATI Vi Server */
#define NETIO_UDP_PORT_CREATIVESERVER2   3364 /* Creative Server */
#define NETIO_UDP_PORT_CONTENTSERVER2    3365 /* Content Server */
#define NETIO_UDP_PORT_CREATIVEPARTNR2   3366 /* Creative Partner */
#define NETIO_UDP_PORT_TIP2              3372 /* TIP 2 */
#define NETIO_UDP_PORT_LAVENIR_LM        3373 /* Lavenir License Manager */
#define NETIO_UDP_PORT_CLUSTER_DISC      3374 /* Cluster Disc */
#define NETIO_UDP_PORT_VSNM_AGENT        3375 /* VSNM Agent */
#define NETIO_UDP_PORT_CDBROKER          3376 /* CD Broker */
#define NETIO_UDP_PORT_COGSYS_LM         3377 /* Cogsys Network License Manager */
#define NETIO_UDP_PORT_WSICOPY           3378 /* WSICOPY */
#define NETIO_UDP_PORT_SOCORFS           3379 /* SOCORFS */
#define NETIO_UDP_PORT_SNS_CHANNELS      3380 /* SNS Channels */
#define NETIO_UDP_PORT_GENEOUS           3381 /* Geneous */
#define NETIO_UDP_PORT_FUJITSU_NEAT      3382 /* Fujitsu Network Enhanced Antitheft function */
#define NETIO_UDP_PORT_ESP_LM            3383 /* Enterprise Software Products License Manager */
#define NETIO_UDP_PORT_HP_CLIC           3384 /* Hardware Management */
#define NETIO_UDP_PORT_QNXNETMAN         3385 /* qnxnetman */
#define NETIO_UDP_PORT_GPRS_SIG          3386 /* GPRS SIG */
#define NETIO_UDP_PORT_BACKROOMNET       3387 /* Back Room Net */
#define NETIO_UDP_PORT_CBSERVER          3388 /* CB Server */
#define NETIO_UDP_PORT_MS_WBT_SERVER     3389 /* MS WBT Server */
#define NETIO_UDP_PORT_DSC               3390 /* Distributed Service Coordinator */
#define NETIO_UDP_PORT_SAVANT            3391 /* SAVANT */
#define NETIO_UDP_PORT_EFI_LM            3392 /* EFI License Management */
#define NETIO_UDP_PORT_D2K_TAPESTRY1     3393 /* D2K Tapestry Client to Server */
#define NETIO_UDP_PORT_D2K_TAPESTRY2     3394 /* D2K Tapestry Server to Server */
#define NETIO_UDP_PORT_DYNA_LM           3395 /* Dyna License Manager (Elam) */
#define NETIO_UDP_PORT_PRINTER_AGENT     3396 /* "Printer Agent */
#define NETIO_UDP_PORT_CLOANTO_LM        3397 /* Cloanto License Manager */
#define NETIO_UDP_PORT_MERCANTILE        3398 /* Mercantile */
#define NETIO_UDP_PORT_CSMS              3399 /* CSMS */
#define NETIO_UDP_PORT_CSMS2             3400 /* CSMS2 */
#define NETIO_UDP_PORT_FILECAST          3401 /* filecast */
#define NETIO_UDP_PORT_FXAENGINE_NET     3402 /* FXa Engine Network Port */
#define NETIO_UDP_PORT_NOKIA_ANN_CH1     3405 /* Nokia Announcement ch 1 */
#define NETIO_UDP_PORT_NOKIA_ANN_CH2     3406 /* Nokia Announcement ch 2 */
#define NETIO_UDP_PORT_LDAP_ADMIN        3407 /* LDAP admin server port */
#define NETIO_UDP_PORT_BESAPI            3408 /* BES Api Port */
#define NETIO_UDP_PORT_NETWORKLENS       3409 /* NetworkLens Event Port */
#define NETIO_UDP_PORT_NETWORKLENSS      3410 /* NetworkLens SSL Event */
#define NETIO_UDP_PORT_BIOLINK_AUTH      3411 /* BioLink Authenteon server */
#define NETIO_UDP_PORT_XMLBLASTER        3412 /* xmlBlaster */
#define NETIO_UDP_PORT_SVNET             3413 /* SpecView Networking */
#define NETIO_UDP_PORT_WIP_PORT          3414 /* BroadCloud WIP Port */
#define NETIO_UDP_PORT_BCINAMESERVICE    3415 /* BCI Name Service */
#define NETIO_UDP_PORT_COMMANDPORT       3416 /* AirMobile IS Command Port */
#define NETIO_UDP_PORT_CSVR              3417 /* ConServR file translation */
#define NETIO_UDP_PORT_RNMAP             3418 /* Remote nmap */
#define NETIO_UDP_PORT_SOFTAUDIT         3419 /* ISogon SoftAudit */
#define NETIO_UDP_PORT_IFCP_PORT         3420 /* iFCP User Port */
#define NETIO_UDP_PORT_BMAP              3421 /* Bull Apprise portmapper */
#define NETIO_UDP_PORT_RUSB_SYS_PORT     3422 /* Remote USB System Port */
#define NETIO_UDP_PORT_XTRM              3423 /* xTrade Reliable Messaging */
#define NETIO_UDP_PORT_XTRMS             3424 /* xTrade over TLS/SSL */
#define NETIO_UDP_PORT_AGPS_PORT         3425 /* AGPS Access Port */
#define NETIO_UDP_PORT_ARKIVIO           3426 /* Arkivio Storage Protocol */
#define NETIO_UDP_PORT_WEBSPHERE_SNMP    3427 /* WebSphere SNMP */
#define NETIO_UDP_PORT_TWCSS             3428 /* 2Wire CSS */
#define NETIO_UDP_PORT_GCSP              3429 /* GCSP user port */
#define NETIO_UDP_PORT_SSDISPATCH        3430 /* Scott Studios Dispatch */
#define NETIO_UDP_PORT_NDL_ALS           3431 /* Active License Server Port */
#define NETIO_UDP_PORT_OSDCP             3432 /* Secure Device Protocol */
#define NETIO_UDP_PORT_OPNET_SMP         3433 /* OPNET Service Management Platform */
#define NETIO_UDP_PORT_OPENCM            3434 /* OpenCM Server */
#define NETIO_UDP_PORT_PACOM             3435 /* Pacom Security User Port */
#define NETIO_UDP_PORT_GC_CONFIG         3436 /* GuardControl Exchange Protocol */
#define NETIO_UDP_PORT_AUTOCUEDS         3437 /* Autocue Directory Service */
#define NETIO_UDP_PORT_SPIRAL_ADMIN      3438 /* Spiralcraft Admin */
#define NETIO_UDP_PORT_HRI_PORT          3439 /* HRI Interface Port */
#define NETIO_UDP_PORT_ANS_CONSOLE       3440 /* Net Steward Mgmt Console */
#define NETIO_UDP_PORT_CONNECT_CLIENT    3441 /* OC Connect Client */
#define NETIO_UDP_PORT_CONNECT_SERVER    3442 /* OC Connect Server */
#define NETIO_UDP_PORT_OV_NNM_WEBSRV     3443 /* OpenView Network Node Manager WEB Server */
#define NETIO_UDP_PORT_DENALI_SERVER     3444 /* Denali Server */
#define NETIO_UDP_PORT_MONP              3445 /* Media Object Network */
#define NETIO_UDP_PORT_3COMFAXRPC        3446 /* 3Com FAX RPC port */
#define NETIO_UDP_PORT_DIRECTNET         3447 /* DirectNet IM System */
#define NETIO_UDP_PORT_DNC_PORT          3448 /* Discovery and Net Config */
#define NETIO_UDP_PORT_HOTU_CHAT         3449 /* HotU Chat */
#define NETIO_UDP_PORT_CASTORPROXY       3450 /* CAStorProxy */
#define NETIO_UDP_PORT_ASAM              3451 /* ASAM Services */
#define NETIO_UDP_PORT_SABP_SIGNAL       3452 /* SABP-Signalling Protocol */
#define NETIO_UDP_PORT_PSCUPD            3453 /* PSC Update Port */
#define NETIO_UDP_PORT_MIRA              3454 /* Apple Remote Access Protocol */
#define NETIO_UDP_PORT_PRSVP             3455 /* RSVP Port */
#define NETIO_UDP_PORT_VAT               3456 /* VAT default data */
#define NETIO_UDP_PORT_VAT_CONTROL       3457 /* VAT default control */
#define NETIO_UDP_PORT_D3WINOSFI         3458 /* D3WinOSFI */
#define NETIO_UDP_PORT_INTEGRAL          3459 /* TIP Integral */
#define NETIO_UDP_PORT_EDM_MANAGER       3460 /* EDM Manger */
#define NETIO_UDP_PORT_EDM_STAGER        3461 /* EDM Stager */
#define NETIO_UDP_PORT_EDM_STD_NOTIFY    3462 /* EDM STD Notify */
#define NETIO_UDP_PORT_EDM_ADM_NOTIFY    3463 /* EDM ADM Notify */
#define NETIO_UDP_PORT_EDM_MGR_SYNC      3464 /* EDM MGR Sync */
#define NETIO_UDP_PORT_EDM_MGR_CNTRL     3465 /* EDM MGR Cntrl */
#define NETIO_UDP_PORT_WORKFLOW          3466 /* WORKFLOW */
#define NETIO_UDP_PORT_RCST              3467 /* RCST */
#define NETIO_UDP_PORT_TTCMREMOTECTRL    3468 /* TTCM Remote Controll */
#define NETIO_UDP_PORT_PLURIBUS          3469 /* Pluribus */
#define NETIO_UDP_PORT_JT400             3470 /* jt400 */
#define NETIO_UDP_PORT_JT400_SSL         3471 /* jt400-ssl */
#define NETIO_UDP_PORT_JAUGSREMOTEC_1    3472 /* JAUGS N-G Remotec 1 */
#define NETIO_UDP_PORT_JAUGSREMOTEC_2    3473 /* JAUGS N-G Remotec 2 */
#define NETIO_UDP_PORT_TTNTSPAUTO        3474 /* TSP Automation */
#define NETIO_UDP_PORT_GENISAR_PORT      3475 /* Genisar Comm Port */
#define NETIO_UDP_PORT_NPPMP             3476 /* NVIDIA Mgmt Protocol */
#define NETIO_UDP_PORT_ECOMM             3477 /* eComm link port */
#define NETIO_UDP_PORT_STUN              3478 /* Session Traversal Utilities for NAT (STUN) port */
#define NETIO_UDP_PORT_TWRPC             3479 /* 2Wire RPC */
#define NETIO_UDP_PORT_PLETHORA          3480 /* Secure Virtual Workspace */
#define NETIO_UDP_PORT_CLEANERLIVERC     3481 /* CleanerLive remote ctrl */
#define NETIO_UDP_PORT_VULTURE           3482 /* Vulture Monitoring System */
#define NETIO_UDP_PORT_SLIM_DEVICES      3483 /* Slim Devices Protocol */
#define NETIO_UDP_PORT_GBS_STP           3484 /* GBS SnapTalk Protocol */
#define NETIO_UDP_PORT_CELATALK          3485 /* CelaTalk */
#define NETIO_UDP_PORT_IFSF_HB_PORT      3486 /* IFSF Heartbeat Port */
#define NETIO_UDP_PORT_LTCUDP            3487 /* LISA UDP Transfer Channel */
#define NETIO_UDP_PORT_FS_RH_SRV         3488 /* FS Remote Host Server */
#define NETIO_UDP_PORT_DTP_DIA           3489 /* DTP/DIA */
#define NETIO_UDP_PORT_COLUBRIS          3490 /* Colubris Management Port */
#define NETIO_UDP_PORT_SWR_PORT          3491 /* SWR Port */
#define NETIO_UDP_PORT_TVDUMTRAY_PORT    3492 /* TVDUM Tray Port */
#define NETIO_UDP_PORT_NUT               3493 /* Network UPS Tools */
#define NETIO_UDP_PORT_IBM3494           3494 /* IBM 3494 */
#define NETIO_UDP_PORT_SECLAYER_TCP      3495 /* securitylayer over tcp */
#define NETIO_UDP_PORT_SECLAYER_TLS      3496 /* securitylayer over tls */
#define NETIO_UDP_PORT_IPETHER232PORT    3497 /* ipEther232Port */
#define NETIO_UDP_PORT_DASHPAS_PORT      3498 /* DASHPAS user port */
#define NETIO_UDP_PORT_SCCIP_MEDIA       3499 /* SccIP Media */
#define NETIO_UDP_PORT_RTMP_PORT         3500 /* RTMP Port */
#define NETIO_UDP_PORT_ISOFT_P2P         3501 /* iSoft-P2P */
#define NETIO_UDP_PORT_AVINSTALLDISC     3502 /* Avocent Install Discovery */
#define NETIO_UDP_PORT_LSP_PING          3503 /* MPLS LSP-echo Port */
#define NETIO_UDP_PORT_IRONSTORM         3504 /* IronStorm game server */
#define NETIO_UDP_PORT_CCMCOMM           3505 /* CCM communications port */
#define NETIO_UDP_PORT_APC_3506          3506 /* APC 3506 */
#define NETIO_UDP_PORT_NESH_BROKER       3507 /* Nesh Broker Port */
#define NETIO_UDP_PORT_INTERACTIONWEB    3508 /* Interaction Web */
#define NETIO_UDP_PORT_VT_SSL            3509 /* Virtual Token SSL Port */
#define NETIO_UDP_PORT_XSS_PORT          3510 /* XSS Port */
#define NETIO_UDP_PORT_WEBMAIL_2         3511 /* WebMail/2 */
#define NETIO_UDP_PORT_AZTEC             3512 /* Aztec Distribution Port */
#define NETIO_UDP_PORT_ARCPD             3513 /* Adaptec Remote Protocol */
#define NETIO_UDP_PORT_MUST_P2P          3514 /* MUST Peer to Peer */
#define NETIO_UDP_PORT_MUST_BACKPLANE    3515 /* MUST Backplane */
#define NETIO_UDP_PORT_SMARTCARD_PORT    3516 /* Smartcard Port */
#define NETIO_UDP_PORT_802_11_IAPP       3517 /* IEEE 802.11 WLANs WG IAPP */
#define NETIO_UDP_PORT_ARTIFACT_MSG      3518 /* Artifact Message Server */
#define NETIO_UDP_PORT_GALILEO           3519 /* Netvion Galileo Port */
#define NETIO_UDP_PORT_GALILEOLOG        3520 /* Netvion Galileo Log Port */
#define NETIO_UDP_PORT_MC3SS             3521 /* Telequip Labs MC3SS */
#define NETIO_UDP_PORT_NSSOCKETPORT      3522 /* DO over NSSocketPort */
#define NETIO_UDP_PORT_ODEUMSERVLINK     3523 /* Odeum Serverlink */
#define NETIO_UDP_PORT_ECMPORT           3524 /* ECM Server port */
#define NETIO_UDP_PORT_EISPORT           3525 /* EIS Server port */
#define NETIO_UDP_PORT_STARQUIZ_PORT     3526 /* starQuiz Port */
#define NETIO_UDP_PORT_BESERVER_MSG_Q    3527 /* VERITAS Backup Exec Server */
#define NETIO_UDP_PORT_JBOSS_IIOP        3528 /* JBoss IIOP */
#define NETIO_UDP_PORT_JBOSS_IIOP_SSL    3529 /* JBoss IIOP/SSL */
#define NETIO_UDP_PORT_GF                3530 /* Grid Friendly */
#define NETIO_UDP_PORT_JOLTID            3531 /* Joltid */
#define NETIO_UDP_PORT_RAVEN_RMP         3532 /* Raven Remote Management Control */
#define NETIO_UDP_PORT_RAVEN_RDP         3533 /* Raven Remote Management Data */
#define NETIO_UDP_PORT_URLD_PORT         3534 /* URL Daemon Port */
#define NETIO_UDP_PORT_MS_LA             3535 /* MS-LA */
#define NETIO_UDP_PORT_SNAC              3536 /* SNAC */
#define NETIO_UDP_PORT_NI_VISA_REMOTE    3537 /* Remote NI-VISA port */
#define NETIO_UDP_PORT_IBM_DIRADM        3538 /* IBM Directory Server */
#define NETIO_UDP_PORT_IBM_DIRADM_SSL    3539 /* IBM Directory Server SSL */
#define NETIO_UDP_PORT_PNRP_PORT         3540 /* PNRP User Port */
#define NETIO_UDP_PORT_VOISPEED_PORT     3541 /* VoiSpeed Port */
#define NETIO_UDP_PORT_HACL_MONITOR      3542 /* HA cluster monitor */
#define NETIO_UDP_PORT_QFTEST_LOOKUP     3543 /* qftest Lookup Port */
#define NETIO_UDP_PORT_TEREDO            3544 /* Teredo Port */
#define NETIO_UDP_PORT_CAMAC             3545 /* CAMAC equipment */
#define NETIO_UDP_PORT_SYMANTEC_SIM      3547 /* Symantec SIM */
#define NETIO_UDP_PORT_INTERWORLD        3548 /* Interworld */
#define NETIO_UDP_PORT_TELLUMAT_NMS      3549 /* Tellumat MDR NMS */
#define NETIO_UDP_PORT_SSMPP             3550 /* Secure SMPP */
#define NETIO_UDP_PORT_APCUPSD           3551 /* Apcupsd Information Port */
#define NETIO_UDP_PORT_TASERVER          3552 /* TeamAgenda Server Port */
#define NETIO_UDP_PORT_RBR_DISCOVERY     3553 /* Red Box Recorder ADP */
#define NETIO_UDP_PORT_QUESTNOTIFY       3554 /* Quest Notification Server */
#define NETIO_UDP_PORT_RAZOR             3555 /* Vipul's Razor */
#define NETIO_UDP_PORT_SKY_TRANSPORT     3556 /* Sky Transport Protocol */
#define NETIO_UDP_PORT_PERSONALOS_001    3557 /* PersonalOS Comm Port */
#define NETIO_UDP_PORT_MCP_PORT          3558 /* MCP user port */
#define NETIO_UDP_PORT_CCTV_PORT         3559 /* CCTV control port */
#define NETIO_UDP_PORT_INISERVE_PORT     3560 /* INIServe port */
#define NETIO_UDP_PORT_BMC_ONEKEY        3561 /* BMC-OneKey */
#define NETIO_UDP_PORT_SDBPROXY          3562 /* SDBProxy */
#define NETIO_UDP_PORT_WATCOMDEBUG       3563 /* Watcom Debug */
#define NETIO_UDP_PORT_ESIMPORT          3564 /* Electromed SIM port */
#define NETIO_UDP_PORT_ENC_EPS           3567 /* EMIT protocol stack */
#define NETIO_UDP_PORT_ENC_TUNNEL_SEC    3568 /* EMIT secure tunnel */
#define NETIO_UDP_PORT_MBG_CTRL          3569 /* Meinberg Control Service */
#define NETIO_UDP_PORT_MCCWEBSVR_PORT    3570 /* MCC Web Server Port */
#define NETIO_UDP_PORT_MEGARDSVR_PORT    3571 /* MegaRAID Server Port */
#define NETIO_UDP_PORT_MEGAREGSVRPORT    3572 /* Registration Server Port */
#define NETIO_UDP_PORT_TAG_UPS_1         3573 /* Advantage Group UPS Suite */
#define NETIO_UDP_PORT_DMAF_CASTER       3574 /* DMAF Caster */
#define NETIO_UDP_PORT_CCM_PORT          3575 /* Coalsere CCM Port */
#define NETIO_UDP_PORT_CMC_PORT          3576 /* Coalsere CMC Port */
#define NETIO_UDP_PORT_CONFIG_PORT       3577 /* Configuration Port */
#define NETIO_UDP_PORT_DATA_PORT         3578 /* Data Port */
#define NETIO_UDP_PORT_TTAT3LB           3579 /* Tarantella Load Balancing */
#define NETIO_UDP_PORT_NATI_SVRLOC       3580 /* NATI-ServiceLocator */
#define NETIO_UDP_PORT_KFXACLICENSING    3581 /* Ascent Capture Licensing */
#define NETIO_UDP_PORT_PRESS             3582 /* PEG PRESS Server */
#define NETIO_UDP_PORT_CANEX_WATCH       3583 /* CANEX Watch System */
#define NETIO_UDP_PORT_U_DBAP            3584 /* U-DBase Access Protocol */
#define NETIO_UDP_PORT_EMPRISE_LLS       3585 /* Emprise License Server */
#define NETIO_UDP_PORT_EMPRISE_LSC       3586 /* License Server Console */
#define NETIO_UDP_PORT_P2PGROUP          3587 /* Peer to Peer Grouping */
#define NETIO_UDP_PORT_SENTINEL          3588 /* Sentinel Server */
#define NETIO_UDP_PORT_ISOMAIR           3589 /* isomair */
#define NETIO_UDP_PORT_WV_CSP_SMS        3590 /* WV CSP SMS Binding */
#define NETIO_UDP_PORT_GTRACK_SERVER     3591 /* LOCANIS G-TRACK Server */
#define NETIO_UDP_PORT_GTRACK_NE         3592 /* LOCANIS G-TRACK NE Port */
#define NETIO_UDP_PORT_BPMD              3593 /* BP Model Debugger */
#define NETIO_UDP_PORT_MEDIASPACE        3594 /* MediaSpace */
#define NETIO_UDP_PORT_SHAREAPP          3595 /* ShareApp */
#define NETIO_UDP_PORT_IW_MMOGAME        3596 /* Illusion Wireless MMOG */
#define NETIO_UDP_PORT_A14               3597 /* A14 (AN-to-SC/MM) */
#define NETIO_UDP_PORT_A15               3598 /* A15 (AN-to-AN) */
#define NETIO_UDP_PORT_QUASAR_SERVER     3599 /* Quasar Accounting Server */
#define NETIO_UDP_PORT_TRAP_DAEMON       3600 /* text relay-answer */
#define NETIO_UDP_PORT_VISINET_GUI       3601 /* Visinet Gui */
#define NETIO_UDP_PORT_INFINISWITCHCL    3602 /* InfiniSwitch Mgr Client */
#define NETIO_UDP_PORT_INT_RCV_CNTRL     3603 /* Integrated Rcvr Control */
#define NETIO_UDP_PORT_BMC_JMX_PORT      3604 /* BMC JMX Port */
#define NETIO_UDP_PORT_COMCAM_IO         3605 /* ComCam IO Port */
#define NETIO_UDP_PORT_SPLITLOCK         3606 /* Splitlock Server */
#define NETIO_UDP_PORT_PRECISE_I3        3607 /* Precise I3 */
#define NETIO_UDP_PORT_TRENDCHIP_DCP     3608 /* Trendchip control protocol */
#define NETIO_UDP_PORT_CPDI_PIDAS_CM     3609 /* CPDI PIDAS Connection Mon */
#define NETIO_UDP_PORT_ECHONET           3610 /* ECHONET */
#define NETIO_UDP_PORT_SIX_DEGREES       3611 /* Six Degrees Port */
#define NETIO_UDP_PORT_HP_DATAPROTECT    3612 /* HP Data Protector */
#define NETIO_UDP_PORT_ALARIS_DISC       3613 /* Alaris Device Discovery */
#define NETIO_UDP_PORT_SIGMA_PORT        3614 /* Satchwell Sigma */
#define NETIO_UDP_PORT_START_NETWORK     3615 /* Start Messaging Network */
#define NETIO_UDP_PORT_CD3O_PROTOCOL     3616 /* cd3o Control Protocol */
#define NETIO_UDP_PORT_SHARP_SERVER      3617 /* ATI SHARP Logic Engine */
#define NETIO_UDP_PORT_AAIRNET_1         3618 /* AAIR-Network 1 */
#define NETIO_UDP_PORT_AAIRNET_2         3619 /* AAIR-Network 2 */
#define NETIO_UDP_PORT_EP_PCP            3620 /* EPSON Projector Control Port */
#define NETIO_UDP_PORT_EP_NSP            3621 /* EPSON Network Screen Port */
#define NETIO_UDP_PORT_FF_LR_PORT        3622 /* FF LAN Redundancy Port */
#define NETIO_UDP_PORT_HAIPE_DISCOVER    3623 /* HAIPIS Dynamic Discovery */
#define NETIO_UDP_PORT_DIST_UPGRADE      3624 /* Distributed Upgrade Port */
#define NETIO_UDP_PORT_VOLLEY            3625 /* Volley */
#define NETIO_UDP_PORT_BVCDAEMON_PORT    3626 /* bvControl Daemon */
#define NETIO_UDP_PORT_JAMSERVERPORT     3627 /* Jam Server Port */
#define NETIO_UDP_PORT_EPT_MACHINE       3628 /* EPT Machine Interface */
#define NETIO_UDP_PORT_ESCVPNET          3629 /* ESC/VP.net */
#define NETIO_UDP_PORT_CS_REMOTE_DB      3630 /* C&S Remote Database Port */
#define NETIO_UDP_PORT_CS_SERVICES       3631 /* C&S Web Services Port */
#define NETIO_UDP_PORT_DISTCC            3632 /* distributed compiler */
#define NETIO_UDP_PORT_WACP              3633 /* Wyrnix AIS port */
#define NETIO_UDP_PORT_HLIBMGR           3634 /* hNTSP Library Manager */
#define NETIO_UDP_PORT_SDO               3635 /* Simple Distributed Objects */
#define NETIO_UDP_PORT_SERVISTAITSM      3636 /* SerVistaITSM */
#define NETIO_UDP_PORT_SCSERVP           3637 /* Customer Service Port */
#define NETIO_UDP_PORT_EHP_BACKUP        3638 /* EHP Backup Protocol */
#define NETIO_UDP_PORT_XAP_HA            3639 /* Extensible Automation */
#define NETIO_UDP_PORT_NETPLAY_PORT1     3640 /* Netplay Port 1 */
#define NETIO_UDP_PORT_NETPLAY_PORT2     3641 /* Netplay Port 2 */
#define NETIO_UDP_PORT_JUXML_PORT        3642 /* Juxml Replication port */
#define NETIO_UDP_PORT_AUDIOJUGGLER      3643 /* AudioJuggler */
#define NETIO_UDP_PORT_SSOWATCH          3644 /* ssowatch */
#define NETIO_UDP_PORT_CYC               3645 /* Cyc */
#define NETIO_UDP_PORT_XSS_SRV_PORT      3646 /* XSS Server Port */
#define NETIO_UDP_PORT_SPLITLOCK_GW      3647 /* Splitlock Gateway */
#define NETIO_UDP_PORT_FJCP              3648 /* Fujitsu Cooperation Port */
#define NETIO_UDP_PORT_NMMP              3649 /* Nishioka Miyuki Msg Protocol */
#define NETIO_UDP_PORT_PRISMIQ_PLUGIN    3650 /* PRISMIQ VOD plug-in */
#define NETIO_UDP_PORT_XRPC_REGISTRY     3651 /* XRPC Registry */
#define NETIO_UDP_PORT_VXCRNBUPORT       3652 /* VxCR NBU Default Port */
#define NETIO_UDP_PORT_TSP               3653 /* Tunnel Setup Protocol */
#define NETIO_UDP_PORT_VAPRTM            3654 /* VAP RealTime Messenger */
#define NETIO_UDP_PORT_ABATEMGR          3655 /* ActiveBatch Exec Agent */
#define NETIO_UDP_PORT_ABATJSS           3656 /* ActiveBatch Job Scheduler */
#define NETIO_UDP_PORT_IMMEDIANET_BCN    3657 /* ImmediaNet Beacon */
#define NETIO_UDP_PORT_PS_AMS            3658 /* PlayStation AMS (Secure) */
#define NETIO_UDP_PORT_APPLE_SASL        3659 /* Apple SASL */
#define NETIO_UDP_PORT_CAN_NDS_SSL       3660 /* IBM Tivoli Directory Service using SSL */
#define NETIO_UDP_PORT_CAN_FERRET_SSL    3661 /* IBM Tivoli Directory Service using SSL */
#define NETIO_UDP_PORT_PSERVER           3662 /* pserver */
#define NETIO_UDP_PORT_DTP               3663 /* DIRECWAY Tunnel Protocol */
#define NETIO_UDP_PORT_UPS_ENGINE        3664 /* UPS Engine Port */
#define NETIO_UDP_PORT_ENT_ENGINE        3665 /* Enterprise Engine Port */
#define NETIO_UDP_PORT_ESERVER_PAP       3666 /* IBM EServer PAP */
#define NETIO_UDP_PORT_INFOEXCH          3667 /* IBM Information Exchange */
#define NETIO_UDP_PORT_DELL_RM_PORT      3668 /* Dell Remote Management */
#define NETIO_UDP_PORT_CASANSWMGMT       3669 /* CA SAN Switch Management */
#define NETIO_UDP_PORT_SMILE             3670 /* SMILE TCP/UDP Interface */
#define NETIO_UDP_PORT_EFCP              3671 /* e Field Control (EIBnet) */
#define NETIO_UDP_PORT_LISPWORKS_ORB     3672 /* LispWorks ORB */
#define NETIO_UDP_PORT_MEDIAVAULT_GUI    3673 /* Openview Media Vault GUI */
#define NETIO_UDP_PORT_WININSTALL_IPC    3674 /* WinINSTALL IPC Port */
#define NETIO_UDP_PORT_CALLTRAX          3675 /* CallTrax Data Port */
#define NETIO_UDP_PORT_VA_PACBASE        3676 /* VisualAge Pacbase server */
#define NETIO_UDP_PORT_ROVERLOG          3677 /* RoverLog IPC */
#define NETIO_UDP_PORT_IPR_DGLT          3678 /* DataGuardianLT */
#define NETIO_UDP_PORT_ESCALE            3679 /* Newton Dock */
#define NETIO_UDP_PORT_NPDS_TRACKER      3680 /* NPDS Tracker */
#define NETIO_UDP_PORT_BTS_X73           3681 /* BTS X73 Port */
#define NETIO_UDP_PORT_CAS_MAPI          3682 /* EMC SmartPackets-MAPI */
#define NETIO_UDP_PORT_BMC_EA            3683 /* BMC EDV/EA */
#define NETIO_UDP_PORT_FAXSTFX_PORT      3684 /* FAXstfX */
#define NETIO_UDP_PORT_DSX_AGENT         3685 /* DS Expert Agent */
#define NETIO_UDP_PORT_TNMPV2            3686 /* Trivial Network Management */
#define NETIO_UDP_PORT_SIMPLE_PUSH       3687 /* simple-push */
#define NETIO_UDP_PORT_SIMPLE_PUSH_S     3688 /* simple-push Secure */
#define NETIO_UDP_PORT_DAAP              3689 /* Digital Audio Access Protocol (iTunes) */
#define NETIO_UDP_PORT_SVN               3690 /* Subversion */
#define NETIO_UDP_PORT_MAGAYA_NETWORK    3691 /* Magaya Network Port */
#define NETIO_UDP_PORT_INTELSYNC         3692 /* Brimstone IntelSync */
#define NETIO_UDP_PORT_BMC_DATA_COLL     3695 /* BMC Data Collection */
#define NETIO_UDP_PORT_TELNETCPCD        3696 /* Telnet Com Port Control */
#define NETIO_UDP_PORT_NW_LICENSE        3697 /* NavisWorks Licnese System */
#define NETIO_UDP_PORT_SAGECTLPANEL      3698 /* SAGECTLPANEL */
#define NETIO_UDP_PORT_KPN_ICW           3699 /* Internet Call Waiting */
#define NETIO_UDP_PORT_LRS_PAGING        3700 /* LRS NetPage */
#define NETIO_UDP_PORT_NETCELERA         3701 /* NetCelera */
#define NETIO_UDP_PORT_WS_DISCOVERY      3702 /* Web Service Discovery */
#define NETIO_UDP_PORT_ADOBESERVER_3     3703 /* Adobe Server 3 */
#define NETIO_UDP_PORT_ADOBESERVER_4     3704 /* Adobe Server 4 */
#define NETIO_UDP_PORT_ADOBESERVER_5     3705 /* Adobe Server 5 */
#define NETIO_UDP_PORT_RT_EVENT          3706 /* Real-Time Event Port */
#define NETIO_UDP_PORT_RT_EVENT_S        3707 /* Real-Time Event Secure Port */
#define NETIO_UDP_PORT_SUN_AS_IIOPS      3708 /* Sun App Svr - Naming */
#define NETIO_UDP_PORT_CA_IDMS           3709 /* CA-IDMS Server */
#define NETIO_UDP_PORT_PORTGATE_AUTH     3710 /* PortGate Authentication */
#define NETIO_UDP_PORT_EDB_SERVER2       3711 /* EBD Server 2 */
#define NETIO_UDP_PORT_SENTINEL_ENT      3712 /* Sentinel Enterprise */
#define NETIO_UDP_PORT_TFTPS             3713 /* TFTP over TLS */
#define NETIO_UDP_PORT_DELOS_DMS         3714 /* DELOS Direct Messaging */
#define NETIO_UDP_PORT_ANOTO_RENDEZV     3715 /* Anoto Rendezvous Port */
#define NETIO_UDP_PORT_WV_CSP_SMS_CIR    3716 /* WV CSP SMS CIR Channel */
#define NETIO_UDP_PORT_WV_CSP_UDP_CIR    3717 /* WV CSP UDP/IP CIR Channel */
#define NETIO_UDP_PORT_OPUS_SERVICES     3718 /* OPUS Server Port */
#define NETIO_UDP_PORT_ITELSERVERPORT    3719 /* iTel Server Port */
#define NETIO_UDP_PORT_UFASTRO_INSTR     3720 /* UF Astro. Instr. Services */
#define NETIO_UDP_PORT_XSYNC             3721 /* Xsync */
#define NETIO_UDP_PORT_XSERVERAID        3722 /* Xserve RAID */
#define NETIO_UDP_PORT_SYCHROND          3723 /* Sychron Service Daemon */
#define NETIO_UDP_PORT_BLIZWOW           3724 /* World of Warcraft */
#define NETIO_UDP_PORT_NA_ER_TIP         3725 /* Netia NA-ER Port */
#define NETIO_UDP_PORT_ARRAY_MANAGER     3726 /* Xyartex Array Manager */
#define NETIO_UDP_PORT_E_MDU             3727 /* Ericsson Mobile Data Unit */
#define NETIO_UDP_PORT_E_WOA             3728 /* Ericsson Web on Air */
#define NETIO_UDP_PORT_FKSP_AUDIT        3729 /* Fireking Audit Port */
#define NETIO_UDP_PORT_CLIENT_CTRL       3730 /* Client Control */
#define NETIO_UDP_PORT_SMAP              3731 /* Service Manager */
#define NETIO_UDP_PORT_M_WNN             3732 /* Mobile Wnn */
#define NETIO_UDP_PORT_MULTIP_MSG        3733 /* Multipuesto Msg Port */
#define NETIO_UDP_PORT_SYNEL_DATA        3734 /* Synel Data Collection Port */
#define NETIO_UDP_PORT_PWDIS             3735 /* Password Distribution */
#define NETIO_UDP_PORT_RS_RMI            3736 /* RealSpace RMI */
#define NETIO_UDP_PORT_VERSATALK         3738 /* versaTalk Server Port */
#define NETIO_UDP_PORT_LAUNCHBIRD_LM     3739 /* Launchbird LicenseManager */
#define NETIO_UDP_PORT_HEARTBEAT         3740 /* Heartbeat Protocol */
#define NETIO_UDP_PORT_WYSDMA            3741 /* WysDM Agent */
#define NETIO_UDP_PORT_CST_PORT          3742 /* CST - Configuration & Service Tracker */
#define NETIO_UDP_PORT_IPCS_COMMAND      3743 /* IP Control Systems Ltd. */
#define NETIO_UDP_PORT_SASG              3744 /* SASG */
#define NETIO_UDP_PORT_GW_CALL_PORT      3745 /* GWRTC Call Port */
#define NETIO_UDP_PORT_LINKTEST          3746 /* LXPRO.COM LinkTest */
#define NETIO_UDP_PORT_LINKTEST_S        3747 /* LXPRO.COM LinkTest SSL */
#define NETIO_UDP_PORT_WEBDATA           3748 /* webData */
#define NETIO_UDP_PORT_CIMTRAK           3749 /* CimTrak */
#define NETIO_UDP_PORT_CBOS_IP_PORT      3750 /* CBOS/IP ncapsalatoin port */
#define NETIO_UDP_PORT_GPRS_CUBE         3751 /* CommLinx GPRS Cube */
#define NETIO_UDP_PORT_VIPREMOTEAGENT    3752 /* Vigil-IP RemoteAgent */
#define NETIO_UDP_PORT_NATTYSERVER       3753 /* NattyServer Port */
#define NETIO_UDP_PORT_TIMESTENBROKER    3754 /* TimesTen Broker Port */
#define NETIO_UDP_PORT_SAS_REMOTE_HLP    3755 /* SAS Remote Help Server */
#define NETIO_UDP_PORT_CANON_CAPT        3756 /* Canon CAPT Port */
#define NETIO_UDP_PORT_GRF_PORT          3757 /* GRF Server Port */
#define NETIO_UDP_PORT_APW_REGISTRY      3758 /* apw RMI registry */
#define NETIO_UDP_PORT_EXAPT_LMGR        3759 /* Exapt License Manager */
#define NETIO_UDP_PORT_ADTEMPUSCLIENT    3760 /* adTEmpus Client */
#define NETIO_UDP_PORT_GSAKMP            3761 /* gsakmp port */
#define NETIO_UDP_PORT_GBS_SMP           3762 /* GBS SnapMail Protocol */
#define NETIO_UDP_PORT_XO_WAVE           3763 /* XO Wave Control Port */
#define NETIO_UDP_PORT_MNI_PROT_ROUT     3764 /* MNI Protected Routing */
#define NETIO_UDP_PORT_RTRACEROUTE       3765 /* Remote Traceroute */
#define NETIO_UDP_PORT_LISTMGR_PORT      3767 /* ListMGR Port */
#define NETIO_UDP_PORT_RBLCHECKD         3768 /* rblcheckd server daemon */
#define NETIO_UDP_PORT_HAIPE_OTNK        3769 /* HAIPE Network Keying */
#define NETIO_UDP_PORT_CINDYCOLLAB       3770 /* Cinderella Collaboration */
#define NETIO_UDP_PORT_PAGING_PORT       3771 /* RTP Paging Port */
#define NETIO_UDP_PORT_CTP               3772 /* Chantry Tunnel Protocol */
#define NETIO_UDP_PORT_CTDHERCULES       3773 /* ctdhercules */
#define NETIO_UDP_PORT_ZICOM             3774 /* ZICOM */
#define NETIO_UDP_PORT_ISPMMGR           3775 /* ISPM Manager Port */
#define NETIO_UDP_PORT_DVCPROV_PORT      3776 /* Device Provisioning Port */
#define NETIO_UDP_PORT_JIBE_EB           3777 /* Jibe EdgeBurst */
#define NETIO_UDP_PORT_C_H_IT_PORT       3778 /* Cutler-Hammer IT Port */
#define NETIO_UDP_PORT_COGNIMA           3779 /* Cognima Replication */
#define NETIO_UDP_PORT_NNP               3780 /* Nuzzler Network Protocol */
#define NETIO_UDP_PORT_ABCVOICE_PORT     3781 /* ABCvoice server port */
#define NETIO_UDP_PORT_ISO_TP0S          3782 /* Secure ISO TP0 port */
#define NETIO_UDP_PORT_BIM_PEM           3783 /* Impact Mgr./PEM Gateway */
#define NETIO_UDP_PORT_BFD_CONTROL       3784 /* BFD Control Protocol */
#define NETIO_UDP_PORT_BFD_ECHO          3785 /* BFD Echo Protocol */
#define NETIO_UDP_PORT_UPSTRIGGERVSW     3786 /* VSW Upstrigger port */
#define NETIO_UDP_PORT_FINTRX            3787 /* Fintrx */
#define NETIO_UDP_PORT_ISRP_PORT         3788 /* SPACEWAY Routing port */
#define NETIO_UDP_PORT_REMOTEDEPLOY      3789 /* RemoteDeploy Administration Port [July 2003] */
#define NETIO_UDP_PORT_QUICKBOOKSRDS     3790 /* QuickBooks RDS */
#define NETIO_UDP_PORT_TVNETWORKVIDEO    3791 /* TV NetworkVideo Data port */
#define NETIO_UDP_PORT_SITEWATCH         3792 /* e-Watch Corporation SiteWatch */
#define NETIO_UDP_PORT_DCSOFTWARE        3793 /* DataCore Software */
#define NETIO_UDP_PORT_JAUS              3794 /* JAUS Robots */
#define NETIO_UDP_PORT_MYBLAST           3795 /* myBLAST Mekentosj port */
#define NETIO_UDP_PORT_SPW_DIALER        3796 /* Spaceway Dialer */
#define NETIO_UDP_PORT_IDPS              3797 /* idps */
#define NETIO_UDP_PORT_MINILOCK          3798 /* Minilock */
#define NETIO_UDP_PORT_RADIUS_DYNAUTH    3799 /* RADIUS Dynamic Authorization */
#define NETIO_UDP_PORT_PWGPSI            3800 /* Print Services Interface */
#define NETIO_UDP_PORT_IBM_MGR           3801 /* ibm manager service */
#define NETIO_UDP_PORT_VHD               3802 /* VHD */
#define NETIO_UDP_PORT_SONIQSYNC         3803 /* SoniqSync */
#define NETIO_UDP_PORT_IQNET_PORT        3804 /* Harman IQNet Port */
#define NETIO_UDP_PORT_TCPDATASERVER     3805 /* ThorGuard Server Port */
#define NETIO_UDP_PORT_WSMLB             3806 /* Remote System Manager */
#define NETIO_UDP_PORT_SPUGNA            3807 /* SpuGNA Communication Port */
#define NETIO_UDP_PORT_SUN_AS_IIOPS_CA   3808 /* Sun App Svr-IIOPClntAuth */
#define NETIO_UDP_PORT_APOCD             3809 /* Java Desktop System Configuration Agent */
#define NETIO_UDP_PORT_WLANAUTH          3810 /* WLAN AS server */
#define NETIO_UDP_PORT_AMP               3811 /* AMP */
#define NETIO_UDP_PORT_NETO_WOL_SERVER   3812 /* netO WOL Server */
#define NETIO_UDP_PORT_RAP_IP            3813 /* Rhapsody Interface Protocol */
#define NETIO_UDP_PORT_NETO_DCS          3814 /* netO DCS */
#define NETIO_UDP_PORT_LANSURVEYORXML    3815 /* LANsurveyor XML */
#define NETIO_UDP_PORT_SUNLPS_HTTP       3816 /* Sun Local Patch Server */
#define NETIO_UDP_PORT_TAPEWARE          3817 /* Yosemite Tech Tapeware */
#define NETIO_UDP_PORT_CRINIS_HB         3818 /* Crinis Heartbeat */
#define NETIO_UDP_PORT_EPL_SLP           3819 /* EPL Sequ Layer Protocol */
#define NETIO_UDP_PORT_SCP               3820 /* Siemens AuD SCP */
#define NETIO_UDP_PORT_PMCP              3821 /* ATSC PMCP Standard */
#define NETIO_UDP_PORT_ACP_DISCOVERY     3822 /* Compute Pool Discovery */
#define NETIO_UDP_PORT_ACP_CONDUIT       3823 /* Compute Pool Conduit */
#define NETIO_UDP_PORT_ACP_POLICY        3824 /* Compute Pool Policy */
#define NETIO_UDP_PORT_FFSERVER          3825 /* Antera FlowFusion Process Simulation */
#define NETIO_UDP_PORT_WARMUX            3826 /* WarMUX game server */
#define NETIO_UDP_PORT_NETMPI            3827 /* Netadmin Systems MPI service */
#define NETIO_UDP_PORT_NETEH             3828 /* Netadmin Systems Event Handler */
#define NETIO_UDP_PORT_NETEH_EXT         3829 /* Netadmin Systems Event Handler External */
#define NETIO_UDP_PORT_CERNSYSMGMTAGT    3830 /* Cerner System Management Agent */
#define NETIO_UDP_PORT_DVAPPS            3831 /* Docsvault Application Service */
#define NETIO_UDP_PORT_XXNETSERVER       3832 /* xxNETserver */
#define NETIO_UDP_PORT_AIPN_AUTH         3833 /* AIPN LS Authentication */
#define NETIO_UDP_PORT_SPECTARDATA       3834 /* Spectar Data Stream Service */
#define NETIO_UDP_PORT_SPECTARDB         3835 /* Spectar Database Rights Service */
#define NETIO_UDP_PORT_MARKEM_DCP        3836 /* MARKEM NEXTGEN DCP */
#define NETIO_UDP_PORT_MKM_DISCOVERY     3837 /* MARKEM Auto-Discovery */
#define NETIO_UDP_PORT_SOS               3838 /* Scito Object Server */
#define NETIO_UDP_PORT_AMX_RMS           3839 /* AMX Resource Management Suite */
#define NETIO_UDP_PORT_FLIRTMITMIR       3840 /* www.FlirtMitMir.de */
#define NETIO_UDP_PORT_ZFIRM_SHIPRUSH3   3841 /* Z-Firm ShipRush v3 */
#define NETIO_UDP_PORT_NHCI              3842 /* NHCI status port */
#define NETIO_UDP_PORT_QUEST_AGENT       3843 /* Quest Common Agent */
#define NETIO_UDP_PORT_RNM               3844 /* RNM */
#define NETIO_UDP_PORT_V_ONE_SPP         3845 /* V-ONE Single Port Proxy */
#define NETIO_UDP_PORT_AN_PCP            3846 /* Astare Network PCP */
#define NETIO_UDP_PORT_MSFW_CONTROL      3847 /* MS Firewall Control */
#define NETIO_UDP_PORT_ITEM              3848 /* IT Environmental Monitor */
#define NETIO_UDP_PORT_SPW_DNSPRELOAD    3849 /* SPACEWAY DNS Prelaod */
#define NETIO_UDP_PORT_QTMS_BOOTSTRAP    3850 /* QTMS Bootstrap Protocol */
#define NETIO_UDP_PORT_SPECTRAPORT       3851 /* SpectraTalk Port */
#define NETIO_UDP_PORT_SSE_APP_CONFIG    3852 /* SSE App Configuration */
#define NETIO_UDP_PORT_SSCAN             3853 /* SONY scanning protocol */
#define NETIO_UDP_PORT_STRYKER_COM       3854 /* Stryker Comm Port */
#define NETIO_UDP_PORT_OPENTRAC          3855 /* OpenTRAC */
#define NETIO_UDP_PORT_INFORMER          3856 /* INFORMER */
#define NETIO_UDP_PORT_TRAP_PORT         3857 /* Trap Port */
#define NETIO_UDP_PORT_TRAP_PORT_MOM     3858 /* Trap Port MOM */
#define NETIO_UDP_PORT_NAV_PORT          3859 /* Navini Port */
#define NETIO_UDP_PORT_SASP              3860 /* Server/Application State Protocol (SASP) */
#define NETIO_UDP_PORT_WINSHADOW_HD      3861 /* winShadow Host Discovery */
#define NETIO_UDP_PORT_GIGA_POCKET       3862 /* GIGA-POCKET */
#define NETIO_UDP_PORT_ASAP_UDP          3863 /* asap udp port */
#define NETIO_UDP_PORT_XPL               3865 /* xpl automation protocol */
#define NETIO_UDP_PORT_DZDAEMON          3866 /* Sun SDViz DZDAEMON Port */
#define NETIO_UDP_PORT_DZOGLSERVER       3867 /* Sun SDViz DZOGLSERVER Port */
#define NETIO_UDP_PORT_OVSAM_MGMT        3869 /* hp OVSAM MgmtServer Disco */
#define NETIO_UDP_PORT_OVSAM_D_AGENT     3870 /* hp OVSAM HostAgent Disco */
#define NETIO_UDP_PORT_AVOCENT_ADSAP     3871 /* Avocent DS Authorization */
#define NETIO_UDP_PORT_OEM_AGENT         3872 /* OEM Agent */
#define NETIO_UDP_PORT_FAGORDNC          3873 /* fagordnc */
#define NETIO_UDP_PORT_SIXXSCONFIG       3874 /* SixXS Configuration */
#define NETIO_UDP_PORT_PNBSCADA          3875 /* PNBSCADA */
#define NETIO_UDP_PORT_DL_AGENT          3876 /* "DirectoryLockdown Agent */
#define NETIO_UDP_PORT_XMPCR_INTERFACE   3877 /* XMPCR Interface Port */
#define NETIO_UDP_PORT_FOTOGCAD          3878 /* FotoG CAD interface */
#define NETIO_UDP_PORT_APPSS_LM          3879 /* appss license manager */
#define NETIO_UDP_PORT_IGRS              3880 /* IGRS */
#define NETIO_UDP_PORT_IDAC              3881 /* Data Acquisition and Control */
#define NETIO_UDP_PORT_MSDTS1            3882 /* DTS Service Port */
#define NETIO_UDP_PORT_VRPN              3883 /* VR Peripheral Network */
#define NETIO_UDP_PORT_SOFTRACK_METER    3884 /* SofTrack Metering */
#define NETIO_UDP_PORT_TOPFLOW_SSL       3885 /* TopFlow SSL */
#define NETIO_UDP_PORT_NEI_MANAGEMENT    3886 /* NEI management port */
#define NETIO_UDP_PORT_CIPHIRE_DATA      3887 /* Ciphire Data Transport */
#define NETIO_UDP_PORT_CIPHIRE_SERV      3888 /* Ciphire Services */
#define NETIO_UDP_PORT_DANDV_TESTER      3889 /* D and V Tester Control Port */
#define NETIO_UDP_PORT_NDSCONNECT        3890 /* Niche Data Server Connect */
#define NETIO_UDP_PORT_RTC_PM_PORT       3891 /* Oracle RTC-PM port */
#define NETIO_UDP_PORT_PCC_IMAGE_PORT    3892 /* PCC-image-port */
#define NETIO_UDP_PORT_CGI_STARAPI       3893 /* CGI StarAPI Server */
#define NETIO_UDP_PORT_SYAM_AGENT        3894 /* SyAM Agent Port */
#define NETIO_UDP_PORT_SYAM_SMC          3895 /* SyAm SMC Service Port */
#define NETIO_UDP_PORT_SDO_TLS           3896 /* Simple Distributed Objects over TLS */
#define NETIO_UDP_PORT_SDO_SSH           3897 /* Simple Distributed Objects over SSH */
#define NETIO_UDP_PORT_SENIP             3898 /* "IAS */
#define NETIO_UDP_PORT_ITV_CONTROL       3899 /* ITV Port */
#define NETIO_UDP_PORT_UDT_OS2           3900 /* "Unidata UDT OS */
#define NETIO_UDP_PORT_NIMSH             3901 /* NIM Service Handler */
#define NETIO_UDP_PORT_NIMAUX            3902 /* NIMsh Auxiliary Port */
#define NETIO_UDP_PORT_CHARSETMGR        3903 /* CharsetMGR */
#define NETIO_UDP_PORT_OMNILINK_PORT     3904 /* Arnet Omnilink Port */
#define NETIO_UDP_PORT_MUPDATE           3905 /* Mailbox Update (MUPDATE) protocol */
#define NETIO_UDP_PORT_TOPOVISTA_DATA    3906 /* TopoVista elevation data */
#define NETIO_UDP_PORT_IMOGUIA_PORT      3907 /* Imoguia Port */
#define NETIO_UDP_PORT_HPPRONETMAN       3908 /* HP Procurve NetManagement */
#define NETIO_UDP_PORT_SURFCONTROLCPA    3909 /* SurfControl CPA */
#define NETIO_UDP_PORT_PRNREQUEST        3910 /* Printer Request Port */
#define NETIO_UDP_PORT_PRNSTATUS         3911 /* Printer Status Port */
#define NETIO_UDP_PORT_GBMT_STARS        3912 /* Global Maintech Stars */
#define NETIO_UDP_PORT_LISTCRT_PORT      3913 /* ListCREATOR Port */
#define NETIO_UDP_PORT_LISTCRT_PORT_2    3914 /* ListCREATOR Port 2 */
#define NETIO_UDP_PORT_AGCAT             3915 /* Auto-Graphics Cataloging */
#define NETIO_UDP_PORT_WYSDMC            3916 /* WysDM Controller */
#define NETIO_UDP_PORT_AFTMUX            3917 /* AFT multiples port */
#define NETIO_UDP_PORT_PKTCABLEMMCOPS    3918 /* PacketCableMultimediaCOPS */
#define NETIO_UDP_PORT_HYPERIP           3919 /* HyperIP */
#define NETIO_UDP_PORT_EXASOFTPORT1      3920 /* Exasoft IP Port */
#define NETIO_UDP_PORT_HERODOTUS_NET     3921 /* Herodotus Net */
#define NETIO_UDP_PORT_SOR_UPDATE        3922 /* Soronti Update Port */
#define NETIO_UDP_PORT_SYMB_SB_PORT      3923 /* Symbian Service Broker */
#define NETIO_UDP_PORT_MPL_GPRS_PORT     3924 /* MPL_GPRS_Port */
#define NETIO_UDP_PORT_ZMP               3925 /* Zoran Media Port */
#define NETIO_UDP_PORT_WINPORT           3926 /* WINPort */
#define NETIO_UDP_PORT_NATDATASERVICE    3927 /* ScsTsr */
#define NETIO_UDP_PORT_NETBOOT_PXE       3928 /* PXE NetBoot Manager */
#define NETIO_UDP_PORT_SMAUTH_PORT       3929 /* AMS Port */
#define NETIO_UDP_PORT_SYAM_WEBSERVER    3930 /* Syam Web Server Port */
#define NETIO_UDP_PORT_MSR_PLUGIN_PORT   3931 /* MSR Plugin Port */
#define NETIO_UDP_PORT_DYN_SITE          3932 /* Dynamic Site System */
#define NETIO_UDP_PORT_PLBSERVE_PORT     3933 /* PL/B App Server User Port */
#define NETIO_UDP_PORT_SUNFM_PORT        3934 /* PL/B File Manager Port */
#define NETIO_UDP_PORT_SDP_PORTMAPPER    3935 /* SDP Port Mapper Protocol */
#define NETIO_UDP_PORT_MAILPROX          3936 /* Mailprox */
#define NETIO_UDP_PORT_DVBSERVDSC        3937 /* DVB Service Discovery */
#define NETIO_UDP_PORT_DBCONTROL_AGENT   3938 /* "Oracel dbControl Agent po */
#define NETIO_UDP_PORT_AAMP              3939 /* Anti-virus Application Management Port */
#define NETIO_UDP_PORT_XECP_NODE         3940 /* XeCP Node Service */
#define NETIO_UDP_PORT_HOMEPORTAL_WEB    3941 /* Home Portal Web Server */
#define NETIO_UDP_PORT_SRDP              3942 /* satellite distribution */
#define NETIO_UDP_PORT_TIG               3943 /* TetraNode Ip Gateway */
#define NETIO_UDP_PORT_SOPS              3944 /* S-Ops Management */
#define NETIO_UDP_PORT_EMCADS            3945 /* EMCADS Server Port */
#define NETIO_UDP_PORT_BACKUPEDGE        3946 /* BackupEDGE Server */
#define NETIO_UDP_PORT_CCP               3947 /* "Connect and Control Protocol for Consumer */
#define NETIO_UDP_PORT_APDAP             3948 /* Anton Paar Device Administration Protocol */
#define NETIO_UDP_PORT_DRIP              3949 /* Dynamic Routing Information Protocol */
#define NETIO_UDP_PORT_NAMEMUNGE         3950 /* Name Munging */
#define NETIO_UDP_PORT_PWGIPPFAX         3951 /* PWG IPP Facsimile */
#define NETIO_UDP_PORT_I3_SESSIONMGR     3952 /* I3 Session Manager */
#define NETIO_UDP_PORT_XMLINK_CONNECT    3953 /* Eydeas XMLink Connect */
#define NETIO_UDP_PORT_ADREP             3954 /* AD Replication RPC */
#define NETIO_UDP_PORT_P2PCOMMUNITY      3955 /* p2pCommunity */
#define NETIO_UDP_PORT_GVCP              3956 /* GigE Vision Control */
#define NETIO_UDP_PORT_MQE_BROKER        3957 /* MQEnterprise Broker */
#define NETIO_UDP_PORT_MQE_AGENT         3958 /* MQEnterprise Agent */
#define NETIO_UDP_PORT_TREEHOPPER        3959 /* Tree Hopper Networking */
#define NETIO_UDP_PORT_BESS              3960 /* Bess Peer Assessment */
#define NETIO_UDP_PORT_PROAXESS          3961 /* ProAxess Server */
#define NETIO_UDP_PORT_SBI_AGENT         3962 /* SBI Agent Protocol */
#define NETIO_UDP_PORT_THRP              3963 /* Teran Hybrid Routing Protocol */
#define NETIO_UDP_PORT_SASGGPRS          3964 /* SASG GPRS */
#define NETIO_UDP_PORT_ATI_IP_TO_NCPE    3965 /* Avanti IP to NCPE API */
#define NETIO_UDP_PORT_BFLCKMGR          3966 /* BuildForge Lock Manager */
#define NETIO_UDP_PORT_PPSMS             3967 /* PPS Message Service */
#define NETIO_UDP_PORT_IANYWHERE_DBNS    3968 /* iAnywhere DBNS */
#define NETIO_UDP_PORT_LANDMARKS         3969 /* Landmark Messages */
#define NETIO_UDP_PORT_LANREVAGENT       3970 /* LANrev Agent */
#define NETIO_UDP_PORT_LANREVSERVER      3971 /* LANrev Server */
#define NETIO_UDP_PORT_ICONP             3972 /* ict-control Protocol */
#define NETIO_UDP_PORT_PROGISTICS        3973 /* ConnectShip Progistics */
#define NETIO_UDP_PORT_CITYSEARCH        3974 /* Remote Applicant Tracking Service */
#define NETIO_UDP_PORT_AIRSHOT           3975 /* Air Shot */
#define NETIO_UDP_PORT_OPSWAGENT         3976 /* Opsware Agent */
#define NETIO_UDP_PORT_OPSWMANAGER       3977 /* Opsware Manager */
#define NETIO_UDP_PORT_SECURE_CFG_SVR    3978 /* Secured Configuration Server */
#define NETIO_UDP_PORT_SMWAN             3979 /* Smith Micro Wide Area Network Service */
#define NETIO_UDP_PORT_ACMS              3980 /* Aircraft Cabin Management System */
#define NETIO_UDP_PORT_STARFISH          3981 /* Starfish System Admin */
#define NETIO_UDP_PORT_EIS               3982 /* ESRI Image Server */
#define NETIO_UDP_PORT_EISP              3983 /* ESRI Image Service */
#define NETIO_UDP_PORT_MAPPER_NODEMGR    3984 /* MAPPER network node manager */
#define NETIO_UDP_PORT_MAPPER_MAPETHD    3985 /* MAPPER TCP/IP server */
#define NETIO_UDP_PORT_MAPPER_WS_ETHD    3986 /* "MAPPER workstation server */
#define NETIO_UDP_PORT_CENTERLINE        3987 /* Centerline */
#define NETIO_UDP_PORT_DCS_CONFIG        3988 /* DCS Configuration Port */
#define NETIO_UDP_PORT_BV_QUERYENGINE    3989 /* BindView-Query Engine */
#define NETIO_UDP_PORT_BV_IS             3990 /* BindView-IS */
#define NETIO_UDP_PORT_BV_SMCSRV         3991 /* BindView-SMCServer */
#define NETIO_UDP_PORT_BV_DS             3992 /* BindView-DirectoryServer */
#define NETIO_UDP_PORT_BV_AGENT          3993 /* BindView-Agent */
#define NETIO_UDP_PORT_ISS_MGMT_SSL      3995 /* ISS Management Svcs SSL */
#define NETIO_UDP_PORT_ABCSOFTWARE       3996 /* abcsoftware-01 */
#define NETIO_UDP_PORT_AGENTSEASE_DB     3997 /* aes_db */
#define NETIO_UDP_PORT_DNX               3998 /* Distributed Nagios Executor Service */
#define NETIO_UDP_PORT_NVCNET            3999 /* Norman distributes scanning service */
#define NETIO_UDP_PORT_TERABASE          4000 /* Terabase */
#define NETIO_UDP_PORT_NEWOAK            4001 /* NewOak */
#define NETIO_UDP_PORT_PXC_SPVR_FT       4002 /* pxc-spvr-ft */
#define NETIO_UDP_PORT_PXC_SPLR_FT       4003 /* pxc-splr-ft */
#define NETIO_UDP_PORT_PXC_ROID          4004 /* pxc-roid */
#define NETIO_UDP_PORT_PXC_PIN           4005 /* pxc-pin */
#define NETIO_UDP_PORT_PXC_SPVR          4006 /* pxc-spvr */
#define NETIO_UDP_PORT_PXC_SPLR          4007 /* pxc-splr */
#define NETIO_UDP_PORT_NETCHEQUE         4008 /* NetCheque accounting */
#define NETIO_UDP_PORT_CHIMERA_HWM       4009 /* Chimera HWM */
#define NETIO_UDP_PORT_SAMSUNG_UNIDEX    4010 /* Samsung Unidex */
#define NETIO_UDP_PORT_ALTSERVICEBOOT    4011 /* Alternate Service Boot */
#define NETIO_UDP_PORT_PDA_GATE          4012 /* PDA Gate */
#define NETIO_UDP_PORT_ACL_MANAGER       4013 /* ACL Manager */
#define NETIO_UDP_PORT_TAICLOCK          4014 /* TAICLOCK */
#define NETIO_UDP_PORT_TALARIAN_MCAST1   4015 /* Talarian Mcast */
#define NETIO_UDP_PORT_TALARIAN_MCAST2   4016 /* Talarian Mcast */
#define NETIO_UDP_PORT_TALARIAN_MCAST3   4017 /* Talarian Mcast */
#define NETIO_UDP_PORT_TALARIAN_MCAST4   4018 /* Talarian Mcast */
#define NETIO_UDP_PORT_TALARIAN_MCAST5   4019 /* Talarian Mcast */
#define NETIO_UDP_PORT_TRAP              4020 /* TRAP Port */
#define NETIO_UDP_PORT_NEXUS_PORTAL      4021 /* Nexus Portal */
#define NETIO_UDP_PORT_DNOX              4022 /* DNOX */
#define NETIO_UDP_PORT_ESNM_ZONING       4023 /* ESNM Zoning Port */
#define NETIO_UDP_PORT_TNP1_PORT         4024 /* TNP1 User Port */
#define NETIO_UDP_PORT_PARTIMAGE         4025 /* Partition Image Port */
#define NETIO_UDP_PORT_AS_DEBUG          4026 /* Graphical Debug Server */
#define NETIO_UDP_PORT_BXP               4027 /* bitxpress */
#define NETIO_UDP_PORT_DTSERVER_PORT     4028 /* DTServer Port */
#define NETIO_UDP_PORT_IP_QSIG           4029 /* IP Q signaling protocol */
#define NETIO_UDP_PORT_JDMN_PORT         4030 /* Accell/JSP Daemon Port */
#define NETIO_UDP_PORT_SUUCP             4031 /* UUCP over SSL */
#define NETIO_UDP_PORT_VRTS_AUTH_PORT    4032 /* VERITAS Authorization Service */
#define NETIO_UDP_PORT_SANAVIGATOR       4033 /* SANavigator Peer Port */
#define NETIO_UDP_PORT_UBXD              4034 /* Ubiquinox Daemon */
#define NETIO_UDP_PORT_WAP_PUSH_HTTP     4035 /* WAP Push OTA-HTTP port */
#define NETIO_UDP_PORT_WAP_PUSH_HTTPS    4036 /* WAP Push OTA-HTTP secure */
#define NETIO_UDP_PORT_RAVEHD            4037 /* RaveHD network control */
#define NETIO_UDP_PORT_FAZZT_PTP         4038 /* Fazzt Point-To-Point */
#define NETIO_UDP_PORT_FAZZT_ADMIN       4039 /* Fazzt Administration */
#define NETIO_UDP_PORT_YO_MAIN           4040 /* Yo.net main service */
#define NETIO_UDP_PORT_HOUSTON           4041 /* Rocketeer-Houston */
#define NETIO_UDP_PORT_LDXP              4042 /* LDXP */
#define NETIO_UDP_PORT_NIRP              4043 /* Neighbour Identity Resolution */
#define NETIO_UDP_PORT_LTP               4044 /* Location Tracking Protocol */
#define NETIO_UDP_PORT_NPP2              4045 /* Network Paging Protocol */
#define NETIO_UDP_PORT_ACP_PROTO         4046 /* Accounting Protocol */
#define NETIO_UDP_PORT_CTP_STATE         4047 /* Context Transfer Protocol */
#define NETIO_UDP_PORT_WAFS              4049 /* Wide Area File Services */
#define NETIO_UDP_PORT_CISCO_WAFS        4050 /* Wide Area File Services */
#define NETIO_UDP_PORT_CPPDP             4051 /* Cisco Peer to Peer Distribution Protocol */
#define NETIO_UDP_PORT_INTERACT          4052 /* VoiceConnect Interact */
#define NETIO_UDP_PORT_CCU_COMM_1        4053 /* CosmoCall Universe Communications Port 1 */
#define NETIO_UDP_PORT_CCU_COMM_2        4054 /* CosmoCall Universe Communications Port 2 */
#define NETIO_UDP_PORT_CCU_COMM_3        4055 /* CosmoCall Universe Communications Port 3 */
#define NETIO_UDP_PORT_LMS               4056 /* Location Message Service */
#define NETIO_UDP_PORT_WFM               4057 /* Servigistics WFM server */
#define NETIO_UDP_PORT_KINGFISHER        4058 /* Kingfisher protocol */
#define NETIO_UDP_PORT_DLMS_COSEM        4059 /* DLMS/COSEM */
#define NETIO_UDP_PORT_DSMETER_IATC      4060 /* "DSMETER Inter-Agent Transfer Channel */
#define NETIO_UDP_PORT_ICE_LOCATION      4061 /* Ice Location Service (TCP) */
#define NETIO_UDP_PORT_ICE_SLOCATION     4062 /* Ice Location Service (SSL) */
#define NETIO_UDP_PORT_ICE_ROUTER        4063 /* Ice Firewall Traversal Service (TCP) */
#define NETIO_UDP_PORT_ICE_SROUTER       4064 /* Ice Firewall Traversal Service (SSL) */
#define NETIO_UDP_PORT_AVANTI_CDP        4065 /* "Avanti Common Data */
#define NETIO_UDP_PORT_PMAS              4066 /* Performance Measurement and Analysis */
#define NETIO_UDP_PORT_IDP               4067 /* Information Distribution Protocol */
#define NETIO_UDP_PORT_IPFLTBCST         4068 /* IP Fleet Broadcast */
#define NETIO_UDP_PORT_MINGER            4069 /* Minger Email Address Validation Service */
#define NETIO_UDP_PORT_TRIPE             4070 /* Trivial IP Encryption (TrIPE) */
#define NETIO_UDP_PORT_AIBKUP            4071 /* Automatically Incremental Backup */
#define NETIO_UDP_PORT_ZIETO_SOCK        4072 /* Zieto Socket Communications */
#define NETIO_UDP_PORT_IRAPP             4073 /* iRAPP Server Protocol */
#define NETIO_UDP_PORT_CEQUINT_CITYID    4074 /* Cequint City ID UI trigger */
#define NETIO_UDP_PORT_PERIMLAN          4075 /* ISC Alarm Message Service */
#define NETIO_UDP_PORT_SERAPH            4076 /* Seraph DCS */
#define NETIO_UDP_PORT_ASCOMALARM        4077 /* Ascom IP Alarming */
#define NETIO_UDP_PORT_SANTOOLS          4079 /* SANtools Diagnostic Server */
#define NETIO_UDP_PORT_LORICA_IN         4080 /* Lorica inside facing */
#define NETIO_UDP_PORT_LORICA_IN_SEC     4081 /* Lorica inside facing (SSL) */
#define NETIO_UDP_PORT_LORICA_OUT        4082 /* Lorica outside facing */
#define NETIO_UDP_PORT_LORICA_OUT_SEC    4083 /* Lorica outside facing (SSL) */
#define NETIO_UDP_PORT_FORTISPHERE_VM    4084 /* Fortisphere VM Service */
#define NETIO_UDP_PORT_FTSYNC            4086 /* Firewall/NAT state table synchronization */
#define NETIO_UDP_PORT_OPENCORE          4089 /* OpenCORE Remote Control Service */
#define NETIO_UDP_PORT_OMASGPORT         4090 /* OMA BCAST Service Guide */
#define NETIO_UDP_PORT_EWINSTALLER       4091 /* EminentWare Installer */
#define NETIO_UDP_PORT_EWDGS             4092 /* EminentWare DGS */
#define NETIO_UDP_PORT_PVXPLUSCS         4093 /* Pvx Plus CS Host */
#define NETIO_UDP_PORT_SYSRQD            4094 /* sysrq daemon */
#define NETIO_UDP_PORT_XTGUI             4095 /* xtgui information service */
#define NETIO_UDP_PORT_BRE               4096 /* BRE (Bridge Relay Element) */
#define NETIO_UDP_PORT_PATROLVIEW        4097 /* Patrol View */
#define NETIO_UDP_PORT_DRMSFSD           4098 /* drmsfsd */
#define NETIO_UDP_PORT_DPCP              4099 /* DPCP */
#define NETIO_UDP_PORT_IGO_INCOGNITO     4100 /* IGo Incognito Data Port */
#define NETIO_UDP_PORT_BRLP_0            4101 /* Braille protocol */
#define NETIO_UDP_PORT_BRLP_1            4102 /* Braille protocol */
#define NETIO_UDP_PORT_BRLP_2            4103 /* Braille protocol */
#define NETIO_UDP_PORT_BRLP_3            4104 /* Braille protocol */
#define NETIO_UDP_PORT_SHOFAR            4105 /* Shofar */
#define NETIO_UDP_PORT_SYNCHRONITE       4106 /* Synchronite */
#define NETIO_UDP_PORT_J_AC              4107 /* JDL Accounting LAN Service */
#define NETIO_UDP_PORT_ACCEL             4108 /* ACCEL */
#define NETIO_UDP_PORT_IZM               4109 /* Instantiated Zero-control Messaging */
#define NETIO_UDP_PORT_G2TAG             4110 /* G2 RFID Tag Telemetry Data */
#define NETIO_UDP_PORT_XGRID             4111 /* Xgrid */
#define NETIO_UDP_PORT_APPLE_VPNS_RP     4112 /* Apple VPN Server Reporting Protocol */
#define NETIO_UDP_PORT_AIPN_REG          4113 /* AIPN LS Registration */
#define NETIO_UDP_PORT_JOMAMQMONITOR     4114 /* JomaMQMonitor */
#define NETIO_UDP_PORT_CDS               4115 /* CDS Transfer Agent */
#define NETIO_UDP_PORT_SMARTCARD_TLS     4116 /* smartcard-TLS */
#define NETIO_UDP_PORT_HILLRSERV         4117 /* Hillr Connection Manager */
#define NETIO_UDP_PORT_NETSCRIPT         4118 /* Netadmin Systems NETscript service */
#define NETIO_UDP_PORT_ASSURIA_SLM       4119 /* Assuria Log Manager */
#define NETIO_UDP_PORT_E_BUILDER         4121 /* e-Builder Application Communication */
#define NETIO_UDP_PORT_FPRAMS            4122 /* Fiber Patrol Alarm Service */
#define NETIO_UDP_PORT_Z_WAVE            4123 /* Z-Wave Protocol */
#define NETIO_UDP_PORT_TIGV2             4124 /* Rohill TetraNode Ip Gateway v2 */
#define NETIO_UDP_PORT_OPSVIEW_ENVOY     4125 /* Opsview Envoy */
#define NETIO_UDP_PORT_DDREPL            4126 /* Data Domain Replication Service */
#define NETIO_UDP_PORT_UNIKEYPRO         4127 /* NetUniKeyServer */
#define NETIO_UDP_PORT_NUFW              4128 /* NuFW decision delegation protocol */
#define NETIO_UDP_PORT_NUAUTH            4129 /* NuFW authentication protocol */
#define NETIO_UDP_PORT_FRONET            4130 /* FRONET message protocol */
#define NETIO_UDP_PORT_STARS             4131 /* Global Maintech Stars */
#define NETIO_UDP_PORT_NUTS_DEM          4132 /* "NUTS Daemon */
#define NETIO_UDP_PORT_NUTS_BOOTP        4133 /* "NUTS Bootp Server */
#define NETIO_UDP_PORT_NIFTY_HMI         4134 /* NIFTY-Serve HMI protocol */
#define NETIO_UDP_PORT_CL_DB_ATTACH      4135 /* Classic Line Database Server Attach */
#define NETIO_UDP_PORT_CL_DB_REQUEST     4136 /* Classic Line Database Server Request */
#define NETIO_UDP_PORT_CL_DB_REMOTE      4137 /* Classic Line Database Server Remote */
#define NETIO_UDP_PORT_NETTEST           4138 /* nettest */
#define NETIO_UDP_PORT_THRTX             4139 /* Imperfect Networks Server */
#define NETIO_UDP_PORT_CEDROS_FDS        4140 /* "Cedros Fraud Detection System */
#define NETIO_UDP_PORT_OIRTGSVC          4141 /* Workflow Server */
#define NETIO_UDP_PORT_OIDOCSVC          4142 /* Document Server */
#define NETIO_UDP_PORT_OIDSR             4143 /* Document Replication */
#define NETIO_UDP_PORT_VVR_CONTROL       4145 /* VVR Control */
#define NETIO_UDP_PORT_TGCCONNECT        4146 /* TGCConnect Beacon */
#define NETIO_UDP_PORT_VRXPSERVMAN       4147 /* Multum Service Manager */
#define NETIO_UDP_PORT_HHB_HANDHELD      4148 /* HHB Handheld Client */
#define NETIO_UDP_PORT_AGSLB             4149 /* A10 GSLB Service */
#define NETIO_UDP_PORT_POWERALERT_NSA    4150 /* PowerAlert Network Shutdown Agent */
#define NETIO_UDP_PORT_MENANDMICE_NOH    4151 /* "Men & Mice Remote Control */
#define NETIO_UDP_PORT_IDIG_MUX          4152 /* "iDigTech Multiplex */
#define NETIO_UDP_PORT_MBL_BATTD         4153 /* MBL Remote Battery Monitoring */
#define NETIO_UDP_PORT_ATLINKS           4154 /* atlinks device discovery */
#define NETIO_UDP_PORT_BZR               4155 /* Bazaar version control system */
#define NETIO_UDP_PORT_STAT_RESULTS      4156 /* STAT Results */
#define NETIO_UDP_PORT_STAT_SCANNER      4157 /* STAT Scanner Control */
#define NETIO_UDP_PORT_STAT_CC           4158 /* STAT Command Center */
#define NETIO_UDP_PORT_NSS               4159 /* Network Security Service */
#define NETIO_UDP_PORT_JINI_DISCOVERY    4160 /* Jini Discovery */
#define NETIO_UDP_PORT_OMSCONTACT        4161 /* OMS Contact */
#define NETIO_UDP_PORT_OMSTOPOLOGY       4162 /* OMS Topology */
#define NETIO_UDP_PORT_SILVERPEAKPEER    4163 /* Silver Peak Peer Protocol */
#define NETIO_UDP_PORT_SILVERPEAKCOMM    4164 /* Silver Peak Communication Protocol */
#define NETIO_UDP_PORT_ALTCP             4165 /* ArcLink over Ethernet */
#define NETIO_UDP_PORT_JOOST             4166 /* Joost Peer to Peer Protocol */
#define NETIO_UDP_PORT_DDGN              4167 /* DeskDirect Global Network */
#define NETIO_UDP_PORT_PSLICSER          4168 /* PrintSoft License Server */
#define NETIO_UDP_PORT_IADT_DISC         4169 /* Internet ADT Discovery Protocol */
#define NETIO_UDP_PORT_PCOIP             4172 /* PC over IP */
#define NETIO_UDP_PORT_MMA_DISCOVERY     4173 /* MMA Device Discovery */
#define NETIO_UDP_PORT_SM_DISC           4174 /* StorMagic Discovery */
#define NETIO_UDP_PORT_WELLO             4177 /* Wello P2P pubsub service */
#define NETIO_UDP_PORT_STORMAN           4178 /* StorMan */
#define NETIO_UDP_PORT_MAXUMSP           4179 /* Maxum Services */
#define NETIO_UDP_PORT_HTTPX             4180 /* HTTPX */
#define NETIO_UDP_PORT_MACBAK            4181 /* MacBak */
#define NETIO_UDP_PORT_PCPTCPSERVICE     4182 /* Production Company Pro TCP Service */
#define NETIO_UDP_PORT_GMMP              4183 /* General Metaverse Messaging Protocol */
#define NETIO_UDP_PORT_UNIVERSE_SUITE    4184 /* "UNIVERSE SUITE MESSAGE SERVICE */
#define NETIO_UDP_PORT_WCPP              4185 /* Woven Control Plane Protocol */
#define NETIO_UDP_PORT_VATATA            4188 /* Vatata Peer to Peer Protocol */
#define NETIO_UDP_PORT_DSMIPV6           4191 /* Dual Stack MIPv6 NAT Traversal */
#define NETIO_UDP_PORT_AZETI_BD          4192 /* azeti blinddate */
#define NETIO_UDP_PORT_EIMS_ADMIN        4199 /* EIMS ADMIN */
#define NETIO_UDP_PORT_CORELCCAM         4300 /* Corel CCam */
#define NETIO_UDP_PORT_D_DATA            4301 /* Diagnostic Data */
#define NETIO_UDP_PORT_D_DATA_CONTROL    4302 /* Diagnostic Data Control */
#define NETIO_UDP_PORT_SRCP              4303 /* Simple Railroad Command Protocol */
#define NETIO_UDP_PORT_OWSERVER          4304 /* One-Wire Filesystem Server */
#define NETIO_UDP_PORT_BATMAN            4305 /* better approach to mobile ad-hoc networking */
#define NETIO_UDP_PORT_PINGHGL           4306 /* Hellgate London */
#define NETIO_UDP_PORT_VISICRON_VS       4307 /* Visicron Videoconference Service */
#define NETIO_UDP_PORT_COMPX_LOCKVIEW    4308 /* CompX-LockView */
#define NETIO_UDP_PORT_DSERVER           4309 /* Exsequi Appliance Discovery */
#define NETIO_UDP_PORT_MIRRTEX           4310 /* Mir-RT exchange service */
#define NETIO_UDP_PORT_FDT_RCATP         4320 /* FDT Remote Categorization Protocol */
#define NETIO_UDP_PORT_RWHOIS            4321 /* Remote Who Is */
#define NETIO_UDP_PORT_TRIM_EVENT        4322 /* TRIM Event Service */
#define NETIO_UDP_PORT_TRIM_ICE          4323 /* TRIM ICE Service */
#define NETIO_UDP_PORT_BALOUR            4324 /* Balour Game Server */
#define NETIO_UDP_PORT_GEOGNOSISMAN      4325 /* Cadcorp GeognoSIS Manager Service */
#define NETIO_UDP_PORT_GEOGNOSIS         4326 /* Cadcorp GeognoSIS Service */
#define NETIO_UDP_PORT_JAXER_WEB         4327 /* Jaxer Web Protocol */
#define NETIO_UDP_PORT_JAXER_MANAGER     4328 /* Jaxer Manager Command Protocol */
#define NETIO_UDP_PORT_AHSP              4333 /* ArrowHead Service Protocol (AHSP) */
#define NETIO_UDP_PORT_GAIA              4340 /* Gaia Connector Protocol */
#define NETIO_UDP_PORT_LISP_DATA         4341 /* LISP Data Packets */
#define NETIO_UDP_PORT_LISP_CONTROL      4342 /* LISP Control Packets */
#define NETIO_UDP_PORT_UNICALL           4343 /* UNICALL */
#define NETIO_UDP_PORT_VINAINSTALL       4344 /* VinaInstall */
#define NETIO_UDP_PORT_M4_NETWORK_AS     4345 /* Macro 4 Network AS */
#define NETIO_UDP_PORT_ELANLM            4346 /* ELAN LM */
#define NETIO_UDP_PORT_LANSURVEYOR       4347 /* LAN Surveyor */
#define NETIO_UDP_PORT_ITOSE             4348 /* ITOSE */
#define NETIO_UDP_PORT_FSPORTMAP         4349 /* File System Port Map */
#define NETIO_UDP_PORT_NET_DEVICE        4350 /* Net Device */
#define NETIO_UDP_PORT_PLCY_NET_SVCS     4351 /* PLCY Net Services */
#define NETIO_UDP_PORT_PJLINK            4352 /* Projector Link */
#define NETIO_UDP_PORT_F5_IQUERY         4353 /* F5 iQuery */
#define NETIO_UDP_PORT_QSNET_TRANS       4354 /* QSNet Transmitter */
#define NETIO_UDP_PORT_QSNET_WORKST      4355 /* QSNet Workstation */
#define NETIO_UDP_PORT_QSNET_ASSIST      4356 /* QSNet Assistant */
#define NETIO_UDP_PORT_QSNET_COND        4357 /* QSNet Conductor */
#define NETIO_UDP_PORT_QSNET_NUCL        4358 /* QSNet Nucleus */
#define NETIO_UDP_PORT_OMABCASTLTKM      4359 /* OMA BCAST Long-Term Key Messages */
#define NETIO_UDP_PORT_NACNL             4361 /* NavCom Discovery and Control Port */
#define NETIO_UDP_PORT_AFORE_VDP_DISC    4362 /* AFORE vNode Discovery protocol */
#define NETIO_UDP_PORT_WXBRIEF           4368 /* WeatherBrief Direct */
#define NETIO_UDP_PORT_EPMD              4369 /* Erlang Port Mapper Daemon */
#define NETIO_UDP_PORT_ELPRO_TUNNEL      4370 /* "ELPRO V2 Protocol Tunnel */
#define NETIO_UDP_PORT_L2C_DISC          4371 /* LAN2CAN Discovery */
#define NETIO_UDP_PORT_L2C_DATA          4372 /* LAN2CAN Data */
#define NETIO_UDP_PORT_REMCTL            4373 /* Remote Authenticated Command Service */
#define NETIO_UDP_PORT_TOLTECES          4375 /* Toltec EasyShare */
#define NETIO_UDP_PORT_BIP               4376 /* BioAPI Interworking */
#define NETIO_UDP_PORT_CP_SPXSVR         4377 /* Cambridge Pixel SPx Server */
#define NETIO_UDP_PORT_CP_SPXDPY         4378 /* Cambridge Pixel SPx Display */
#define NETIO_UDP_PORT_CTDB              4379 /* CTDB */
#define NETIO_UDP_PORT_XANDROS_CMS       4389 /* Xandros Community Management Service */
#define NETIO_UDP_PORT_WIEGAND           4390 /* Physical Access Control */
#define NETIO_UDP_PORT_APWI_DISC         4394 /* American Printware Discovery */
#define NETIO_UDP_PORT_OMNIVISIONESX     4395 /* OmniVision communication for Virtual environments */
#define NETIO_UDP_PORT_DS_SRV            4400 /* ASIGRA Services */
#define NETIO_UDP_PORT_DS_SRVR           4401 /* ASIGRA Televaulting DS-System Service */
#define NETIO_UDP_PORT_DS_CLNT           4402 /* ASIGRA Televaulting DS-Client Service */
#define NETIO_UDP_PORT_DS_USER           4403 /* ASIGRA Televaulting DS-Client Monitoring/Management */
#define NETIO_UDP_PORT_DS_ADMIN          4404 /* ASIGRA Televaulting DS-System Monitoring/Management */
#define NETIO_UDP_PORT_DS_MAIL           4405 /* ASIGRA Televaulting Message Level Restore service */
#define NETIO_UDP_PORT_DS_SLP            4406 /* ASIGRA Televaulting DS-Sleeper Service */
#define NETIO_UDP_PORT_NETROCKEY6        4425 /* NetROCKEY6 SMART Plus Service */
#define NETIO_UDP_PORT_BEACON_PORT_2     4426 /* SMARTS Beacon Port */
#define NETIO_UDP_PORT_RSQLSERVER        4430 /* REAL SQL Server */
#define NETIO_UDP_PORT_L_ACOUSTICS       4432 /* L-ACOUSTICS management */
#define NETIO_UDP_PORT_NETBLOX           4441 /* Netblox Protocol */
#define NETIO_UDP_PORT_SARIS             4442 /* Saris */
#define NETIO_UDP_PORT_PHAROS            4443 /* Pharos */
#define NETIO_UDP_PORT_KRB524            4444 /* KRB524 */
#define NETIO_UDP_PORT_UPNOTIFYP         4445 /* UPNOTIFYP */
#define NETIO_UDP_PORT_N1_FWP            4446 /* N1-FWP */
#define NETIO_UDP_PORT_N1_RMGMT          4447 /* N1-RMGMT */
#define NETIO_UDP_PORT_ASC_SLMD          4448 /* ASC Licence Manager */
#define NETIO_UDP_PORT_PRIVATEWIRE       4449 /* PrivateWire */
#define NETIO_UDP_PORT_CAMP              4450 /* Common ASCII Messaging Protocol */
#define NETIO_UDP_PORT_CTISYSTEMMSG      4451 /* CTI System Msg */
#define NETIO_UDP_PORT_CTIPROGRAMLOAD    4452 /* CTI Program Load */
#define NETIO_UDP_PORT_NSSALERTMGR       4453 /* NSS Alert Manager */
#define NETIO_UDP_PORT_NSSAGENTMGR       4454 /* NSS Agent Manager */
#define NETIO_UDP_PORT_PRCHAT_USER       4455 /* PR Chat User */
#define NETIO_UDP_PORT_PRCHAT_SERVER     4456 /* PR Chat Server */
#define NETIO_UDP_PORT_PRREGISTER        4457 /* PR Register */
#define NETIO_UDP_PORT_MCP               4458 /* Matrix Configuration Protocol */
#define NETIO_UDP_PORT_HPSSMGMT          4484 /* hpssmgmt service */
#define NETIO_UDP_PORT_ICMS              4486 /* Integrated Client Message Service */
#define NETIO_UDP_PORT_AWACS_ICE         4488 /* Apple Wide Area Connectivity Service ICE Bootstrap */
#define NETIO_UDP_PORT_IPSEC_NAT_T       4500 /* IPsec NAT-Traversal */
#define NETIO_UDP_PORT_ARMAGETRONAD      4534 /* Armagetron Advanced Game Server */
#define NETIO_UDP_PORT_EHS               4535 /* Event Heap Server */
#define NETIO_UDP_PORT_EHS_SSL           4536 /* Event Heap Server SSL */
#define NETIO_UDP_PORT_WSSAUTHSVC        4537 /* WSS Security Service */
#define NETIO_UDP_PORT_SWX_GATE          4538 /* Software Data Exchange Gateway */
#define NETIO_UDP_PORT_WORLDSCORES       4545 /* WorldScores */
#define NETIO_UDP_PORT_SF_LM             4546 /* SF License Manager (Sentinel) */
#define NETIO_UDP_PORT_LANNER_LM         4547 /* Lanner License Manager */
#define NETIO_UDP_PORT_SYNCHROMESH       4548 /* Synchromesh */
#define NETIO_UDP_PORT_AEGATE            4549 /* Aegate PMR Service */
#define NETIO_UDP_PORT_GDS_ADPPIW_DB     4550 /* Perman I Interbase Server */
#define NETIO_UDP_PORT_IEEE_MIH          4551 /* MIH Services */
#define NETIO_UDP_PORT_MENANDMICE_MON    4552 /* Men and Mice Monitoring */
#define NETIO_UDP_PORT_MSFRS             4554 /* MS FRS Replication */
#define NETIO_UDP_PORT_RSIP              4555 /* RSIP Port */
#define NETIO_UDP_PORT_DTN_BUNDLE        4556 /* DTN Bundle UDP CL Protocol */
#define NETIO_UDP_PORT_MTCEVRUNQSS       4557 /* Marathon everRun Quorum Service Server */
#define NETIO_UDP_PORT_MTCEVRUNQMAN      4558 /* Marathon everRun Quorum Service Manager */
#define NETIO_UDP_PORT_HYLAFAX           4559 /* HylaFAX */
#define NETIO_UDP_PORT_KWTC              4566 /* Kids Watch Time Control Service */
#define NETIO_UDP_PORT_TRAM              4567 /* TRAM */
#define NETIO_UDP_PORT_BMC_REPORTING     4568 /* BMC Reporting */
#define NETIO_UDP_PORT_IAX               4569 /* Inter-Asterisk eXchange */
#define NETIO_UDP_PORT_L3T_AT_AN         4591 /* HRPD L3T (AT-AN) */
#define NETIO_UDP_PORT_HRPD_ITH_AT_AN    4592 /* HRPD-ITH (AT-AN) */
#define NETIO_UDP_PORT_IPT_ANRI_ANRI     4593 /* IPT (ANRI-ANRI) */
#define NETIO_UDP_PORT_IAS_SESSION       4594 /* IAS-Session (ANRI-ANRI) */
#define NETIO_UDP_PORT_IAS_PAGING        4595 /* IAS-Paging (ANRI-ANRI) */
#define NETIO_UDP_PORT_IAS_NEIGHBOR      4596 /* IAS-Neighbor (ANRI-ANRI) */
#define NETIO_UDP_PORT_A21_AN_1XBS       4597 /* A21 (AN-1xBS) */
#define NETIO_UDP_PORT_A16_AN_AN         4598 /* A16 (AN-AN) */
#define NETIO_UDP_PORT_A17_AN_AN         4599 /* A17 (AN-AN) */
#define NETIO_UDP_PORT_PIRANHA1          4600 /* Piranha1 */
#define NETIO_UDP_PORT_PIRANHA2          4601 /* Piranha2 */
#define NETIO_UDP_PORT_PLAYSTA2_APP      4658 /* PlayStation2 App Port */
#define NETIO_UDP_PORT_PLAYSTA2_LOB      4659 /* PlayStation2 Lobby Port */
#define NETIO_UDP_PORT_SMACLMGR          4660 /* smaclmgr */
#define NETIO_UDP_PORT_KAR2OUCHE         4661 /* Kar2ouche Peer location service */
#define NETIO_UDP_PORT_OMS               4662 /* OrbitNet Message Service */
#define NETIO_UDP_PORT_NOTEIT            4663 /* Note It! Message Service */
#define NETIO_UDP_PORT_EMS               4664 /* Rimage Messaging Server */
#define NETIO_UDP_PORT_CONTCLIENTMS      4665 /* Container Client Message Service */
#define NETIO_UDP_PORT_EPORTCOMM         4666 /* E-Port Message Service */
#define NETIO_UDP_PORT_MMACOMM           4667 /* MMA Comm Services */
#define NETIO_UDP_PORT_MMAEDS            4668 /* MMA EDS Service */
#define NETIO_UDP_PORT_EPORTCOMMDATA     4669 /* E-Port Data Service */
#define NETIO_UDP_PORT_LIGHT             4670 /* Light packets transfer protocol */
#define NETIO_UDP_PORT_ACTER             4671 /* Bull RSF action server */
#define NETIO_UDP_PORT_RFA               4672 /* remote file access server */
#define NETIO_UDP_PORT_CXWS              4673 /* CXWS Operations */
#define NETIO_UDP_PORT_APPIQ_MGMT        4674 /* AppIQ Agent Management */
#define NETIO_UDP_PORT_DHCT_STATUS       4675 /* BIAP Device Status */
#define NETIO_UDP_PORT_DHCT_ALERTS       4676 /* BIAP Generic Alert */
#define NETIO_UDP_PORT_BCS               4677 /* Business Continuity Servi */
#define NETIO_UDP_PORT_TRAVERSAL         4678 /* boundary traversal */
#define NETIO_UDP_PORT_MGESUPERVISION    4679 /* MGE UPS Supervision */
#define NETIO_UDP_PORT_MGEMANAGEMENT     4680 /* MGE UPS Management */
#define NETIO_UDP_PORT_PARLIANT          4681 /* Parliant Telephony System */
#define NETIO_UDP_PORT_FINISAR           4682 /* finisar */
#define NETIO_UDP_PORT_SPIKE             4683 /* Spike Clipboard Service */
#define NETIO_UDP_PORT_RFID_RP1          4684 /* RFID Reader Protocol 1.0 */
#define NETIO_UDP_PORT_AUTOPAC           4685 /* Autopac Protocol */
#define NETIO_UDP_PORT_MSP_OS            4686 /* Manina Service Protocol */
#define NETIO_UDP_PORT_NST               4687 /* Network Scanner Tool FTP */
#define NETIO_UDP_PORT_MOBILE_P2P        4688 /* Mobile P2P Service */
#define NETIO_UDP_PORT_ALTOVACENTRAL     4689 /* Altova DatabaseCentral */
#define NETIO_UDP_PORT_PRELUDE           4690 /* Prelude IDS message proto */
#define NETIO_UDP_PORT_MTN               4691 /* monotone Netsync Protocol */
#define NETIO_UDP_PORT_CONSPIRACY        4692 /* Conspiracy messaging */
#define NETIO_UDP_PORT_NETXMS_AGENT      4700 /* NetXMS Agent */
#define NETIO_UDP_PORT_NETXMS_MGMT       4701 /* NetXMS Management */
#define NETIO_UDP_PORT_NETXMS_SYNC       4702 /* NetXMS Server Synchronization */
#define NETIO_UDP_PORT_TRUCKSTAR         4725 /* TruckStar Service */
#define NETIO_UDP_PORT_A26_FAP_FGW       4726 /* A26 (FAP-FGW) */
#define NETIO_UDP_PORT_FCIS_DISC         4727 /* F-Link Client Information Service Discovery */
#define NETIO_UDP_PORT_CAPMUX            4728 /* CA Port Multiplexer */
#define NETIO_UDP_PORT_GSMTAP            4729 /* GSM Interface Tap */
#define NETIO_UDP_PORT_GEARMAN           4730 /* Gearman Job Queue System */
#define NETIO_UDP_PORT_OHMTRIGGER        4732 /* OHM server trigger */
#define NETIO_UDP_PORT_IPDR_SP           4737 /* IPDR/SP */
#define NETIO_UDP_PORT_SOLERA_LPN        4738 /* SoleraTec Locator */
#define NETIO_UDP_PORT_IPFIX             4739 /* IP Flow Info Export */
#define NETIO_UDP_PORT_IPFIXS            4740 /* ipfix protocol over DTLS */
#define NETIO_UDP_PORT_LUMIMGRD          4741 /* Luminizer Manager */
#define NETIO_UDP_PORT_SICCT_SDP         4742 /* SICCT Service Discovery Protocol */
#define NETIO_UDP_PORT_OPENHPID          4743 /* openhpi HPI service */
#define NETIO_UDP_PORT_IFSP              4744 /* Internet File Synchronization Protocol */
#define NETIO_UDP_PORT_FMP               4745 /* Funambol Mobile Push */
#define NETIO_UDP_PORT_BUSCHTROMMEL      4747 /* peer-to-peer file exchange protocol */
#define NETIO_UDP_PORT_PROFILEMAC        4749 /* Profile for Mac */
#define NETIO_UDP_PORT_SSAD              4750 /* Simple Service Auto Discovery */
#define NETIO_UDP_PORT_SPOCP             4751 /* Simple Policy Control Protocol */
#define NETIO_UDP_PORT_SNAP              4752 /* Simple Network Audio Protocol */
#define NETIO_UDP_PORT_SIMON_DISC        4753 /* Simple Invocation of Methods Over Network (SIMON) Discovery */
#define NETIO_UDP_PORT_BFD_MULTI_CTL     4784 /* BFD Multihop Control */
#define NETIO_UDP_PORT_CNCP              4785 /* Cisco Nexus Control Protocol */
#define NETIO_UDP_PORT_VXLAN             4789 /* Virtual eXtensible Local Area Network (VXLAN) */
#define NETIO_UDP_PORT_IIMS              4800 /* Icona Instant Messenging System */
#define NETIO_UDP_PORT_IWEC              4801 /* Icona Web Embedded Chat */
#define NETIO_UDP_PORT_ILSS              4802 /* Icona License System Server */
#define NETIO_UDP_PORT_NOTATEIT_DISC     4803 /* Notateit Messaging Discovery */
#define NETIO_UDP_PORT_AJA_NTV4_DISC     4804 /* AJA ntv4 Video System Discovery */
#define NETIO_UDP_PORT_HTCP              4827 /* HTCP */
#define NETIO_UDP_PORT_VARADERO_0        4837 /* Varadero-0 */
#define NETIO_UDP_PORT_VARADERO_1        4838 /* Varadero-1 */
#define NETIO_UDP_PORT_VARADERO_2        4839 /* Varadero-2 */
#define NETIO_UDP_PORT_OPCUA_UDP         4840 /* OPC UA TCP Protocol */
#define NETIO_UDP_PORT_QUOSA             4841 /* QUOSA Virtual Library Service */
#define NETIO_UDP_PORT_GW_ASV            4842 /* nCode ICE-flow Library AppServer */
#define NETIO_UDP_PORT_OPCUA_TLS         4843 /* OPC UA TCP Protocol over TLS/SSL */
#define NETIO_UDP_PORT_GW_LOG            4844 /* nCode ICE-flow Library LogServer */
#define NETIO_UDP_PORT_WCR_REMLIB        4845 /* WordCruncher Remote Library Service */
#define NETIO_UDP_PORT_CONTAMAC_ICM      4846 /* "Contamac ICM Service */
#define NETIO_UDP_PORT_WFC               4847 /* Web Fresh Communication */
#define NETIO_UDP_PORT_APPSERV_HTTP      4848 /* App Server - Admin HTTP */
#define NETIO_UDP_PORT_APPSERV_HTTPS     4849 /* App Server - Admin HTTPS */
#define NETIO_UDP_PORT_SUN_AS_NODEAGT    4850 /* Sun App Server - NA */
#define NETIO_UDP_PORT_DERBY_REPLI       4851 /* Apache Derby Replication */
#define NETIO_UDP_PORT_UNIFY_DEBUG       4867 /* Unify Debugger */
#define NETIO_UDP_PORT_PHRELAY           4868 /* Photon Relay */
#define NETIO_UDP_PORT_PHRELAYDBG        4869 /* Photon Relay Debug */
#define NETIO_UDP_PORT_CC_TRACKING       4870 /* Citcom Tracking Service */
#define NETIO_UDP_PORT_WIRED             4871 /* Wired */
#define NETIO_UDP_PORT_TRITIUM_CAN       4876 /* Tritium CAN Bus Bridge Service */
#define NETIO_UDP_PORT_LMCS              4877 /* Lighting Management Control System */
#define NETIO_UDP_PORT_INST_DISCOVERY    4878 /* Agilent Instrument Discovery */
#define NETIO_UDP_PORT_SOCP_T            4881 /* SOCP Time Synchronization Protocol */
#define NETIO_UDP_PORT_SOCP_C            4882 /* SOCP Control Protocol */
#define NETIO_UDP_PORT_HIVESTOR          4884 /* HiveStor Distributed File System */
#define NETIO_UDP_PORT_ABBS              4885 /* ABBS */
#define NETIO_UDP_PORT_LYSKOM            4894 /* LysKOM Protocol A */
#define NETIO_UDP_PORT_RADMIN_PORT       4899 /* RAdmin Port */
#define NETIO_UDP_PORT_HFCS              4900 /* HFSQL Client/Server Database Engine */
#define NETIO_UDP_PORT_BONES             4914 /* Bones Remote Control */
#define NETIO_UDP_PORT_AN_SIGNALING      4936 /* Signal protocol port for autonomic networking */
#define NETIO_UDP_PORT_ATSC_MH_SSC       4937 /* ATSC-M/H Service Signaling Channel */
#define NETIO_UDP_PORT_EQ_OFFICE_4940    4940 /* Equitrac Office */
#define NETIO_UDP_PORT_EQ_OFFICE_4941    4941 /* Equitrac Office */
#define NETIO_UDP_PORT_EQ_OFFICE_4942    4942 /* Equitrac Office */
#define NETIO_UDP_PORT_MUNIN             4949 /* Munin Graphing Framework */
#define NETIO_UDP_PORT_SYBASESRVMON      4950 /* Sybase Server Monitor */
#define NETIO_UDP_PORT_PWGWIMS           4951 /* PWG WIMS */
#define NETIO_UDP_PORT_SAGXTSDS          4952 /* SAG Directory Server */
#define NETIO_UDP_PORT_CCSS_QMM          4969 /* CCSS QMessageMonitor */
#define NETIO_UDP_PORT_CCSS_QSM          4970 /* CCSS QSystemMonitor */
#define NETIO_UDP_PORT_MRIP              4986 /* Model Railway Interface Program */
#define NETIO_UDP_PORT_SMAR_SE_PORT1     4987 /* SMAR Ethernet Port 1 */
#define NETIO_UDP_PORT_SMAR_SE_PORT2     4988 /* SMAR Ethernet Port 2 */
#define NETIO_UDP_PORT_PARALLEL          4989 /* Parallel for GAUSS (tm) */
#define NETIO_UDP_PORT_BUSYCAL           4990 /* BusySync Calendar Synch. Protocol */
#define NETIO_UDP_PORT_VRT               4991 /* VITA Radio Transport */
#define NETIO_UDP_PORT_HFCS_MANAGER      4999 /* HFSQL Client/Server Database Engine Manager */
#define NETIO_UDP_PORT_RFE               5002 /* radio free ethernet */
#define NETIO_UDP_PORT_FMPRO_INTERNAL    5003 /* "FileMaker */
#define NETIO_UDP_PORT_AVT_PROFILE_1     5004 /* RTP media data */
#define NETIO_UDP_PORT_AVT_PROFILE_2     5005 /* RTP control protocol */
#define NETIO_UDP_PORT_WSM_SERVER        5006 /* wsm server */
#define NETIO_UDP_PORT_WSM_SERVER_SSL    5007 /* wsm server ssl */
#define NETIO_UDP_PORT_SYNAPSIS_EDGE     5008 /* Synapsis EDGE */
#define NETIO_UDP_PORT_WINFS             5009 /* Microsoft Windows Filesystem */
#define NETIO_UDP_PORT_TELELPATHSTART    5010 /* TelepathStart */
#define NETIO_UDP_PORT_TELELPATHATTACK   5011 /* TelepathAttack */
#define NETIO_UDP_PORT_NSP               5012 /* NetOnTap Service */
#define NETIO_UDP_PORT_FMPRO_V6          5013 /* "FileMaker */
#define NETIO_UDP_PORT_ONPSOCKET         5014 /* Overlay Network Protocol */
#define NETIO_UDP_PORT_ZENGINKYO_1       5020 /* zenginkyo-1 */
#define NETIO_UDP_PORT_ZENGINKYO_2       5021 /* zenginkyo-2 */
#define NETIO_UDP_PORT_MICE              5022 /* mice server */
#define NETIO_UDP_PORT_HTUILSRV          5023 /* Htuil Server for PLD2 */
#define NETIO_UDP_PORT_SCPI_TELNET       5024 /* SCPI-TELNET */
#define NETIO_UDP_PORT_SCPI_RAW          5025 /* SCPI-RAW */
#define NETIO_UDP_PORT_STREXEC_D         5026 /* Storix I/O daemon (data) */
#define NETIO_UDP_PORT_STREXEC_S         5027 /* Storix I/O daemon (stat) */
#define NETIO_UDP_PORT_INFOBRIGHT        5029 /* Infobright Database Server */
#define NETIO_UDP_PORT_SURFPASS          5030 /* SurfPass */
#define NETIO_UDP_PORT_DMP               5031 /* Direct Message Protocol */
#define NETIO_UDP_PORT_ASNAACCELER8DB    5042 /* asnaacceler8db */
#define NETIO_UDP_PORT_SWXADMIN          5043 /* ShopWorX Administration */
#define NETIO_UDP_PORT_LXI_EVNTSVC       5044 /* LXI Event Service */
#define NETIO_UDP_PORT_VPM_UDP           5046 /* Vishay PM UDP Service */
#define NETIO_UDP_PORT_ISCAPE            5047 /* iSCAPE Data Broadcasting */
#define NETIO_UDP_PORT_IVOCALIZE         5049 /* iVocalize Web Conference */
#define NETIO_UDP_PORT_MMCC              5050 /* multimedia conference control tool */
#define NETIO_UDP_PORT_ITA_AGENT         5051 /* ITA Agent */
#define NETIO_UDP_PORT_ITA_MANAGER       5052 /* ITA Manager */
#define NETIO_UDP_PORT_RLM_DISC          5053 /* RLM Discovery Server */
#define NETIO_UDP_PORT_UNOT              5055 /* UNOT */
#define NETIO_UDP_PORT_INTECOM_PS1       5056 /* Intecom Pointspan 1 */
#define NETIO_UDP_PORT_INTECOM_PS2       5057 /* Intecom Pointspan 2 */
#define NETIO_UDP_PORT_LOCUS_DISC        5058 /* Locus Discovery */
#define NETIO_UDP_PORT_SDS               5059 /* SIP Directory Services */
#define NETIO_UDP_PORT_SIP               5060 /* SIP */
#define NETIO_UDP_PORT_SIPS              5061 /* SIP-TLS */
#define NETIO_UDP_PORT_NA_LOCALISE       5062 /* Localisation access */
#define NETIO_UDP_PORT_CA_1              5064 /* Channel Access 1 */
#define NETIO_UDP_PORT_CA_2              5065 /* Channel Access 2 */
#define NETIO_UDP_PORT_STANAG_5066       5066 /* STANAG-5066-SUBNET-INTF */
#define NETIO_UDP_PORT_AUTHENTX          5067 /* Authentx Service */
#define NETIO_UDP_PORT_I_NET_2000_NPR    5069 /* I/Net 2000-NPR */
#define NETIO_UDP_PORT_VTSAS             5070 /* VersaTrans Server Agent Service */
#define NETIO_UDP_PORT_POWERSCHOOL       5071 /* PowerSchool */
#define NETIO_UDP_PORT_AYIYA             5072 /* Anything In Anything */
#define NETIO_UDP_PORT_TAG_PM            5073 /* Advantage Group Port Mgr */
#define NETIO_UDP_PORT_ALESQUERY         5074 /* ALES Query */
#define NETIO_UDP_PORT_PIXELPUSHER       5078 /* PixelPusher pixel data */
#define NETIO_UDP_PORT_CP_SPXRPTS        5079 /* Cambridge Pixel SPx Reports */
#define NETIO_UDP_PORT_ONSCREEN          5080 /* OnScreen Data Collection Service */
#define NETIO_UDP_PORT_SDL_ETS           5081 /* SDL - Ent Trans Server */
#define NETIO_UDP_PORT_QCP               5082 /* Qpur Communication Protocol */
#define NETIO_UDP_PORT_QFP               5083 /* Qpur File Protocol */
#define NETIO_UDP_PORT_LLRP              5084 /* EPCglobal Low-Level Reader Protocol */
#define NETIO_UDP_PORT_ENCRYPTED_LLRP    5085 /* EPCglobal Encrypted LLRP */
#define NETIO_UDP_PORT_MAGPIE            5092 /* Magpie Binary */
#define NETIO_UDP_PORT_SENTINEL_LM       5093 /* Sentinel LM */
#define NETIO_UDP_PORT_HART_IP           5094 /* HART-IP */
#define NETIO_UDP_PORT_SENTLM_SRV2SRV    5099 /* SentLM Srv2Srv */
#define NETIO_UDP_PORT_SOCALIA           5100 /* Socalia service mux */
#define NETIO_UDP_PORT_TALARIAN_UDP      5101 /* Talarian_UDP */
#define NETIO_UDP_PORT_OMS_NONSECURE     5102 /* Oracle OMS non-secure */
#define NETIO_UDP_PORT_TINYMESSAGE       5104 /* TinyMessage */
#define NETIO_UDP_PORT_HUGHES_AP         5105 /* Hughes Association Protocol */
#define NETIO_UDP_PORT_TAEP_AS_SVC       5111 /* TAEP AS service */
#define NETIO_UDP_PORT_PM_CMDSVR         5112 /* PeerMe Msg Cmd Service */
#define NETIO_UDP_PORT_EMB_PROJ_CMD      5116 /* EPSON Projecter Image Transfer */
#define NETIO_UDP_PORT_BARRACUDA_BBS     5120 /* Barracuda Backup Protocol */
#define NETIO_UDP_PORT_NBT_PC            5133 /* Policy Commander */
#define NETIO_UDP_PORT_MINOTAUR_SA       5136 /* Minotaur SA */
#define NETIO_UDP_PORT_CTSD              5137 /* MyCTS server port */
#define NETIO_UDP_PORT_RMONITOR_SECURE   5145 /* "RMONITOR SECURE */
#define NETIO_UDP_PORT_ATMP              5150 /* Ascend Tunnel Management Protocol */
#define NETIO_UDP_PORT_ESRI_SDE          5151 /* "ESRI SDE Remote Start */
#define NETIO_UDP_PORT_SDE_DISCOVERY     5152 /* ESRI SDE Instance Discovery */
#define NETIO_UDP_PORT_BZFLAG            5154 /* BZFlag game server */
#define NETIO_UDP_PORT_ASCTRL_AGENT      5155 /* Oracle asControl Agent */
#define NETIO_UDP_PORT_VPA_DISC          5164 /* Virtual Protocol Adapter Discovery */
#define NETIO_UDP_PORT_IFE_ICORP         5165 /* "ife_1corp */
#define NETIO_UDP_PORT_WINPCS            5166 /* WinPCS Service Connection */
#define NETIO_UDP_PORT_SCTE104           5167 /* SCTE104 Connection */
#define NETIO_UDP_PORT_SCTE30            5168 /* SCTE30 Connection */
#define NETIO_UDP_PORT_AOL               5190 /* America-Online */
#define NETIO_UDP_PORT_AOL_1             5191 /* AmericaOnline1 */
#define NETIO_UDP_PORT_AOL_2             5192 /* AmericaOnline2 */
#define NETIO_UDP_PORT_AOL_3             5193 /* AmericaOnline3 */
#define NETIO_UDP_PORT_TARGUS_GETDATA    5200 /* TARGUS GetData */
#define NETIO_UDP_PORT_TARGUS_GETDATA1   5201 /* TARGUS GetData 1 */
#define NETIO_UDP_PORT_TARGUS_GETDATA2   5202 /* TARGUS GetData 2 */
#define NETIO_UDP_PORT_TARGUS_GETDATA3   5203 /* TARGUS GetData 3 */
#define NETIO_UDP_PORT_HPVIRTGRP         5223 /* HP Virtual Machine Group Management */
#define NETIO_UDP_PORT_HPVIRTCTRL        5224 /* HP Virtual Machine Console Operations */
#define NETIO_UDP_PORT_HP_SERVER         5225 /* HP Server */
#define NETIO_UDP_PORT_HP_STATUS         5226 /* HP Status */
#define NETIO_UDP_PORT_PERFD             5227 /* HP System Performance Metric Service */
#define NETIO_UDP_PORT_EENET             5234 /* EEnet communications */
#define NETIO_UDP_PORT_GALAXY_NETWORK    5235 /* Galaxy Network Service */
#define NETIO_UDP_PORT_MNET_DISCOVERY    5237 /* m-net discovery */
#define NETIO_UDP_PORT_DOWNTOOLS_DISC    5245 /* DownTools Discovery Protocol */
#define NETIO_UDP_PORT_CAPWAP_CONTROL    5246 /* CAPWAP Control Protocol */
#define NETIO_UDP_PORT_CAPWAP_DATA       5247 /* CAPWAP Data Protocol */
#define NETIO_UDP_PORT_CAACWS            5248 /* CA Access Control Web Service */
#define NETIO_UDP_PORT_CAACLANG2         5249 /* CA AC Lang Service */
#define NETIO_UDP_PORT_SOAGATEWAY        5250 /* soaGateway */
#define NETIO_UDP_PORT_CAEVMS            5251 /* CA eTrust VM Service */
#define NETIO_UDP_PORT_MOVAZ_SSC         5252 /* Movaz SSC */
#define NETIO_UDP_PORT_3COM_NJACK_1      5264 /* 3Com Network Jack Port 1 */
#define NETIO_UDP_PORT_3COM_NJACK_2      5265 /* 3Com Network Jack Port 2 */
#define NETIO_UDP_PORT_CARTOGRAPHERXMP   5270 /* Cartographer XMP */
#define NETIO_UDP_PORT_CUELINK_DISC      5271 /* StageSoft CueLink discovery */
#define NETIO_UDP_PORT_PK                5272 /* PK */
#define NETIO_UDP_PORT_TRANSMIT_PORT     5282 /* Marimba Transmitter Port */
#define NETIO_UDP_PORT_PRESENCE          5298 /* XMPP Link-Local Messaging */
#define NETIO_UDP_PORT_NLG_DATA          5299 /* NLG Data Service */
#define NETIO_UDP_PORT_HACL_HB           5300 /* HA cluster heartbeat */
#define NETIO_UDP_PORT_HACL_GS           5301 /* HA cluster general services */
#define NETIO_UDP_PORT_HACL_CFG          5302 /* HA cluster configuration */
#define NETIO_UDP_PORT_HACL_PROBE        5303 /* HA cluster probing */
#define NETIO_UDP_PORT_HACL_LOCAL        5304 /* HA Cluster Commands */
#define NETIO_UDP_PORT_HACL_TEST         5305 /* HA Cluster Test */
#define NETIO_UDP_PORT_SUN_MC_GRP        5306 /* Sun MC Group */
#define NETIO_UDP_PORT_SCO_AIP           5307 /* SCO AIP */
#define NETIO_UDP_PORT_CFENGINE          5308 /* CFengine */
#define NETIO_UDP_PORT_JPRINTER          5309 /* J Printer */
#define NETIO_UDP_PORT_OUTLAWS           5310 /* Outlaws */
#define NETIO_UDP_PORT_PERMABIT_CS       5312 /* Permabit Client-Server */
#define NETIO_UDP_PORT_RRDP              5313 /* Real-time & Reliable Data */
#define NETIO_UDP_PORT_OPALIS_RBT_IPC    5314 /* opalis-rbt-ipc */
#define NETIO_UDP_PORT_HACL_POLL         5315 /* HA Cluster UDP Polling */
#define NETIO_UDP_PORT_KFSERVER          5343 /* Sculptor Database Server */
#define NETIO_UDP_PORT_XKOTODRCP         5344 /* xkoto DRCP */
#define NETIO_UDP_PORT_STUNS             5349 /* STUN over DTLS */
#define NETIO_UDP_PORT_PCP_MULTICAST     5350 /* Port Control Protocol Multicast */
#define NETIO_UDP_PORT_PCP               5351 /* Port Control Protocol */
#define NETIO_UDP_PORT_DNS_LLQ           5352 /* DNS Long-Lived Queries */
#define NETIO_UDP_PORT_MDNS              5353 /* Multicast DNS */
#define NETIO_UDP_PORT_MDNSRESPONDER     5354 /* Multicast DNS Responder IPC */
#define NETIO_UDP_PORT_LLMNR             5355 /* LLMNR */
#define NETIO_UDP_PORT_MS_SMLBIZ         5356 /* Microsoft Small Business */
#define NETIO_UDP_PORT_WSDAPI            5357 /* Web Services for Devices */
#define NETIO_UDP_PORT_WSDAPI_S          5358 /* WS for Devices Secured */
#define NETIO_UDP_PORT_MS_ALERTER        5359 /* Microsoft Alerter */
#define NETIO_UDP_PORT_MS_SIDESHOW       5360 /* Protocol for Windows SideShow */
#define NETIO_UDP_PORT_MS_S_SIDESHOW     5361 /* Secure Protocol for Windows SideShow */
#define NETIO_UDP_PORT_SERVERWSD2        5362 /* Microsoft Windows Server WSD2 Service */
#define NETIO_UDP_PORT_NET_PROJECTION    5363 /* Windows Network Projection */
#define NETIO_UDP_PORT_KDNET             5364 /* Microsoft Kernel Debugger */
#define NETIO_UDP_PORT_STRESSTESTER      5397 /* StressTester(tm) Injector */
#define NETIO_UDP_PORT_ELEKTRON_ADMIN    5398 /* Elektron Administration */
#define NETIO_UDP_PORT_SECURITYCHASE     5399 /* SecurityChase */
#define NETIO_UDP_PORT_EXCERPT           5400 /* Excerpt Search */
#define NETIO_UDP_PORT_EXCERPTS          5401 /* Excerpt Search Secure */
#define NETIO_UDP_PORT_MFTP2             5402 /* OmniCast MFTP */
#define NETIO_UDP_PORT_HPOMS_CI_LSTN     5403 /* HPOMS-CI-LSTN */
#define NETIO_UDP_PORT_HPOMS_DPS_LSTN    5404 /* HPOMS-DPS-LSTN */
#define NETIO_UDP_PORT_NETSUPPORT        5405 /* NetSupport */
#define NETIO_UDP_PORT_SYSTEMICS_SOX     5406 /* Systemics Sox */
#define NETIO_UDP_PORT_FORESYTE_CLEAR    5407 /* Foresyte-Clear */
#define NETIO_UDP_PORT_FORESYTE_SEC      5408 /* Foresyte-Sec */
#define NETIO_UDP_PORT_SALIENT_DTASRV    5409 /* Salient Data Server */
#define NETIO_UDP_PORT_SALIENT_USRMGR    5410 /* Salient User Manager */
#define NETIO_UDP_PORT_ACTNET            5411 /* ActNet */
#define NETIO_UDP_PORT_CONTINUUS         5412 /* Continuus */
#define NETIO_UDP_PORT_WWIOTALK          5413 /* WWIOTALK */
#define NETIO_UDP_PORT_STATUSD           5414 /* StatusD */
#define NETIO_UDP_PORT_NS_SERVER         5415 /* NS Server */
#define NETIO_UDP_PORT_SNS_GATEWAY       5416 /* SNS Gateway */
#define NETIO_UDP_PORT_SNS_AGENT         5417 /* SNS Agent */
#define NETIO_UDP_PORT_MCNTP             5418 /* MCNTP */
#define NETIO_UDP_PORT_DJ_ICE            5419 /* DJ-ICE */
#define NETIO_UDP_PORT_CYLINK_C          5420 /* Cylink-C */
#define NETIO_UDP_PORT_NETSUPPORT2       5421 /* Net Support 2 */
#define NETIO_UDP_PORT_SALIENT_MUX       5422 /* Salient MUX */
#define NETIO_UDP_PORT_VIRTUALUSER       5423 /* VIRTUALUSER */
#define NETIO_UDP_PORT_BEYOND_REMOTE     5424 /* Beyond Remote */
#define NETIO_UDP_PORT_BR_CHANNEL        5425 /* Beyond Remote Command Channel */
#define NETIO_UDP_PORT_DEVBASIC          5426 /* DEVBASIC */
#define NETIO_UDP_PORT_SCO_PEER_TTA      5427 /* SCO-PEER-TTA */
#define NETIO_UDP_PORT_TELACONSOLE       5428 /* TELACONSOLE */
#define NETIO_UDP_PORT_BASE              5429 /* Billing and Accounting System Exchange */
#define NETIO_UDP_PORT_RADEC_CORP        5430 /* RADEC CORP */
#define NETIO_UDP_PORT_PARK_AGENT        5431 /* PARK AGENT */
#define NETIO_UDP_PORT_POSTGRESQL        5432 /* PostgreSQL Database */
#define NETIO_UDP_PORT_PYRRHO            5433 /* Pyrrho DBMS */
#define NETIO_UDP_PORT_SGI_ARRAYD        5434 /* SGI Array Services Daemon */
#define NETIO_UDP_PORT_SCEANICS          5435 /* SCEANICS situation and action notification */
#define NETIO_UDP_PORT_PMIP6_CNTL        5436 /* pmip6-cntl */
#define NETIO_UDP_PORT_PMIP6_DATA        5437 /* pmip6-data */
#define NETIO_UDP_PORT_SPSS              5443 /* Pearson HTTPS */
#define NETIO_UDP_PORT_SUREBOX           5453 /* SureBox */
#define NETIO_UDP_PORT_APC_5454          5454 /* APC 5454 */
#define NETIO_UDP_PORT_APC_5455          5455 /* APC 5455 */
#define NETIO_UDP_PORT_APC_5456          5456 /* APC 5456 */
#define NETIO_UDP_PORT_SILKMETER         5461 /* SILKMETER */
#define NETIO_UDP_PORT_TTL_PUBLISHER     5462 /* TTL Publisher */
#define NETIO_UDP_PORT_TTLPRICEPROXY     5463 /* TTL Price Proxy */
#define NETIO_UDP_PORT_QUAILNET          5464 /* Quail Networks Object Broker */
#define NETIO_UDP_PORT_NETOPS_BROKER     5465 /* NETOPS-BROKER */
#define NETIO_UDP_PORT_FCP_ADDR_SRVR1    5500 /* fcp-addr-srvr1 */
#define NETIO_UDP_PORT_FCP_ADDR_SRVR2    5501 /* fcp-addr-srvr2 */
#define NETIO_UDP_PORT_FCP_SRVR_INST1    5502 /* fcp-srvr-inst1 */
#define NETIO_UDP_PORT_FCP_SRVR_INST2    5503 /* fcp-srvr-inst2 */
#define NETIO_UDP_PORT_FCP_CICS_GW1      5504 /* fcp-cics-gw1 */
#define NETIO_UDP_PORT_CHECKOUTDB        5505 /* Checkout Database */
#define NETIO_UDP_PORT_AMC               5506 /* Amcom Mobile Connect */
#define NETIO_UDP_PORT_SGI_EVENTMOND     5553 /* SGI Eventmond Port */
#define NETIO_UDP_PORT_SGI_ESPHTTP       5554 /* SGI ESP HTTP */
#define NETIO_UDP_PORT_PERSONAL_AGENT    5555 /* Personal Agent */
#define NETIO_UDP_PORT_FREECIV           5556 /* Freeciv gameplay */
#define NETIO_UDP_PORT_ENC_EPS_MC_SEC    5567 /* EMIT protocol stack multicast/secure transport */
#define NETIO_UDP_PORT_SDT               5568 /* Session Data Transport Multicast */
#define NETIO_UDP_PORT_RDMNET_DEVICE     5569 /* "PLASA E1.33 */
#define NETIO_UDP_PORT_SDMMP             5573 /* SAS Domain Management Messaging Protocol */
#define NETIO_UDP_PORT_TMOSMS0           5580 /* T-Mobile SMS Protocol Message 0 */
#define NETIO_UDP_PORT_TMOSMS1           5581 /* T-Mobile SMS Protocol Message 1 */
#define NETIO_UDP_PORT_FAC_RESTORE       5582 /* T-Mobile SMS Protocol Message 3 */
#define NETIO_UDP_PORT_TMO_ICON_SYNC     5583 /* T-Mobile SMS Protocol Message 2 */
#define NETIO_UDP_PORT_BIS_WEB           5584 /* BeInSync-Web */
#define NETIO_UDP_PORT_BIS_SYNC          5585 /* BeInSync-sync */
#define NETIO_UDP_PORT_ININMESSAGING     5597 /* inin secure messaging */
#define NETIO_UDP_PORT_MCTFEED           5598 /* MCT Market Data Feed */
#define NETIO_UDP_PORT_ESINSTALL         5599 /* Enterprise Security Remote Install */
#define NETIO_UDP_PORT_ESMMANAGER        5600 /* Enterprise Security Manager */
#define NETIO_UDP_PORT_ESMAGENT          5601 /* Enterprise Security Agent */
#define NETIO_UDP_PORT_A1_MSC            5602 /* A1-MSC */
#define NETIO_UDP_PORT_A1_BS             5603 /* A1-BS */
#define NETIO_UDP_PORT_A3_SDUNODE        5604 /* A3-SDUNode */
#define NETIO_UDP_PORT_A4_SDUNODE        5605 /* A4-SDUNode */
#define NETIO_UDP_PORT_NINAF             5627 /* Node Initiated Network Association Forma */
#define NETIO_UDP_PORT_HTRUST            5628 /* HTrust API */
#define NETIO_UDP_PORT_SYMANTEC_SFDB     5629 /* Symantec Storage Foundation for Database */
#define NETIO_UDP_PORT_PRECISE_COMM      5630 /* PreciseCommunication */
#define NETIO_UDP_PORT_PCANYWHEREDATA    5631 /* pcANYWHEREdata */
#define NETIO_UDP_PORT_PCANYWHERESTAT    5632 /* pcANYWHEREstat */
#define NETIO_UDP_PORT_BEORL             5633 /* BE Operations Request Listener */
#define NETIO_UDP_PORT_XPRTLD            5634 /* SF Message Service */
#define NETIO_UDP_PORT_ZRE_DISC          5670 /* Local area discovery and messaging over ZeroMQ */
#define NETIO_UDP_PORT_AMQPS             5671 /* amqp protocol over TLS/SSL */
#define NETIO_UDP_PORT_AMQP              5672 /* AMQP */
#define NETIO_UDP_PORT_JMS               5673 /* JACL Message Server */
#define NETIO_UDP_PORT_HYPERSCSI_PORT    5674 /* HyperSCSI Port */
#define NETIO_UDP_PORT_V5UA              5675 /* V5UA application port */
#define NETIO_UDP_PORT_RAADMIN           5676 /* RA Administration */
#define NETIO_UDP_PORT_QUESTDB2_LNCHR    5677 /* Quest Central DB2 Launchr */
#define NETIO_UDP_PORT_RRAC              5678 /* Remote Replication Agent Connection */
#define NETIO_UDP_PORT_DCCM              5679 /* Direct Cable Connect Manager */
#define NETIO_UDP_PORT_AURIGA_ROUTER     5680 /* Auriga Router Service */
#define NETIO_UDP_PORT_NCXCP             5681 /* Net-coneX Control Protocol */
#define NETIO_UDP_PORT_BRIGHTCORE        5682 /* BrightCore control & data transfer exchange */
#define NETIO_UDP_PORT_COAP              5683 /* Constrained Application Protocol */
#define NETIO_UDP_PORT_COAPS             5684 /* DTLS-secured CoAP */
#define NETIO_UDP_PORT_GGZ               5688 /* GGZ Gaming Zone */
#define NETIO_UDP_PORT_QMVIDEO           5689 /* QM video network management protocol */
#define NETIO_UDP_PORT_PROSHAREAUDIO     5713 /* proshare conf audio */
#define NETIO_UDP_PORT_PROSHAREVIDEO     5714 /* proshare conf video */
#define NETIO_UDP_PORT_PROSHAREDATA      5715 /* proshare conf data */
#define NETIO_UDP_PORT_PROSHAREREQUEST   5716 /* proshare conf request */
#define NETIO_UDP_PORT_PROSHARENOTIFY    5717 /* proshare conf notify */
#define NETIO_UDP_PORT_DPM               5718 /* DPM Communication Server */
#define NETIO_UDP_PORT_DPM_AGENT         5719 /* DPM Agent Coordinator */
#define NETIO_UDP_PORT_MS_LICENSING      5720 /* MS-Licensing */
#define NETIO_UDP_PORT_DTPT              5721 /* Desktop Passthru Service */
#define NETIO_UDP_PORT_MSDFSR            5722 /* Microsoft DFS Replication Service */
#define NETIO_UDP_PORT_OMHS              5723 /* Operations Manager - Health Service */
#define NETIO_UDP_PORT_OMSDK             5724 /* Operations Manager - SDK Service */
#define NETIO_UDP_PORT_IO_DIST_GROUP     5728 /* Dist. I/O Comm. Service Group Membership */
#define NETIO_UDP_PORT_OPENMAIL          5729 /* Openmail User Agent Layer */
#define NETIO_UDP_PORT_UNIENG            5730 /* Steltor's calendar access */
#define NETIO_UDP_PORT_IDA_DISCOVER1     5741 /* IDA Discover Port 1 */
#define NETIO_UDP_PORT_IDA_DISCOVER2     5742 /* IDA Discover Port 2 */
#define NETIO_UDP_PORT_WATCHDOC_POD      5743 /* Watchdoc NetPOD Protocol */
#define NETIO_UDP_PORT_WATCHDOC          5744 /* Watchdoc Server */
#define NETIO_UDP_PORT_FCOPY_SERVER      5745 /* fcopy-server */
#define NETIO_UDP_PORT_FCOPYS_SERVER     5746 /* fcopys-server */
#define NETIO_UDP_PORT_TUNATIC           5747 /* Wildbits Tunatic */
#define NETIO_UDP_PORT_TUNALYZER         5748 /* Wildbits Tunalyzer */
#define NETIO_UDP_PORT_RSCD              5750 /* Bladelogic Agent Service */
#define NETIO_UDP_PORT_OPENMAILG         5755 /* OpenMail Desk Gateway server */
#define NETIO_UDP_PORT_X500MS            5757 /* OpenMail X.500 Directory Server */
#define NETIO_UDP_PORT_OPENMAILNS        5766 /* OpenMail NewMail Server */
#define NETIO_UDP_PORT_S_OPENMAIL        5767 /* OpenMail Suer Agent Layer (Secure) */
#define NETIO_UDP_PORT_OPENMAILPXY       5768 /* OpenMail CMTS Server */
#define NETIO_UDP_PORT_SPRAMSCA          5769 /* x509solutions Internal CA */
#define NETIO_UDP_PORT_SPRAMSD           5770 /* x509solutions Secure Data */
#define NETIO_UDP_PORT_NETAGENT          5771 /* NetAgent */
#define NETIO_UDP_PORT_DALI_PORT         5777 /* DALI Port */
#define NETIO_UDP_PORT_3PAR_EVTS         5781 /* 3PAR Event Reporting Service */
#define NETIO_UDP_PORT_3PAR_MGMT         5782 /* 3PAR Management Service */
#define NETIO_UDP_PORT_3PAR_MGMT_SSL     5783 /* 3PAR Management Service with SSL */
#define NETIO_UDP_PORT_IBAR              5784 /* Cisco Interbox Application Redundancy */
#define NETIO_UDP_PORT_3PAR_RCOPY        5785 /* 3PAR Inform Remote Copy */
#define NETIO_UDP_PORT_CISCO_REDU        5786 /* redundancy notification */
#define NETIO_UDP_PORT_WAASCLUSTER       5787 /* Cisco WAAS Cluster Protocol */
#define NETIO_UDP_PORT_XTREAMX           5793 /* XtreamX Supervised Peer message */
#define NETIO_UDP_PORT_SPDP              5794 /* Simple Peered Discovery Protocol */
#define NETIO_UDP_PORT_ICMPD             5813 /* ICMPD */
#define NETIO_UDP_PORT_SPT_AUTOMATION    5814 /* Support Automation */
#define NETIO_UDP_PORT_WHEREHOO          5859 /* WHEREHOO */
#define NETIO_UDP_PORT_PPSUITEMSG        5863 /* PlanetPress Suite Messeng */
#define NETIO_UDP_PORT_RFB               5900 /* Remote Framebuffer */
#define NETIO_UDP_PORT_CM                5910 /* Context Management */
#define NETIO_UDP_PORT_CPDLC             5911 /* Controller Pilot Data Link Communication */
#define NETIO_UDP_PORT_FIS               5912 /* Flight Information Services */
#define NETIO_UDP_PORT_ADS_C             5913 /* Automatic Dependent Surveillance */
#define NETIO_UDP_PORT_INDY              5963 /* Indy Application Server */
#define NETIO_UDP_PORT_MPPOLICY_V5       5968 /* mppolicy-v5 */
#define NETIO_UDP_PORT_MPPOLICY_MGR      5969 /* mppolicy-mgr */
#define NETIO_UDP_PORT_COUCHDB           5984 /* CouchDB */
#define NETIO_UDP_PORT_WSMAN             5985 /* WBEM WS-Management HTTP */
#define NETIO_UDP_PORT_WSMANS            5986 /* WBEM WS-Management HTTP over TLS/SSL */
#define NETIO_UDP_PORT_WBEM_RMI          5987 /* WBEM RMI */
#define NETIO_UDP_PORT_WBEM_HTTP         5988 /* WBEM CIM-XML (HTTP) */
#define NETIO_UDP_PORT_WBEM_HTTPS        5989 /* WBEM CIM-XML (HTTPS) */
#define NETIO_UDP_PORT_WBEM_EXP_HTTPS    5990 /* WBEM Export HTTPS */
#define NETIO_UDP_PORT_NUXSL             5991 /* NUXSL */
#define NETIO_UDP_PORT_CONSUL_INSIGHT    5992 /* Consul InSight Security */
#define NETIO_UDP_PORT_CVSUP             5999 /* CVSup */
#define NETIO_UDP_PORT_NDL_AHP_SVC       6064 /* NDL-AHP-SVC */
#define NETIO_UDP_PORT_WINPHARAOH        6065 /* WinPharaoh */
#define NETIO_UDP_PORT_EWCTSP            6066 /* EWCTSP */
#define NETIO_UDP_PORT_TRIP              6069 /* TRIP */
#define NETIO_UDP_PORT_MESSAGEASAP       6070 /* Messageasap */
#define NETIO_UDP_PORT_SSDTP             6071 /* SSDTP */
#define NETIO_UDP_PORT_DIAGNOSE_PROC     6072 /* DIAGNOSE-PROC */
#define NETIO_UDP_PORT_DIRECTPLAY8       6073 /* DirectPlay8 */
#define NETIO_UDP_PORT_MAX               6074 /* Microsoft Max */
#define NETIO_UDP_PORT_GENEVE            6081 /* Generic Network Virtualization Encapsulation (Geneve) */
#define NETIO_UDP_PORT_P25CAI            6082 /* APCO Project 25 Common Air Interface - UDP encapsulation */
#define NETIO_UDP_PORT_MIAMI_BCAST       6083 /* telecomsoftware miami broadcast */
#define NETIO_UDP_PORT_KONSPIRE2B        6085 /* konspire2b p2p network */
#define NETIO_UDP_PORT_PDTP              6086 /* PDTP P2P */
#define NETIO_UDP_PORT_LDSS              6087 /* Local Download Sharing Service */
#define NETIO_UDP_PORT_DOGLMS_NOTIFY     6088 /* SuperDog License Manager Notifier */
#define NETIO_UDP_PORT_SYNCHRONET_DB     6100 /* SynchroNet-db */
#define NETIO_UDP_PORT_SYNCHRONET_RTC    6101 /* SynchroNet-rtc */
#define NETIO_UDP_PORT_SYNCHRONET_UPD    6102 /* SynchroNet-upd */
#define NETIO_UDP_PORT_RETS              6103 /* RETS */
#define NETIO_UDP_PORT_DBDB              6104 /* DBDB */
#define NETIO_UDP_PORT_PRIMASERVER       6105 /* Prima Server */
#define NETIO_UDP_PORT_MPSSERVER         6106 /* MPS Server */
#define NETIO_UDP_PORT_ETC_CONTROL       6107 /* ETC Control */
#define NETIO_UDP_PORT_SERCOMM_SCADMIN   6108 /* Sercomm-SCAdmin */
#define NETIO_UDP_PORT_GLOBECAST_ID      6109 /* GLOBECAST-ID */
#define NETIO_UDP_PORT_SOFTCM            6110 /* HP SoftBench CM */
#define NETIO_UDP_PORT_SPC               6111 /* HP SoftBench Sub-Process Control */
#define NETIO_UDP_PORT_DTSPCD            6112 /* Desk-Top Sub-Process Control Daemon */
#define NETIO_UDP_PORT_TIPC              6118 /* Transparent Inter Process Communication */
#define NETIO_UDP_PORT_BEX_WEBADMIN      6122 /* Backup Express Web Server */
#define NETIO_UDP_PORT_BACKUP_EXPRESS    6123 /* Backup Express */
#define NETIO_UDP_PORT_PNBS              6124 /* Phlexible Network Backup Service */
#define NETIO_UDP_PORT_NBT_WOL           6133 /* New Boundary Tech WOL */
#define NETIO_UDP_PORT_PULSONIXNLS       6140 /* Pulsonix Network License Service */
#define NETIO_UDP_PORT_META_CORP         6141 /* Meta Corporation License Manager */
#define NETIO_UDP_PORT_ASPENTEC_LM       6142 /* Aspen Technology License Manager */
#define NETIO_UDP_PORT_WATERSHED_LM      6143 /* Watershed License Manager */
#define NETIO_UDP_PORT_STATSCI1_LM       6144 /* StatSci License Manager - 1 */
#define NETIO_UDP_PORT_STATSCI2_LM       6145 /* StatSci License Manager - 2 */
#define NETIO_UDP_PORT_LONEWOLF_LM       6146 /* Lone Wolf Systems License Manager */
#define NETIO_UDP_PORT_MONTAGE_LM        6147 /* Montage License Manager */
#define NETIO_UDP_PORT_RICARDO_LM2       6148 /* Ricardo North America License Manager */
#define NETIO_UDP_PORT_TAL_POD           6149 /* tal-pod */
#define NETIO_UDP_PORT_ECMP_DATA         6160 /* Emerson Extensible Control and Management Protocol Data */
#define NETIO_UDP_PORT_PATROL_ISM        6161 /* PATROL Internet Srv Mgr */
#define NETIO_UDP_PORT_PATROL_COLL       6162 /* PATROL Collector */
#define NETIO_UDP_PORT_PSCRIBE           6163 /* Precision Scribe Cnx Port */
#define NETIO_UDP_PORT_LM_X              6200 /* LM-X License Manager by X-Formation */
#define NETIO_UDP_PORT_THERMO_CALC       6201 /* Management of service nodes in a processing grid for thermodynamic calculations */
#define NETIO_UDP_PORT_RADMIND           6222 /* Radmind Access Protocol */
#define NETIO_UDP_PORT_JEOL_NSDDP_1      6241 /* JEOL Network Services Dynamic Discovery Protocol 1 */
#define NETIO_UDP_PORT_JEOL_NSDDP_2      6242 /* JEOL Network Services Dynamic Discovery Protocol 2 */
#define NETIO_UDP_PORT_JEOL_NSDDP_3      6243 /* JEOL Network Services Dynamic Discovery Protocol 3 */
#define NETIO_UDP_PORT_JEOL_NSDDP_4      6244 /* JEOL Network Services Dynamic Discovery Protocol 4 */
#define NETIO_UDP_PORT_TL1_RAW_SSL       6251 /* TL1 Raw Over SSL/TLS */
#define NETIO_UDP_PORT_TL1_SSH           6252 /* TL1 over SSH */
#define NETIO_UDP_PORT_CRIP              6253 /* CRIP */
#define NETIO_UDP_PORT_GRID              6268 /* Grid Authentication */
#define NETIO_UDP_PORT_GRID_ALT          6269 /* Grid Authentication Alt */
#define NETIO_UDP_PORT_BMC_GRX           6300 /* BMC GRX */
#define NETIO_UDP_PORT_BMC_CTD_LDAP      6301 /* "BMC CONTROL-D LDAP SERVER */
#define NETIO_UDP_PORT_UFMP              6306 /* Unified Fabric Management Protocol */
#define NETIO_UDP_PORT_SCUP_DISC         6315 /* Sensor Control Unit Protocol Discovery Protocol */
#define NETIO_UDP_PORT_ABB_ESCP          6316 /* Ethernet Sensor Communications Protocol */
#define NETIO_UDP_PORT_NAV_DATA          6317 /* Navtech Radar Sensor Data */
#define NETIO_UDP_PORT_REPSVC            6320 /* Double-Take Replication Service */
#define NETIO_UDP_PORT_EMP_SERVER1       6321 /* Empress Software Connectivity Server 1 */
#define NETIO_UDP_PORT_EMP_SERVER2       6322 /* Empress Software Connectivity Server 2 */
#define NETIO_UDP_PORT_HRD_NS_DISC       6324 /* HR Device Network service */
#define NETIO_UDP_PORT_SFLOW             6343 /* sFlow traffic monitoring */
#define NETIO_UDP_PORT_GNUTELLA_SVC      6346 /* gnutella-svc */
#define NETIO_UDP_PORT_GNUTELLA_RTR      6347 /* gnutella-rtr */
#define NETIO_UDP_PORT_ADAP              6350 /* App Discovery and Access Protocol */
#define NETIO_UDP_PORT_PMCS              6355 /* PMCS applications */
#define NETIO_UDP_PORT_METAEDIT_MU       6360 /* MetaEdit+ Multi-User */
#define NETIO_UDP_PORT_NDN               6363 /* Named Data Networking */
#define NETIO_UDP_PORT_METAEDIT_SE       6370 /* MetaEdit+ Server Administration */
#define NETIO_UDP_PORT_METATUDE_MDS      6382 /* Metatude Dialogue Server */
#define NETIO_UDP_PORT_CLARIION_EVR01    6389 /* clariion-evr01 */
#define NETIO_UDP_PORT_METAEDIT_WS       6390 /* MetaEdit+ WebService API */
#define NETIO_UDP_PORT_FAXCOMSERVICE     6417 /* Faxcom Message Service */
#define NETIO_UDP_PORT_NIM_VDRSHELL      6420 /* NIM_VDRShell */
#define NETIO_UDP_PORT_NIM_WAN           6421 /* NIM_WAN */
#define NETIO_UDP_PORT_SUN_SR_HTTPS      6443 /* Service Registry Default HTTPS Domain */
#define NETIO_UDP_PORT_SGE_QMASTER       6444 /* "Grid Engine Qmaster Service */
#define NETIO_UDP_PORT_SGE_EXECD         6445 /* "Grid Engine Execution Service */
#define NETIO_UDP_PORT_MYSQL_PROXY       6446 /* MySQL Proxy */
#define NETIO_UDP_PORT_SKIP_CERT_RECV    6455 /* SKIP Certificate Receive */
#define NETIO_UDP_PORT_SKIP_CERT_SEND    6456 /* SKIP Certificate Send */
#define NETIO_UDP_PORT_LVISION_LM        6471 /* LVision License Manager */
#define NETIO_UDP_PORT_SUN_SR_HTTP       6480 /* Service Registry Default HTTP Domain */
#define NETIO_UDP_PORT_SERVICETAGS       6481 /* Service Tags */
#define NETIO_UDP_PORT_LDOMS_MGMT        6482 /* Logical Domains Management Interface */
#define NETIO_UDP_PORT_SUNVTS_RMI        6483 /* SunVTS RMI */
#define NETIO_UDP_PORT_SUN_SR_JMS        6484 /* Service Registry Default JMS Domain */
#define NETIO_UDP_PORT_SUN_SR_IIOP       6485 /* Service Registry Default IIOP Domain */
#define NETIO_UDP_PORT_SUN_SR_IIOPS      6486 /* Service Registry Default IIOPS Domain */
#define NETIO_UDP_PORT_SUN_SR_IIOP_AUT   6487 /* Service Registry Default IIOPAuth Domain */
#define NETIO_UDP_PORT_SUN_SR_JMX        6488 /* Service Registry Default JMX Domain */
#define NETIO_UDP_PORT_SUN_SR_ADMIN      6489 /* Service Registry Default Admin Domain */
#define NETIO_UDP_PORT_BOKS              6500 /* BoKS Master */
#define NETIO_UDP_PORT_BOKS_SERVC        6501 /* "BoKS Servc */
#define NETIO_UDP_PORT_BOKS_SERVM        6502 /* "BoKS Servm */
#define NETIO_UDP_PORT_BOKS_CLNTD        6503 /* "BoKS Clntd */
#define NETIO_UDP_PORT_BADM_PRIV         6505 /* "BoKS Admin Private Port */
#define NETIO_UDP_PORT_BADM_PUB          6506 /* "BoKS Admin Public Port */
#define NETIO_UDP_PORT_BDIR_PRIV         6507 /* "BoKS Dir Server */
#define NETIO_UDP_PORT_BDIR_PUB          6508 /* "BoKS Dir Server */
#define NETIO_UDP_PORT_MGCS_MFP_PORT     6509 /* MGCS-MFP Port */
#define NETIO_UDP_PORT_MCER_PORT         6510 /* MCER Port */
#define NETIO_UDP_PORT_DCCP_UDP          6511 /* Datagram Congestion Control Protocol Encapsulation for NAT Traversal */
#define NETIO_UDP_PORT_SYSLOG_TLS        6514 /* syslog over DTLS */
#define NETIO_UDP_PORT_ELIPSE_REC        6515 /* Elipse RPC Protocol */
#define NETIO_UDP_PORT_LDS_DISTRIB       6543 /* lds_distrib */
#define NETIO_UDP_PORT_LDS_DUMP          6544 /* LDS Dump Service */
#define NETIO_UDP_PORT_APC_6547          6547 /* APC 6547 */
#define NETIO_UDP_PORT_APC_6548          6548 /* APC 6548 */
#define NETIO_UDP_PORT_APC_6549          6549 /* APC 6549 */
#define NETIO_UDP_PORT_FG_SYSUPDATE      6550 /* fg-sysupdate */
#define NETIO_UDP_PORT_SUM               6551 /* Software Update Manager */
#define NETIO_UDP_PORT_SANE_PORT         6566 /* SANE Control Port */
#define NETIO_UDP_PORT_RP_REPUTATION     6568 /* Roaring Penguin IP Address Reputation Collection */
#define NETIO_UDP_PORT_AFFILIATE         6579 /* Affiliate */
#define NETIO_UDP_PORT_PARSEC_MASTER     6580 /* Parsec Masterserver */
#define NETIO_UDP_PORT_PARSEC_PEER       6581 /* Parsec Peer-to-Peer */
#define NETIO_UDP_PORT_PARSEC_GAME       6582 /* Parsec Gameserver */
#define NETIO_UDP_PORT_JOAJEWELSUITE     6583 /* JOA Jewel Suite */
#define NETIO_UDP_PORT_ODETTE_FTPS       6619 /* ODETTE-FTP over TLS/SSL */
#define NETIO_UDP_PORT_KFTP_DATA         6620 /* Kerberos V5 FTP Data */
#define NETIO_UDP_PORT_KFTP              6621 /* Kerberos V5 FTP Control */
#define NETIO_UDP_PORT_MCFTP             6622 /* Multicast FTP */
#define NETIO_UDP_PORT_KTELNET           6623 /* Kerberos V5 Telnet */
#define NETIO_UDP_PORT_WAGO_SERVICE      6626 /* WAGO Service and Update */
#define NETIO_UDP_PORT_NEXGEN            6627 /* Allied Electronics NeXGen */
#define NETIO_UDP_PORT_AFESC_MC          6628 /* AFE Stock Channel M/C */
#define NETIO_UDP_PORT_CISCO_VPATH_TUN   6633 /* Cisco vPath Services Overlay */
#define NETIO_UDP_PORT_MPLS_PM           6634 /* MPLS Performance Measurement out-of-band response */
#define NETIO_UDP_PORT_OPENFLOW          6653 /* OpenFlow */
#define NETIO_UDP_PORT_PALCOM_DISC       6657 /* PalCom Discovery */
#define NETIO_UDP_PORT_VOCALTEC_GOLD     6670 /* Vocaltec Global Online Directory */
#define NETIO_UDP_PORT_P4P_PORTAL        6671 /* P4P Portal Service */
#define NETIO_UDP_PORT_VISION_SERVER     6672 /* "vision_server */
#define NETIO_UDP_PORT_VISION_ELMD       6673 /* "vision_elmd */
#define NETIO_UDP_PORT_VFBP_DISC         6678 /* Viscount Freedom Bridge Discovery */
#define NETIO_UDP_PORT_OSAUT             6679 /* Osorno Automation */
#define NETIO_UDP_PORT_TSA               6689 /* Tofino Security Appliance */
#define NETIO_UDP_PORT_BABEL             6696 /* Babel Routing Protocol */
#define NETIO_UDP_PORT_KTI_ICAD_SRVR     6701 /* KTI/ICAD Nameserver */
#define NETIO_UDP_PORT_E_DESIGN_NET      6702 /* e-Design network */
#define NETIO_UDP_PORT_E_DESIGN_WEB      6703 /* e-Design web */
#define NETIO_UDP_PORT_IBPROTOCOL        6714 /* Internet Backplane Protocol */
#define NETIO_UDP_PORT_FIBOTRADER_COM    6715 /* Fibotrader Communications */
#define NETIO_UDP_PORT_BMC_PERF_AGENT    6767 /* BMC PERFORM AGENT */
#define NETIO_UDP_PORT_BMC_PERF_MGRD     6768 /* BMC PERFORM MGRD */
#define NETIO_UDP_PORT_ADI_GXP_SRVPRT    6769 /* ADInstruments GxP Server */
#define NETIO_UDP_PORT_PLYSRV_HTTP       6770 /* PolyServe http */
#define NETIO_UDP_PORT_PLYSRV_HTTPS      6771 /* PolyServe https */
#define NETIO_UDP_PORT_BFD_LAG           6784 /* Bidirectional Forwarding Detection (BFD) on Link Aggregation Group (LAG) Interfaces */
#define NETIO_UDP_PORT_DGPF_EXCHG        6785 /* DGPF Individual Exchange */
#define NETIO_UDP_PORT_SMC_JMX           6786 /* Sun Java Web Console JMX */
#define NETIO_UDP_PORT_SMC_ADMIN         6787 /* Sun Web Console Admin */
#define NETIO_UDP_PORT_SMC_HTTP          6788 /* SMC-HTTP */
#define NETIO_UDP_PORT_SMC_HTTPS         6789 /* SMC-HTTPS */
#define NETIO_UDP_PORT_HNMP              6790 /* HNMP */
#define NETIO_UDP_PORT_HNM               6791 /* Halcyon Network Manager */
#define NETIO_UDP_PORT_ACNET             6801 /* ACNET Control System Protocol */
#define NETIO_UDP_PORT_AMBIT_LM          6831 /* ambit-lm */
#define NETIO_UDP_PORT_NETMO_DEFAULT     6841 /* Netmo Default */
#define NETIO_UDP_PORT_NETMO_HTTP        6842 /* Netmo HTTP */
#define NETIO_UDP_PORT_ICCRUSHMORE       6850 /* ICCRUSHMORE */
#define NETIO_UDP_PORT_ACCTOPUS_ST       6868 /* Acctopus Status */
#define NETIO_UDP_PORT_MUSE              6888 /* MUSE */
#define NETIO_UDP_PORT_ETHOSCAN          6935 /* EthoScan Service */
#define NETIO_UDP_PORT_XSMSVC            6936 /* XenSource Management Service */
#define NETIO_UDP_PORT_BIOSERVER         6946 /* Biometrics Server */
#define NETIO_UDP_PORT_OTLP              6951 /* OTLP */
#define NETIO_UDP_PORT_JMACT3            6961 /* JMACT3 */
#define NETIO_UDP_PORT_JMEVT2            6962 /* jmevt2 */
#define NETIO_UDP_PORT_SWISMGR1          6963 /* swismgr1 */
#define NETIO_UDP_PORT_SWISMGR2          6964 /* swismgr2 */
#define NETIO_UDP_PORT_SWISTRAP          6965 /* swistrap */
#define NETIO_UDP_PORT_SWISPOL           6966 /* swispol */
#define NETIO_UDP_PORT_ACMSODA           6969 /* acmsoda */
#define NETIO_UDP_PORT_MOBILITYSRV       6997 /* Mobility XE Protocol */
#define NETIO_UDP_PORT_IATP_HIGHPRI      6998 /* IATP-highPri */
#define NETIO_UDP_PORT_IATP_NORMALPRI    6999 /* IATP-normalPri */
#define NETIO_UDP_PORT_AFS3_FILESERVER   7000 /* file server itself */
#define NETIO_UDP_PORT_AFS3_CALLBACK     7001 /* callbacks to cache managers */
#define NETIO_UDP_PORT_AFS3_PRSERVER     7002 /* users & groups database */
#define NETIO_UDP_PORT_AFS3_VLSERVER     7003 /* volume location database */
#define NETIO_UDP_PORT_AFS3_KASERVER     7004 /* AFS/Kerberos authentication service */
#define NETIO_UDP_PORT_AFS3_VOLSER       7005 /* volume managment server */
#define NETIO_UDP_PORT_AFS3_ERRORS       7006 /* error interpretation service */
#define NETIO_UDP_PORT_AFS3_BOS          7007 /* basic overseer process */
#define NETIO_UDP_PORT_AFS3_UPDATE       7008 /* server-to-server updater */
#define NETIO_UDP_PORT_AFS3_RMTSYS       7009 /* remote cache manager service */
#define NETIO_UDP_PORT_UPS_ONLINET       7010 /* onlinet uninterruptable power supplies */
#define NETIO_UDP_PORT_TALON_DISC        7011 /* Talon Discovery Port */
#define NETIO_UDP_PORT_TALON_ENGINE      7012 /* Talon Engine */
#define NETIO_UDP_PORT_MICROTALON_DIS    7013 /* Microtalon Discovery */
#define NETIO_UDP_PORT_MICROTALON_COM    7014 /* Microtalon Communications */
#define NETIO_UDP_PORT_TALON_WEBSERVER   7015 /* Talon Webserver */
#define NETIO_UDP_PORT_DOCERI_VIEW       7019 /* doceri drawing service screen view */
#define NETIO_UDP_PORT_DPSERVE           7020 /* DP Serve */
#define NETIO_UDP_PORT_DPSERVEADMIN      7021 /* DP Serve Admin */
#define NETIO_UDP_PORT_CTDP              7022 /* CT Discovery Protocol */
#define NETIO_UDP_PORT_CT2NMCS           7023 /* Comtech T2 NMCS */
#define NETIO_UDP_PORT_VMSVC             7024 /* Vormetric service */
#define NETIO_UDP_PORT_VMSVC_2           7025 /* Vormetric Service II */
#define NETIO_UDP_PORT_OP_PROBE          7030 /* ObjectPlanet probe */
#define NETIO_UDP_PORT_QUEST_DISC        7040 /* Quest application level network service discovery */
#define NETIO_UDP_PORT_ARCP              7070 /* ARCP */
#define NETIO_UDP_PORT_IWG1              7071 /* IWGADTS Aircraft Housekeeping Message */
#define NETIO_UDP_PORT_EMPOWERID         7080 /* EmpowerID Communication */
#define NETIO_UDP_PORT_JDP_DISC          7095 /* Java Discovery Protocol */
#define NETIO_UDP_PORT_LAZY_PTOP         7099 /* lazy-ptop */
#define NETIO_UDP_PORT_FONT_SERVICE      7100 /* X Font Service */
#define NETIO_UDP_PORT_ELCN              7101 /* Embedded Light Control Network */
#define NETIO_UDP_PORT_AES_X170          7107 /* AES-X170 */
#define NETIO_UDP_PORT_VIRPROT_LM        7121 /* Virtual Prototypes License Manager */
#define NETIO_UDP_PORT_SCENIDM           7128 /* intelligent data manager */
#define NETIO_UDP_PORT_SCENCCS           7129 /* Catalog Content Search */
#define NETIO_UDP_PORT_CABSM_COMM        7161 /* CA BSM Comm */
#define NETIO_UDP_PORT_CAISTORAGEMGR     7162 /* CA Storage Manager */
#define NETIO_UDP_PORT_CACSAMBROKER      7163 /* CA Connection Broker */
#define NETIO_UDP_PORT_FSR               7164 /* File System Repository Agent */
#define NETIO_UDP_PORT_DOC_SERVER        7165 /* Document WCF Server */
#define NETIO_UDP_PORT_ARUBA_SERVER      7166 /* Aruba eDiscovery Server */
#define NETIO_UDP_PORT_CCAG_PIB          7169 /* Consequor Consulting Process Integration Bridge */
#define NETIO_UDP_PORT_NSRP              7170 /* Adaptive Name/Service Resolution */
#define NETIO_UDP_PORT_DRM_PRODUCTION    7171 /* Discovery and Retention Mgt Production */
#define NETIO_UDP_PORT_CLUTILD           7174 /* Clutild */
#define NETIO_UDP_PORT_JANUS_DISC        7181 /* Janus Guidewire Enterprise Discovery Service Bus */
#define NETIO_UDP_PORT_FODMS             7200 /* FODMS FLIP */
#define NETIO_UDP_PORT_DLIP              7201 /* DLIP */
#define NETIO_UDP_PORT_RAMP              7227 /* Registry A $ M Protocol */
#define NETIO_UDP_PORT_ASPCOORDINATION   7235 /* ASP Coordination Protocol */
#define NETIO_UDP_PORT_CNAP              7262 /* Calypso Network Access Protocol */
#define NETIO_UDP_PORT_WATCHME_7272      7272 /* WatchMe Monitoring 7272 */
#define NETIO_UDP_PORT_OMA_RLP           7273 /* OMA Roaming Location */
#define NETIO_UDP_PORT_OMA_RLP_S         7274 /* OMA Roaming Location SEC */
#define NETIO_UDP_PORT_OMA_ULP           7275 /* OMA UserPlane Location */
#define NETIO_UDP_PORT_OMA_ILP           7276 /* OMA Internal Location Protocol */
#define NETIO_UDP_PORT_OMA_ILP_S         7277 /* OMA Internal Location Secure Protocol */
#define NETIO_UDP_PORT_OMA_DCDOCBS       7278 /* OMA Dynamic Content Delivery over CBS */
#define NETIO_UDP_PORT_CTXLIC            7279 /* Citrix Licensing */
#define NETIO_UDP_PORT_ITACTIONSERVER1   7280 /* ITACTIONSERVER 1 */
#define NETIO_UDP_PORT_ITACTIONSERVER2   7281 /* ITACTIONSERVER 2 */
#define NETIO_UDP_PORT_MZCA_ALERT        7282 /* eventACTION/ussACTION (MZCA) alert */
#define NETIO_UDP_PORT_LCM_SERVER        7365 /* LifeKeeper Communications */
#define NETIO_UDP_PORT_MINDFILESYS       7391 /* mind-file system server */
#define NETIO_UDP_PORT_MRSSRENDEZVOUS    7392 /* mrss-rendezvous server */
#define NETIO_UDP_PORT_NFOLDMAN          7393 /* nFoldMan Remote Publish */
#define NETIO_UDP_PORT_FSE               7394 /* File system export of backup images */
#define NETIO_UDP_PORT_WINQEDIT          7395 /* winqedit */
#define NETIO_UDP_PORT_HEXARC            7397 /* Hexarc Command Language */
#define NETIO_UDP_PORT_RTPS_DISCOVERY    7400 /* RTPS Discovery */
#define NETIO_UDP_PORT_RTPS_DD_UT        7401 /* RTPS Data-Distribution User-Traffic */
#define NETIO_UDP_PORT_RTPS_DD_MT        7402 /* RTPS Data-Distribution Meta-Traffic */
#define NETIO_UDP_PORT_IONIXNETMON       7410 /* Ionix Network Monitor */
#define NETIO_UDP_PORT_DAQSTREAM         7411 /* Streaming of measurement data */
#define NETIO_UDP_PORT_MTPORTMON         7421 /* Matisse Port Monitor */
#define NETIO_UDP_PORT_PMDMGR            7426 /* OpenView DM Postmaster Manager */
#define NETIO_UDP_PORT_OVEADMGR          7427 /* OpenView DM Event Agent Manager */
#define NETIO_UDP_PORT_OVLADMGR          7428 /* OpenView DM Log Agent Manager */
#define NETIO_UDP_PORT_OPI_SOCK          7429 /* OpenView DM rqt communication */
#define NETIO_UDP_PORT_XMPV7             7430 /* OpenView DM xmpv7 api pipe */
#define NETIO_UDP_PORT_PMD               7431 /* OpenView DM ovc/xmpv3 api pipe */
#define NETIO_UDP_PORT_FAXIMUM           7437 /* Faximum */
#define NETIO_UDP_PORT_ORACLEAS_HTTPS    7443 /* Oracle Application Server HTTPS */
#define NETIO_UDP_PORT_RISE              7473 /* Rise: The Vieneo Province */
#define NETIO_UDP_PORT_TELOPS_LMD        7491 /* telops-lmd */
#define NETIO_UDP_PORT_SILHOUETTE        7500 /* Silhouette User */
#define NETIO_UDP_PORT_OVBUS             7501 /* HP OpenView Bus Daemon */
#define NETIO_UDP_PORT_OVHPAS            7510 /* HP OpenView Application Server */
#define NETIO_UDP_PORT_PAFEC_LM          7511 /* pafec-lm */
#define NETIO_UDP_PORT_SARATOGA          7542 /* Saratoga Transfer Protocol */
#define NETIO_UDP_PORT_ATUL              7543 /* atul server */
#define NETIO_UDP_PORT_NTA_DS            7544 /* FlowAnalyzer DisplayServer */
#define NETIO_UDP_PORT_NTA_US            7545 /* FlowAnalyzer UtilityServer */
#define NETIO_UDP_PORT_CFS               7546 /* Cisco Fabric service */
#define NETIO_UDP_PORT_CWMP              7547 /* DSL Forum CWMP */
#define NETIO_UDP_PORT_TIDP              7548 /* Threat Information Distribution Protocol */
#define NETIO_UDP_PORT_NLS_TL            7549 /* Network Layer Signaling Transport Layer */
#define NETIO_UDP_PORT_CLOUDSIGNALING    7550 /* Cloud Signaling Service */
#define NETIO_UDP_PORT_SNCP              7560 /* Sniffer Command Protocol */
#define NETIO_UDP_PORT_VSI_OMEGA         7566 /* VSI Omega */
#define NETIO_UDP_PORT_ARIES_KFINDER     7570 /* Aries Kfinder */
#define NETIO_UDP_PORT_COHERENCE_DISC    7574 /* Oracle Coherence Cluster discovery service */
#define NETIO_UDP_PORT_SUN_LM            7588 /* Sun License Manager */
#define NETIO_UDP_PORT_INDI              7624 /* Instrument Neutral Distributed Interface */
#define NETIO_UDP_PORT_SOAP_HTTP         7627 /* SOAP Service Port */
#define NETIO_UDP_PORT_ZEN_PAWN          7628 /* Primary Agent Work Notification */
#define NETIO_UDP_PORT_XDAS              7629 /* OpenXDAS Wire Protocol */
#define NETIO_UDP_PORT_PMDFMGT           7633 /* PMDF Management */
#define NETIO_UDP_PORT_CUSEEME           7648 /* bonjour-cuseeme */
#define NETIO_UDP_PORT_IMQTUNNELS        7674 /* iMQ SSL tunnel */
#define NETIO_UDP_PORT_IMQTUNNEL         7675 /* iMQ Tunnel */
#define NETIO_UDP_PORT_IMQBROKERD        7676 /* iMQ Broker Rendezvous */
#define NETIO_UDP_PORT_SUN_USER_HTTPS    7677 /* Sun App Server - HTTPS */
#define NETIO_UDP_PORT_PANDO_PUB         7680 /* Pando Media Public Distribution */
#define NETIO_UDP_PORT_COLLABER          7689 /* Collaber Network Service */
#define NETIO_UDP_PORT_KLIO              7697 /* KLIO communications */
#define NETIO_UDP_PORT_SYNC_EM7          7707 /* EM7 Dynamic Updates */
#define NETIO_UDP_PORT_SCINET            7708 /* scientia.net */
#define NETIO_UDP_PORT_MEDIMAGEPORTAL    7720 /* MedImage Portal */
#define NETIO_UDP_PORT_NSDEEPFREEZECTL   7724 /* Novell Snap-in Deep Freeze Control */
#define NETIO_UDP_PORT_NITROGEN          7725 /* Nitrogen Service */
#define NETIO_UDP_PORT_FREEZEXSERVICE    7726 /* FreezeX Console Service */
#define NETIO_UDP_PORT_TRIDENT_DATA      7727 /* Trident Systems Data */
#define NETIO_UDP_PORT_SMIP              7734 /* Smith Protocol over IP */
#define NETIO_UDP_PORT_AIAGENT           7738 /* HP Enterprise Discovery Agent */
#define NETIO_UDP_PORT_SCRIPTVIEW        7741 /* ScriptView Network */
#define NETIO_UDP_PORT_SSTP_1            7743 /* Sakura Script Transfer Protocol */
#define NETIO_UDP_PORT_RAQMON_PDU        7744 /* RAQMON PDU */
#define NETIO_UDP_PORT_PRGP              7747 /* Put/Run/Get Protocol */
#define NETIO_UDP_PORT_CBT               7777 /* cbt */
#define NETIO_UDP_PORT_INTERWISE         7778 /* Interwise */
#define NETIO_UDP_PORT_VSTAT             7779 /* VSTAT */
#define NETIO_UDP_PORT_ACCU_LMGR         7781 /* accu-lmgr */
#define NETIO_UDP_PORT_MINIVEND          7786 /* MINIVEND */
#define NETIO_UDP_PORT_POPUP_REMINDERS   7787 /* Popup Reminders Receive */
#define NETIO_UDP_PORT_OFFICE_TOOLS      7789 /* Office Tools Pro Receive */
#define NETIO_UDP_PORT_Q3ADE             7794 /* Q3ADE Cluster Service */
#define NETIO_UDP_PORT_PNET_CONN         7797 /* Propel Connector port */
#define NETIO_UDP_PORT_PNET_ENC          7798 /* Propel Encoder port */
#define NETIO_UDP_PORT_ALTBSDP           7799 /* Alternate BSDP Service */
#define NETIO_UDP_PORT_ASR               7800 /* Apple Software Restore */
#define NETIO_UDP_PORT_SSP_CLIENT        7801 /* Secure Server Protocol - client */
#define NETIO_UDP_PORT_VNS_TP            7802 /* Virtualized Network Services Tunnel Protocol */
#define NETIO_UDP_PORT_RBT_WANOPT        7810 /* Riverbed WAN Optimization Protocol */
#define NETIO_UDP_PORT_APC_7845          7845 /* APC 7845 */
#define NETIO_UDP_PORT_APC_7846          7846 /* APC 7846 */
#define NETIO_UDP_PORT_MIPV6TLS          7872 /* TLS-based Mobile IPv6 Security */
#define NETIO_UDP_PORT_PSS               7880 /* Pearson */
#define NETIO_UDP_PORT_UBROKER           7887 /* Universal Broker */
#define NETIO_UDP_PORT_MEVENT            7900 /* Multicast Event */
#define NETIO_UDP_PORT_TNOS_SP           7901 /* TNOS Service Protocol */
#define NETIO_UDP_PORT_TNOS_DP           7902 /* TNOS shell Protocol */
#define NETIO_UDP_PORT_TNOS_DPS          7903 /* TNOS Secure DiaguardProtocol */
#define NETIO_UDP_PORT_QO_SECURE         7913 /* QuickObjects secure port */
#define NETIO_UDP_PORT_T2_DRM            7932 /* Tier 2 Data Resource Manager */
#define NETIO_UDP_PORT_T2_BRM            7933 /* Tier 2 Business Rules Manager */
#define NETIO_UDP_PORT_GENERALSYNC       7962 /* "Encrypted */
#define NETIO_UDP_PORT_SUPERCELL         7967 /* Supercell */
#define NETIO_UDP_PORT_MICROMUSE_NCPS    7979 /* Micromuse-ncps */
#define NETIO_UDP_PORT_QUEST_VISTA       7980 /* Quest Vista */
#define NETIO_UDP_PORT_SOSSD_DISC        7982 /* Spotlight on SQL Server Desktop Agent Discovery */
#define NETIO_UDP_PORT_USICONTENTPUSH    7998 /* USI Content Push Service */
#define NETIO_UDP_PORT_IRDMI2            7999 /* iRDMI2 */
#define NETIO_UDP_PORT_IRDMI             8000 /* iRDMI */
#define NETIO_UDP_PORT_VCOM_TUNNEL       8001 /* VCOM Tunnel */
#define NETIO_UDP_PORT_TERADATAORDBMS    8002 /* Teradata ORDBMS */
#define NETIO_UDP_PORT_MCREPORT          8003 /* Mulberry Connect Reporting Service */
#define NETIO_UDP_PORT_MXI               8005 /* MXI Generation II for z/OS */
#define NETIO_UDP_PORT_HTTP_ALT2         8008 /* HTTP Alternate */
#define NETIO_UDP_PORT_QBDB              8019 /* QB DB Dynamic Port */
#define NETIO_UDP_PORT_INTU_EC_SVCDISC   8020 /* Intuit Entitlement Service and Discovery */
#define NETIO_UDP_PORT_INTU_EC_CLIENT    8021 /* Intuit Entitlement Client */
#define NETIO_UDP_PORT_OA_SYSTEM         8022 /* oa-system */
#define NETIO_UDP_PORT_CA_AUDIT_DA       8025 /* CA Audit Distribution Agent */
#define NETIO_UDP_PORT_CA_AUDIT_DS       8026 /* CA Audit Distribution Server */
#define NETIO_UDP_PORT_PRO_ED            8032 /* ProEd */
#define NETIO_UDP_PORT_MINDPRINT         8033 /* MindPrint */
#define NETIO_UDP_PORT_VANTRONIX_MGMT    8034 /* .vantronix Management */
#define NETIO_UDP_PORT_AMPIFY            8040 /* Ampify Messaging Protocol */
#define NETIO_UDP_PORT_SENOMIX01         8052 /* Senomix Timesheets Server */
#define NETIO_UDP_PORT_SENOMIX02         8053 /* Senomix Timesheets Client [1 year assignment] */
#define NETIO_UDP_PORT_SENOMIX03         8054 /* Senomix Timesheets Server [1 year assignment] */
#define NETIO_UDP_PORT_SENOMIX04         8055 /* Senomix Timesheets Server [1 year assignment] */
#define NETIO_UDP_PORT_SENOMIX05         8056 /* Senomix Timesheets Server [1 year assignment] */
#define NETIO_UDP_PORT_SENOMIX06         8057 /* Senomix Timesheets Client [1 year assignment] */
#define NETIO_UDP_PORT_SENOMIX07         8058 /* Senomix Timesheets Client [1 year assignment] */
#define NETIO_UDP_PORT_SENOMIX08         8059 /* Senomix Timesheets Client [1 year assignment] */
#define NETIO_UDP_PORT_AERO              8060 /* Asymmetric Extended Route Optimization (AERO) */
#define NETIO_UDP_PORT_GADUGADU          8074 /* Gadu-Gadu */
#define NETIO_UDP_PORT_HTTP_ALT3         8080 /* HTTP Alternate (see port 80) */
#define NETIO_UDP_PORT_SUNPROXYADMIN     8081 /* Sun Proxy Admin Service */
#define NETIO_UDP_PORT_US_CLI            8082 /* Utilistor (Client) */
#define NETIO_UDP_PORT_US_SRV            8083 /* Utilistor (Server) */
#define NETIO_UDP_PORT_D_S_N             8086 /* Distributed SCADA Networking Rendezvous Port */
#define NETIO_UDP_PORT_SIMPLIFYMEDIA     8087 /* Simplify Media SPP Protocol */
#define NETIO_UDP_PORT_RADAN_HTTP        8088 /* Radan HTTP */
#define NETIO_UDP_PORT_SAC               8097 /* SAC Port Id */
#define NETIO_UDP_PORT_XPRINT_SERVER     8100 /* Xprint Server */
#define NETIO_UDP_PORT_MTL8000_MATRIX    8115 /* MTL8000 Matrix */
#define NETIO_UDP_PORT_CP_CLUSTER        8116 /* Check Point Clustering */
#define NETIO_UDP_PORT_PRIVOXY           8118 /* Privoxy HTTP proxy */
#define NETIO_UDP_PORT_APOLLO_DATA       8121 /* Apollo Data Port */
#define NETIO_UDP_PORT_APOLLO_ADMIN      8122 /* Apollo Admin Port */
#define NETIO_UDP_PORT_PAYCASH_ONLINE    8128 /* PayCash Online Protocol */
#define NETIO_UDP_PORT_PAYCASH_WBP       8129 /* PayCash Wallet-Browser */
#define NETIO_UDP_PORT_INDIGO_VRMI       8130 /* INDIGO-VRMI */
#define NETIO_UDP_PORT_INDIGO_VBCP       8131 /* INDIGO-VBCP */
#define NETIO_UDP_PORT_DBABBLE           8132 /* dbabble */
#define NETIO_UDP_PORT_ISDD              8148 /* i-SDD file transfer */
#define NETIO_UDP_PORT_EOR_GAME          8149 /* Edge of Reality game data */
#define NETIO_UDP_PORT_PATROL            8160 /* Patrol */
#define NETIO_UDP_PORT_PATROL_SNMP       8161 /* Patrol SNMP */
#define NETIO_UDP_PORT_VMWARE_FDM        8182 /* VMware Fault Domain Manager */
#define NETIO_UDP_PORT_ITACH             8184 /* Remote iTach Connection */
#define NETIO_UDP_PORT_SPYTECHPHONE      8192 /* SpyTech Phone Service */
#define NETIO_UDP_PORT_BLP1              8194 /* Bloomberg data API */
#define NETIO_UDP_PORT_BLP2              8195 /* Bloomberg feed */
#define NETIO_UDP_PORT_VVR_DATA          8199 /* VVR DATA */
#define NETIO_UDP_PORT_TRIVNET1          8200 /* TRIVNET */
#define NETIO_UDP_PORT_TRIVNET2          8201 /* TRIVNET */
#define NETIO_UDP_PORT_AESOP             8202 /* Audio+Ethernet Standard Open Protocol */
#define NETIO_UDP_PORT_LM_PERFWORKS      8204 /* LM Perfworks */
#define NETIO_UDP_PORT_LM_INSTMGR        8205 /* LM Instmgr */
#define NETIO_UDP_PORT_LM_DTA            8206 /* LM Dta */
#define NETIO_UDP_PORT_LM_SSERVER        8207 /* LM SServer */
#define NETIO_UDP_PORT_LM_WEBWATCHER     8208 /* LM Webwatcher */
#define NETIO_UDP_PORT_REXECJ            8230 /* RexecJ Server */
#define NETIO_UDP_PORT_SYNAPSE_NHTTPS    8243 /* Synapse Non Blocking HTTPS */
#define NETIO_UDP_PORT_PANDO_SEC         8276 /* Pando Media Controlled Distribution */
#define NETIO_UDP_PORT_SYNAPSE_NHTTP     8280 /* Synapse Non Blocking HTTP */
#define NETIO_UDP_PORT_BLP3              8292 /* Bloomberg professional */
#define NETIO_UDP_PORT_BLP4              8294 /* Bloomberg intelligent client */
#define NETIO_UDP_PORT_TMI               8300 /* Transport Management Interface */
#define NETIO_UDP_PORT_AMBERON           8301 /* Amberon PPC/PPS */
#define NETIO_UDP_PORT_TNP_DISCOVER      8320 /* Thin(ium) Network Protocol */
#define NETIO_UDP_PORT_TNP               8321 /* Thin(ium) Network Protocol */
#define NETIO_UDP_PORT_SERVER_FIND       8351 /* Server Find */
#define NETIO_UDP_PORT_CRUISE_ENUM       8376 /* Cruise ENUM */
#define NETIO_UDP_PORT_CRUISE_SWROUTE    8377 /* Cruise SWROUTE */
#define NETIO_UDP_PORT_CRUISE_CONFIG     8378 /* Cruise CONFIG */
#define NETIO_UDP_PORT_CRUISE_DIAGS      8379 /* Cruise DIAGS */
#define NETIO_UDP_PORT_CRUISE_UPDATE     8380 /* Cruise UPDATE */
#define NETIO_UDP_PORT_M2MSERVICES       8383 /* M2m Services */
#define NETIO_UDP_PORT_CVD               8400 /* cvd */
#define NETIO_UDP_PORT_SABARSD           8401 /* sabarsd */
#define NETIO_UDP_PORT_ABARSD            8402 /* abarsd */
#define NETIO_UDP_PORT_ADMIND2           8403 /* admind */
#define NETIO_UDP_PORT_ESPEECH           8416 /* eSpeech Session Protocol */
#define NETIO_UDP_PORT_ESPEECH_RTP       8417 /* eSpeech RTP Protocol */
#define NETIO_UDP_PORT_CYBRO_A_BUS       8442 /* CyBro A-bus Protocol */
#define NETIO_UDP_PORT_PCSYNC_HTTPS      8443 /* PCsync HTTPS */
#define NETIO_UDP_PORT_PCSYNC_HTTP       8444 /* PCsync HTTP */
#define NETIO_UDP_PORT_COPY_DISC         8445 /* Port for copy discovery */
#define NETIO_UDP_PORT_NPMP              8450 /* npmp */
#define NETIO_UDP_PORT_OTV               8472 /* Overlay Transport Virtualization (OTV) */
#define NETIO_UDP_PORT_VP2P              8473 /* Virtual Point to Point */
#define NETIO_UDP_PORT_NOTESHARE         8474 /* AquaMinds NoteShare */
#define NETIO_UDP_PORT_FMTP              8500 /* Flight Message Transfer Protocol */
#define NETIO_UDP_PORT_CMTP_AV           8501 /* CYTEL Message Transfer Audio and Video */
#define NETIO_UDP_PORT_RTSP_ALT          8554 /* RTSP Alternate (see port 554) */
#define NETIO_UDP_PORT_D_FENCE           8555 /* SYMAX D-FENCE */
#define NETIO_UDP_PORT_ENC_TUNNEL        8567 /* EMIT tunneling protocol */
#define NETIO_UDP_PORT_ASTERIX           8600 /* Surveillance Data */
#define NETIO_UDP_PORT_CANON_CPP_DISC    8609 /* Canon Compact Printer Protocol Discovery */
#define NETIO_UDP_PORT_CANON_MFNP        8610 /* Canon MFNP Service */
#define NETIO_UDP_PORT_CANON_BJNP1       8611 /* Canon BJNP Port 1 */
#define NETIO_UDP_PORT_CANON_BJNP2       8612 /* Canon BJNP Port 2 */
#define NETIO_UDP_PORT_CANON_BJNP3       8613 /* Canon BJNP Port 3 */
#define NETIO_UDP_PORT_CANON_BJNP4       8614 /* Canon BJNP Port 4 */
#define NETIO_UDP_PORT_MSI_CPS_RM_DISC   8675 /* Motorola Solutions Customer Programming Software for Radio Management Discovery */
#define NETIO_UDP_PORT_SUN_AS_JMXRMI     8686 /* Sun App Server - JMX/RMI */
#define NETIO_UDP_PORT_DTP_NET           8732 /* DASGIP Net Services */
#define NETIO_UDP_PORT_IBUS              8733 /* iBus */
#define NETIO_UDP_PORT_MC_APPSERVER      8763 /* MC-APPSERVER */
#define NETIO_UDP_PORT_OPENQUEUE         8764 /* OPENQUEUE */
#define NETIO_UDP_PORT_ULTRASEEK_HTTP    8765 /* Ultraseek HTTP */
#define NETIO_UDP_PORT_AMCS              8766 /* Agilent Connectivity Service */
#define NETIO_UDP_PORT_DPAP              8770 /* Digital Photo Access Protocol (iPhoto) */
#define NETIO_UDP_PORT_MSGCLNT           8786 /* Message Client */
#define NETIO_UDP_PORT_MSGSRVR           8787 /* Message Server */
#define NETIO_UDP_PORT_ACD_PM            8793 /* Accedian Performance Measurement */
#define NETIO_UDP_PORT_SUNWEBADMIN       8800 /* Sun Web Server Admin Service */
#define NETIO_UDP_PORT_TRUECM            8804 /* truecm */
#define NETIO_UDP_PORT_DXSPIDER          8873 /* dxspider linking protocol */
#define NETIO_UDP_PORT_CDDBP_ALT         8880 /* CDDBP */
#define NETIO_UDP_PORT_SECURE_MQTT       8883 /* Secure MQTT */
#define NETIO_UDP_PORT_DDI_UDP_1         8888 /* NewsEDGE server UDP (UDP 1) */
#define NETIO_UDP_PORT_DDI_UDP_2         8889 /* NewsEDGE server broadcast */
#define NETIO_UDP_PORT_DDI_UDP_3         8890 /* NewsEDGE client broadcast */
#define NETIO_UDP_PORT_DDI_UDP_4         8891 /* Desktop Data UDP 3: NESS application */
#define NETIO_UDP_PORT_DDI_UDP_5         8892 /* Desktop Data UDP 4: FARM product */
#define NETIO_UDP_PORT_DDI_UDP_6         8893 /* Desktop Data UDP 5: NewsEDGE/Web application */
#define NETIO_UDP_PORT_DDI_UDP_7         8894 /* Desktop Data UDP 6: COAL application */
#define NETIO_UDP_PORT_OSPF_LITE         8899 /* ospf-lite */
#define NETIO_UDP_PORT_JMB_CDS1          8900 /* JMB-CDS 1 */
#define NETIO_UDP_PORT_JMB_CDS2          8901 /* JMB-CDS 2 */
#define NETIO_UDP_PORT_MANYONE_HTTP      8910 /* manyone-http */
#define NETIO_UDP_PORT_MANYONE_XML       8911 /* manyone-xml */
#define NETIO_UDP_PORT_WCBACKUP          8912 /* Windows Client Backup */
#define NETIO_UDP_PORT_DRAGONFLY         8913 /* Dragonfly System Service */
#define NETIO_UDP_PORT_CUMULUS_ADMIN     8954 /* Cumulus Admin Port */
#define NETIO_UDP_PORT_SUNWEBADMINS      8989 /* Sun Web Server SSL Admin Service */
#define NETIO_UDP_PORT_HTTP_WMAP         8990 /* webmail HTTP service */
#define NETIO_UDP_PORT_HTTPS_WMAP        8991 /* webmail HTTPS service */
#define NETIO_UDP_PORT_BCTP              8999 /* Brodos Crypto Trade Protocol */
#define NETIO_UDP_PORT_CSLISTENER        9000 /* CSlistener */
#define NETIO_UDP_PORT_ETLSERVICEMGR     9001 /* ETL Service Manager */
#define NETIO_UDP_PORT_DYNAMID           9002 /* DynamID authentication */
#define NETIO_UDP_PORT_OGS_CLIENT        9007 /* Open Grid Services Client */
#define NETIO_UDP_PORT_PICHAT            9009 /* Pichat Server */
#define NETIO_UDP_PORT_TAMBORA           9020 /* TAMBORA */
#define NETIO_UDP_PORT_PANAGOLIN_IDENT   9021 /* Pangolin Identification */
#define NETIO_UDP_PORT_PARAGENT          9022 /* PrivateArk Remote Agent */
#define NETIO_UDP_PORT_SWA_1             9023 /* Secure Web Access - 1 */
#define NETIO_UDP_PORT_SWA_2             9024 /* Secure Web Access - 2 */
#define NETIO_UDP_PORT_SWA_3             9025 /* Secure Web Access - 3 */
#define NETIO_UDP_PORT_SWA_4             9026 /* Secure Web Access - 4 */
#define NETIO_UDP_PORT_GLRPC             9080 /* Groove GLRPC */
#define NETIO_UDP_PORT_AURORA            9084 /* IBM AURORA Performance Visualizer */
#define NETIO_UDP_PORT_IBM_RSYSCON       9085 /* IBM Remote System Console */
#define NETIO_UDP_PORT_NET2DISPLAY       9086 /* Vesa Net2Display */
#define NETIO_UDP_PORT_CLASSIC           9087 /* Classic Data Server */
#define NETIO_UDP_PORT_SQLEXEC           9088 /* IBM Informix SQL Interface */
#define NETIO_UDP_PORT_SQLEXEC_SSL       9089 /* IBM Informix SQL Interface - Encrypted */
#define NETIO_UDP_PORT_WEBSM             9090 /* WebSM */
#define NETIO_UDP_PORT_XMLTEC_XMLMAIL    9091 /* xmltec-xmlmail */
#define NETIO_UDP_PORT_XMLIPCREGSVC      9092 /* Xml-Ipc Server Reg */
#define NETIO_UDP_PORT_HP_PDL_DATASTR    9100 /* PDL Data Streaming Port */
#define NETIO_UDP_PORT_BACULA_DIR        9101 /* Bacula Director */
#define NETIO_UDP_PORT_BACULA_FD         9102 /* Bacula File Daemon */
#define NETIO_UDP_PORT_BACULA_SD         9103 /* Bacula Storage Daemon */
#define NETIO_UDP_PORT_PEERWIRE          9104 /* PeerWire */
#define NETIO_UDP_PORT_XADMIN            9105 /* Xadmin Control Service */
#define NETIO_UDP_PORT_ASTERGATE_DISC    9106 /* Astergate Discovery Service */
#define NETIO_UDP_PORT_MXIT              9119 /* MXit Instant Messaging */
#define NETIO_UDP_PORT_DDDP              9131 /* Dynamic Device Discovery */
#define NETIO_UDP_PORT_APANI1            9160 /* apani1 */
#define NETIO_UDP_PORT_APANI2            9161 /* apani2 */
#define NETIO_UDP_PORT_APANI3            9162 /* apani3 */
#define NETIO_UDP_PORT_APANI4            9163 /* apani4 */
#define NETIO_UDP_PORT_APANI5            9164 /* apani5 */
#define NETIO_UDP_PORT_SUN_AS_JPDA       9191 /* Sun AppSvr JPDA */
#define NETIO_UDP_PORT_WAP_WSP           9200 /* WAP connectionless session service */
#define NETIO_UDP_PORT_WAP_WSP_WTP       9201 /* WAP session service */
#define NETIO_UDP_PORT_WAP_WSP_S         9202 /* WAP secure connectionless session service */
#define NETIO_UDP_PORT_WAP_WSP_WTP_S     9203 /* WAP secure session service */
#define NETIO_UDP_PORT_WAP_VCARD         9204 /* WAP vCard */
#define NETIO_UDP_PORT_WAP_VCAL          9205 /* WAP vCal */
#define NETIO_UDP_PORT_WAP_VCARD_S       9206 /* WAP vCard Secure */
#define NETIO_UDP_PORT_WAP_VCAL_S        9207 /* WAP vCal Secure */
#define NETIO_UDP_PORT_RJCDB_VCARDS      9208 /* rjcdb vCard */
#define NETIO_UDP_PORT_ALMOBILE_SYSTEM   9209 /* ALMobile System Service */
#define NETIO_UDP_PORT_OMA_MLP           9210 /* OMA Mobile Location Protocol */
#define NETIO_UDP_PORT_OMA_MLP_S         9211 /* OMA Mobile Location Protocol Secure */
#define NETIO_UDP_PORT_SERVERVIEWDBMS    9212 /* Server View dbms access */
#define NETIO_UDP_PORT_SERVERSTART       9213 /* ServerStart RemoteControl */
#define NETIO_UDP_PORT_IPDCESGBS         9214 /* IPDC ESG BootstrapService */
#define NETIO_UDP_PORT_INSIS             9215 /* Integrated Setup and Install Service */
#define NETIO_UDP_PORT_ACME              9216 /* Aionex Communication Management Engine */
#define NETIO_UDP_PORT_FSC_PORT          9217 /* FSC Communication Port */
#define NETIO_UDP_PORT_TEAMCOHERENCE     9222 /* QSC Team Coherence */
#define NETIO_UDP_PORT_MON2              9255 /* Manager On Network */
#define NETIO_UDP_PORT_TRAINGPSDATA      9277 /* GPS Data transmitted from train to ground network */
#define NETIO_UDP_PORT_PEGASUS           9278 /* Pegasus GPS Platform */
#define NETIO_UDP_PORT_PEGASUS_CTL       9279 /* Pegaus GPS System Control Interface */
#define NETIO_UDP_PORT_PGPS              9280 /* Predicted GPS */
#define NETIO_UDP_PORT_SWTP_PORT1        9281 /* SofaWare transport port 1 */
#define NETIO_UDP_PORT_SWTP_PORT2        9282 /* SofaWare transport port 2 */
#define NETIO_UDP_PORT_CALLWAVEIAM       9283 /* CallWaveIAM */
#define NETIO_UDP_PORT_VISD              9284 /* VERITAS Information Serve */
#define NETIO_UDP_PORT_N2H2SERVER        9285 /* N2H2 Filter Service Port */
#define NETIO_UDP_PORT_N2RECEIVE         9286 /* n2 monitoring receiver */
#define NETIO_UDP_PORT_CUMULUS           9287 /* Cumulus */
#define NETIO_UDP_PORT_ARMTECHDAEMON     9292 /* ArmTech Daemon */
#define NETIO_UDP_PORT_STORVIEW          9293 /* StorView Client */
#define NETIO_UDP_PORT_ARMCENTERHTTP     9294 /* ARMCenter http Service */
#define NETIO_UDP_PORT_ARMCENTERHTTPS    9295 /* ARMCenter https Service */
#define NETIO_UDP_PORT_VRACE             9300 /* Virtual Racing Service */
#define NETIO_UDP_PORT_SECURE_TS         9318 /* PKIX TimeStamp over TLS */
#define NETIO_UDP_PORT_GUIBASE           9321 /* guibase */
#define NETIO_UDP_PORT_MPIDCMGR          9343 /* MpIdcMgr */
#define NETIO_UDP_PORT_MPHLPDMC          9344 /* Mphlpdmc */
#define NETIO_UDP_PORT_CTECHLICENSING    9346 /* C Tech Licensing */
#define NETIO_UDP_PORT_FJDMIMGR          9374 /* fjdmimgr */
#define NETIO_UDP_PORT_BOXP              9380 /* Brivs! Open Extensible Protocol */
#define NETIO_UDP_PORT_FJINVMGR          9396 /* fjinvmgr */
#define NETIO_UDP_PORT_MPIDCAGT          9397 /* MpIdcAgt */
#define NETIO_UDP_PORT_SEC_T4NET_SRV     9400 /* Samsung Twain for Network Server */
#define NETIO_UDP_PORT_SEC_T4NET_CLT     9401 /* Samsung Twain for Network Client */
#define NETIO_UDP_PORT_SEC_PC2FAX_SRV    9402 /* Samsung PC2FAX for Network Server */
#define NETIO_UDP_PORT_GIT               9418 /* git pack transfer service */
#define NETIO_UDP_PORT_TUNGSTEN_HTTPS    9443 /* WSO2 Tungsten HTTPS */
#define NETIO_UDP_PORT_WSO2ESB_CONSOLE   9444 /* WSO2 ESB Administration Console HTTPS */
#define NETIO_UDP_PORT_SNTLKEYSSRVR      9450 /* Sentinel Keys Server */
#define NETIO_UDP_PORT_ISMSERVER         9500 /* ismserver */
#define NETIO_UDP_PORT_SMA_SPW           9522 /* SMA Speedwire */
#define NETIO_UDP_PORT_MNGSUITE          9535 /* Management Suite Remote Control */
#define NETIO_UDP_PORT_LAES_BF           9536 /* Surveillance buffering function */
#define NETIO_UDP_PORT_TRISPEN_SRA       9555 /* Trispen Secure Remote Access */
#define NETIO_UDP_PORT_LDGATEWAY         9592 /* LANDesk Gateway */
#define NETIO_UDP_PORT_CBA8              9593 /* LANDesk Management Agent (cba8) */
#define NETIO_UDP_PORT_MSGSYS            9594 /* Message System */
#define NETIO_UDP_PORT_PDS               9595 /* Ping Discovery Service */
#define NETIO_UDP_PORT_MERCURY_DISC      9596 /* Mercury Discovery */
#define NETIO_UDP_PORT_PD_ADMIN          9597 /* PD Administration */
#define NETIO_UDP_PORT_VSCP              9598 /* Very Simple Ctrl Protocol */
#define NETIO_UDP_PORT_ROBIX             9599 /* Robix */
#define NETIO_UDP_PORT_MICROMUSE_NCPW    9600 /* MICROMUSE-NCPW */
#define NETIO_UDP_PORT_STREAMCOMM_DS     9612 /* StreamComm User Directory */
#define NETIO_UDP_PORT_CONDOR            9618 /* Condor Collector Service */
#define NETIO_UDP_PORT_ODBCPATHWAY       9628 /* ODBC Pathway Service */
#define NETIO_UDP_PORT_UNIPORT           9629 /* UniPort SSO Controller */
#define NETIO_UDP_PORT_MC_COMM           9632 /* Mobile-C Communications */
#define NETIO_UDP_PORT_XMMS2             9667 /* Cross-platform Music Multiplexing System */
#define NETIO_UDP_PORT_TEC5_SDCTP        9668 /* tec5 Spectral Device Control Protocol */
#define NETIO_UDP_PORT_CLIENT_WAKEUP     9694 /* T-Mobile Client Wakeup Message */
#define NETIO_UDP_PORT_CCNX              9695 /* Content Centric Networking */
#define NETIO_UDP_PORT_BOARD_ROAR        9700 /* Board M.I.T. Service */
#define NETIO_UDP_PORT_L5NAS_PARCHAN     9747 /* L5NAS Parallel Channel */
#define NETIO_UDP_PORT_BOARD_VOIP        9750 /* Board M.I.T. Synchronous Collaboration */
#define NETIO_UDP_PORT_RASADV            9753 /* rasadv */
#define NETIO_UDP_PORT_TUNGSTEN_HTTP     9762 /* WSO2 Tungsten HTTP */
#define NETIO_UDP_PORT_DAVSRC            9800 /* WebDav Source Port */
#define NETIO_UDP_PORT_SSTP_2            9801 /* Sakura Script Transfer Protocol-2 */
#define NETIO_UDP_PORT_DAVSRCS           9802 /* WebDAV Source TLS/SSL */
#define NETIO_UDP_PORT_SAPV1             9875 /* Session Announcement v1 */
#define NETIO_UDP_PORT_KCA_SERVICE       9878 /* The KX509 Kerberized Certificate Issuance Protocol in Use in 2012 */
#define NETIO_UDP_PORT_CYBORG_SYSTEMS    9888 /* CYBORG Systems */
#define NETIO_UDP_PORT_GT_PROXY          9889 /* Port for Cable network related data proxy or repeater */
#define NETIO_UDP_PORT_MONKEYCOM         9898 /* MonkeyCom */
#define NETIO_UDP_PORT_SCTP_TUNNELING    9899 /* SCTP TUNNELING */
#define NETIO_UDP_PORT_IUA               9900 /* IUA */
#define NETIO_UDP_PORT_ENRP              9901 /* enrp server channel */
#define NETIO_UDP_PORT_MULTICAST_PING    9903 /* Multicast Ping Protocol */
#define NETIO_UDP_PORT_DOMAINTIME        9909 /* domaintime */
#define NETIO_UDP_PORT_SYPE_TRANSPORT    9911 /* SYPECom Transport Protocol */
#define NETIO_UDP_PORT_APC_9950          9950 /* APC 9950 */
#define NETIO_UDP_PORT_APC_9951          9951 /* APC 9951 */
#define NETIO_UDP_PORT_APC_9952          9952 /* APC 9952 */
#define NETIO_UDP_PORT_ACIS              9953 /* 9953 */
#define NETIO_UDP_PORT_ALLJOYN_MCM       9955 /* Contact Port for AllJoyn multiplexed constrained messaging */
#define NETIO_UDP_PORT_ALLJOYN           9956 /* Alljoyn Name Service */
#define NETIO_UDP_PORT_ODNSP             9966 /* OKI Data Network Setting Protocol */
#define NETIO_UDP_PORT_DSM_SCM_TARGET    9987 /* DSM/SCM Target Interface */
#define NETIO_UDP_PORT_OSM_APPSRVR       9990 /* OSM Applet Server */
#define NETIO_UDP_PORT_OSM_OEV           9991 /* OSM Event Server */
#define NETIO_UDP_PORT_PALACE_1          9992 /* OnLive-1 */
#define NETIO_UDP_PORT_PALACE_2          9993 /* OnLive-2 */
#define NETIO_UDP_PORT_PALACE_3          9994 /* OnLive-3 */
#define NETIO_UDP_PORT_PALACE_4          9995 /* Palace-4 */
#define NETIO_UDP_PORT_PALACE_5          9996 /* Palace-5 */
#define NETIO_UDP_PORT_PALACE_6          9997 /* Palace-6 */
#define NETIO_UDP_PORT_DISTINCT32        9998 /* Distinct32 */
#define NETIO_UDP_PORT_DISTINCT          9999 /* distinct */
#define NETIO_UDP_PORT_NDMP              10000 /* Network Data Management Protocol */
#define NETIO_UDP_PORT_SCP_CONFIG        10001 /* SCP Configuration */
#define NETIO_UDP_PORT_DOCUMENTUM        10002 /* EMC-Documentum Content Server Product */
#define NETIO_UDP_PORT_DOCUMENTUM_S      10003 /* "EMC-Documentum Content Server Product */
#define NETIO_UDP_PORT_MVS_CAPACITY      10007 /* MVS Capacity */
#define NETIO_UDP_PORT_OCTOPUS           10008 /* Octopus Multiplexer */
#define NETIO_UDP_PORT_SWDTP_SV          10009 /* Systemwalker Desktop Patrol */
#define NETIO_UDP_PORT_ZABBIX_AGENT      10050 /* Zabbix Agent */
#define NETIO_UDP_PORT_ZABBIX_TRAPPER    10051 /* Zabbix Trapper */
#define NETIO_UDP_PORT_AMANDA            10080 /* Amanda */
#define NETIO_UDP_PORT_FAMDC             10081 /* FAM Archive Server */
#define NETIO_UDP_PORT_ITAP_DDTP         10100 /* VERITAS ITAP DDTP */
#define NETIO_UDP_PORT_EZMEETING_2       10101 /* eZmeeting */
#define NETIO_UDP_PORT_EZPROXY_2         10102 /* eZproxy */
#define NETIO_UDP_PORT_EZRELAY           10103 /* eZrelay */
#define NETIO_UDP_PORT_SWDTP             10104 /* Systemwalker Desktop Patrol */
#define NETIO_UDP_PORT_BCTP_SERVER       10107 /* "VERITAS BCTP */
#define NETIO_UDP_PORT_NMEA_0183         10110 /* NMEA-0183 Navigational Data */
#define NETIO_UDP_PORT_NMEA_ONENET       10111 /* NMEA OneNet multicast messaging */
#define NETIO_UDP_PORT_NETIQ_ENDPOINT    10113 /* NetIQ Endpoint */
#define NETIO_UDP_PORT_NETIQ_QCHECK      10114 /* NetIQ Qcheck */
#define NETIO_UDP_PORT_NETIQ_ENDPT       10115 /* NetIQ Endpoint */
#define NETIO_UDP_PORT_NETIQ_VOIPA       10116 /* NetIQ VoIP Assessor */
#define NETIO_UDP_PORT_IQRM              10117 /* NetIQ IQCResource Managament Svc */
#define NETIO_UDP_PORT_BMC_PERF_SD       10128 /* BMC-PERFORM-SERVICE DAEMON */
#define NETIO_UDP_PORT_QB_DB_SERVER      10160 /* QB Database Server */
#define NETIO_UDP_PORT_SNMPDTLS          10161 /* SNMP-DTLS */
#define NETIO_UDP_PORT_SNMPDTLS_TRAP     10162 /* SNMP-Trap-DTLS */
#define NETIO_UDP_PORT_TRISOAP           10200 /* Trigence AE Soap Service */
#define NETIO_UDP_PORT_RSCS              10201 /* Remote Server Control and Test Service */
#define NETIO_UDP_PORT_APOLLO_RELAY      10252 /* Apollo Relay Port */
#define NETIO_UDP_PORT_AXIS_WIMP_PORT    10260 /* Axis WIMP Port */
#define NETIO_UDP_PORT_BLOCKS            10288 /* Blocks */
#define NETIO_UDP_PORT_BNGSYNC           10439 /* BalanceNG session table synchronization protocol */
#define NETIO_UDP_PORT_HIP_NAT_T         10500 /* HIP NAT-Traversal */
#define NETIO_UDP_PORT_MOS_LOWER         10540 /* MOS Media Object Metadata Port */
#define NETIO_UDP_PORT_MOS_UPPER         10541 /* MOS Running Order Port */
#define NETIO_UDP_PORT_MOS_AUX           10542 /* MOS Low Priority Port */
#define NETIO_UDP_PORT_MOS_SOAP          10543 /* MOS SOAP Default Port */
#define NETIO_UDP_PORT_MOS_SOAP_OPT      10544 /* MOS SOAP Optional Port */
#define NETIO_UDP_PORT_GAP               10800 /* Gestor de Acaparamiento para Pocket PCs */
#define NETIO_UDP_PORT_LPDG              10805 /* LUCIA Pareja Data Group */
#define NETIO_UDP_PORT_NMC_DISC          10810 /* Nuance Mobile Care Discovery */
#define NETIO_UDP_PORT_HELIX             10860 /* Helix Client/Server */
#define NETIO_UDP_PORT_BVEAPI            10880 /* BVEssentials HTTP API */
#define NETIO_UDP_PORT_RMIAUX            10990 /* Auxiliary RMI Port */
#define NETIO_UDP_PORT_IRISA             11000 /* IRISA */
#define NETIO_UDP_PORT_METASYS           11001 /* Metasys */
#define NETIO_UDP_PORT_CEFD_VMP          10023 /* Comtech EF-Data's Vipersat Management Protocol */
#define NETIO_UDP_PORT_WEAVE             11095 /* Nest device-to-device and device-to-service application protocol */
#define NETIO_UDP_PORT_SGI_LK            11106 /* SGI LK Licensing service */
#define NETIO_UDP_PORT_MYQ_TERMLINK      11108 /* Hardware Terminals Discovery and Low-Level Communication Protocol */
#define NETIO_UDP_PORT_VCE               11111 /* Viral Computing Environment (VCE) */
#define NETIO_UDP_PORT_DICOM             11112 /* DICOM */
#define NETIO_UDP_PORT_SUNCACAO_SNMP     11161 /* sun cacao snmp access point */
#define NETIO_UDP_PORT_SUNCACAO_JMXMP    11162 /* sun cacao JMX-remoting access point */
#define NETIO_UDP_PORT_SUNCACAO_RMI      11163 /* sun cacao rmi registry access point */
#define NETIO_UDP_PORT_SUNCACAO_CSA      11164 /* sun cacao command-streaming access point */
#define NETIO_UDP_PORT_SUNCACAO_WEBSVC   11165 /* sun cacao web service access point */
#define NETIO_UDP_PORT_SNSS              11171 /* Surgical Notes Security Service Discovery (SNSS) */
#define NETIO_UDP_PORT_SMSQP             11201 /* smsqp */
#define NETIO_UDP_PORT_WIFREE            11208 /* WiFree Service */
#define NETIO_UDP_PORT_MEMCACHE          11211 /* Memory cache service */
#define NETIO_UDP_PORT_IMIP              11319 /* IMIP */
#define NETIO_UDP_PORT_IMIP_CHANNELS     11320 /* IMIP Channels Port */
#define NETIO_UDP_PORT_ARENA_SERVER      11321 /* Arena Server Listen */
#define NETIO_UDP_PORT_ATM_UHAS          11367 /* ATM UHAS */
#define NETIO_UDP_PORT_HKP               11371 /* OpenPGP HTTP Keyserver */
#define NETIO_UDP_PORT_LSDP              11430 /* Lenbrook Service Discovery Protocol */
#define NETIO_UDP_PORT_TEMPEST_PORT      11600 /* Tempest Protocol Port */
#define NETIO_UDP_PORT_H323CALLSIGALT    11720 /* H.323 Call Control Signalling Alternate */
#define NETIO_UDP_PORT_EMC_XSW_DCACHE    11723 /* EMC XtremSW distributed cache */
#define NETIO_UDP_PORT_INTREPID_SSL      11751 /* Intrepid SSL */
#define NETIO_UDP_PORT_LANSCHOOL_MPT     11796 /* Lanschool Multipoint */
#define NETIO_UDP_PORT_XORAYA            11876 /* X2E Xoraya Multichannel protocol */
#define NETIO_UDP_PORT_X2E_DISC          11877 /* X2E service discovery protocol */
#define NETIO_UDP_PORT_SYSINFO_SP        11967 /* SysInfo Sercice Protocol */
#define NETIO_UDP_PORT_ENTEXTXID         12000 /* IBM Enterprise Extender SNA XID Exchange */
#define NETIO_UDP_PORT_ENTEXTNETWK       12001 /* IBM Enterprise Extender SNA COS Network Priority */
#define NETIO_UDP_PORT_ENTEXTHIGH        12002 /* IBM Enterprise Extender SNA COS High Priority */
#define NETIO_UDP_PORT_ENTEXTMED         12003 /* IBM Enterprise Extender SNA COS Medium Priority */
#define NETIO_UDP_PORT_ENTEXTLOW         12004 /* IBM Enterprise Extender SNA COS Low Priority */
#define NETIO_UDP_PORT_DBISAMSERVER1     12005 /* DBISAM Database Server - Regular */
#define NETIO_UDP_PORT_DBISAMSERVER2     12006 /* DBISAM Database Server - Admin */
#define NETIO_UDP_PORT_ACCURACER         12007 /* Accuracer Database System Server */
#define NETIO_UDP_PORT_ACCURACER_DBMS    12008 /* Accuracer Database System Admin */
#define NETIO_UDP_PORT_GHVPN             12009 /* Green Hills VPN */
#define NETIO_UDP_PORT_VIPERA            12012 /* Vipera Messaging Service */
#define NETIO_UDP_PORT_VIPERA_SSL        12013 /* Vipera Messaging Service over SSL Communication */
#define NETIO_UDP_PORT_RETS_SSL          12109 /* RETS over SSL */
#define NETIO_UDP_PORT_NUPAPER_SS        12121 /* NuPaper Session Service */
#define NETIO_UDP_PORT_CAWAS             12168 /* CA Web Access Service */
#define NETIO_UDP_PORT_HIVEP             12172 /* HiveP */
#define NETIO_UDP_PORT_LINOGRIDENGINE    12300 /* LinoGrid Engine */
#define NETIO_UDP_PORT_WAREHOUSE_SSS     12321 /* Warehouse Monitoring Syst SSS */
#define NETIO_UDP_PORT_WAREHOUSE         12322 /* Warehouse Monitoring Syst */
#define NETIO_UDP_PORT_ITALK             12345 /* Italk Chat System */
#define NETIO_UDP_PORT_TSAF              12753 /* tsaf port */
#define NETIO_UDP_PORT_I_ZIPQD           13160 /* I-ZIPQD */
#define NETIO_UDP_PORT_BCSLOGC           13216 /* Black Crow Software application logging */
#define NETIO_UDP_PORT_RS_PIAS           13217 /* R&S Proxy Installation Assistant Service */
#define NETIO_UDP_PORT_EMC_VCAS_UDP      13218 /* EMV Virtual CAS Service Discovery */
#define NETIO_UDP_PORT_POWWOW_CLIENT     13223 /* PowWow Client */
#define NETIO_UDP_PORT_POWWOW_SERVER     13224 /* PowWow Server */
#define NETIO_UDP_PORT_DOIP_DISC         13400 /* DoIP Discovery */
#define NETIO_UDP_PORT_BPRD              13720 /* BPRD Protocol (VERITAS NetBackup) */
#define NETIO_UDP_PORT_BPDBM             13721 /* BPDBM Protocol (VERITAS NetBackup) */
#define NETIO_UDP_PORT_BPJAVA_MSVC       13722 /* BP Java MSVC Protocol */
#define NETIO_UDP_PORT_VNETD             13724 /* Veritas Network Utility */
#define NETIO_UDP_PORT_BPCD              13782 /* VERITAS NetBackup */
#define NETIO_UDP_PORT_VOPIED            13783 /* VOPIED Protocol */
#define NETIO_UDP_PORT_NBDB              13785 /* NetBackup Database */
#define NETIO_UDP_PORT_NOMDB             13786 /* Veritas-nomdb */
#define NETIO_UDP_PORT_DSMCC_CONFIG      13818 /* DSMCC Config */
#define NETIO_UDP_PORT_DSMCC_SESSION     13819 /* DSMCC Session Messages */
#define NETIO_UDP_PORT_DSMCC_PASSTHRU    13820 /* DSMCC Pass-Thru Messages */
#define NETIO_UDP_PORT_DSMCC_DOWNLOAD    13821 /* DSMCC Download Protocol */
#define NETIO_UDP_PORT_DSMCC_CCP         13822 /* DSMCC Channel Change Protocol */
#define NETIO_UDP_PORT_UCONTROL          13894 /* Ultimate Control communication protocol */
#define NETIO_UDP_PORT_DTA_SYSTEMS       13929 /* D-TA SYSTEMS */
#define NETIO_UDP_PORT_SCOTTY_FT         14000 /* SCOTTY High-Speed Filetransfer */
#define NETIO_UDP_PORT_SUA               14001 /* De-Registered */
#define NETIO_UDP_PORT_SCOTTY_DISC       14002 /* Discovery of a SCOTTY hardware codec board */
#define NETIO_UDP_PORT_SAGE_BEST_COM1    14033 /* sage Best! Config Server 1 */
#define NETIO_UDP_PORT_SAGE_BEST_COM2    14034 /* sage Best! Config Server 2 */
#define NETIO_UDP_PORT_VCS_APP           14141 /* VCS Application */
#define NETIO_UDP_PORT_ICPP              14142 /* IceWall Cert Protocol */
#define NETIO_UDP_PORT_GCM_APP           14145 /* GCM Application */
#define NETIO_UDP_PORT_VRTS_TDD          14149 /* Veritas Traffic Director */
#define NETIO_UDP_PORT_VAD               14154 /* Veritas Application Director */
#define NETIO_UDP_PORT_CPS               14250 /* Fencing Server */
#define NETIO_UDP_PORT_CA_WEB_UPDATE     14414 /* CA eTrust Web Update Service */
#define NETIO_UDP_PORT_HDE_LCESRVR_1     14936 /* hde-lcesrvr-1 */
#define NETIO_UDP_PORT_HDE_LCESRVR_2     14937 /* hde-lcesrvr-2 */
#define NETIO_UDP_PORT_HYDAP             15000 /* Hypack Data Aquisition */
#define NETIO_UDP_PORT_V2G_SECC          15118 /* v2g Supply Equipment Communication Controller Discovery Protocol */
#define NETIO_UDP_PORT_XPILOT            15345 /* XPilot Contact Port */
#define NETIO_UDP_PORT_3LINK             15363 /* 3Link Negotiation */
#define NETIO_UDP_PORT_CISCO_SNAT        15555 /* Cisco Stateful NAT */
#define NETIO_UDP_PORT_BEX_XR            15660 /* Backup Express Restore Server */
#define NETIO_UDP_PORT_PTP               15740 /* Picture Transfer Protocol */
#define NETIO_UDP_PORT_2PING             15998 /* 2ping Bi-Directional Ping Service */
#define NETIO_UDP_PORT_ALFIN             16003 /* Automation and Control by REGULACE.ORG */
#define NETIO_UDP_PORT_SUN_SEA_PORT      16161 /* Solaris SEA Port */
#define NETIO_UDP_PORT_ETB4J             16309 /* etb4j */
#define NETIO_UDP_PORT_PDUNCS            16310 /* "Policy Distribute */
#define NETIO_UDP_PORT_PDEFMNS           16311 /* Policy definition and update management */
#define NETIO_UDP_PORT_NETSERIALEXT1     16360 /* Network Serial Extension Ports One */
#define NETIO_UDP_PORT_NETSERIALEXT2     16361 /* Network Serial Extension Ports Two */
#define NETIO_UDP_PORT_NETSERIALEXT3     16367 /* Network Serial Extension Ports Three */
#define NETIO_UDP_PORT_NETSERIALEXT4     16368 /* Network Serial Extension Ports Four */
#define NETIO_UDP_PORT_CONNECTED         16384 /* Connected Corp */
#define NETIO_UDP_PORT_VTP               16666 /* Vidder Tunnel Protocol */
#define NETIO_UDP_PORT_NEWBAY_SNC_MC     16900 /* Newbay Mobile Client Update Service */
#define NETIO_UDP_PORT_SGCIP             16950 /* Simple Generic Client Interface Protocol */
#define NETIO_UDP_PORT_INTEL_RCI_MP      16991 /* INTEL-RCI-MP */
#define NETIO_UDP_PORT_AMT_SOAP_HTTP     16992 /* Intel(R) AMT SOAP/HTTP */
#define NETIO_UDP_PORT_AMT_SOAP_HTTPS    16993 /* Intel(R) AMT SOAP/HTTPS */
#define NETIO_UDP_PORT_AMT_REDIR_TCP     16994 /* Intel(R) AMT Redirection/TCP */
#define NETIO_UDP_PORT_AMT_REDIR_TLS     16995 /* Intel(R) AMT Redirection/TLS */
#define NETIO_UDP_PORT_SOUNDSVIRTUAL     17185 /* Sounds Virtual */
#define NETIO_UDP_PORT_CHIPPER           17219 /* Chipper */
#define NETIO_UDP_PORT_AVTP              17220 /* IEEE 1722 Transport Protocol for Time Sensitive Applications */
#define NETIO_UDP_PORT_AVDECC            17221 /* "IEEE 1722.1 AVB Discovery */
#define NETIO_UDP_PORT_CPSP              17222 /* Control Plane Synchronization Protocol (SPSP) */
#define NETIO_UDP_PORT_INTEGRIUS_STP     17234 /* Integrius Secure Tunnel Protocol */
#define NETIO_UDP_PORT_SSH_MGMT          17235 /* SSH Tectia Manager */
#define NETIO_UDP_PORT_DB_LSP_DISC       17500 /* Dropbox LanSync Discovery */
#define NETIO_UDP_PORT_EA                17729 /* Eclipse Aviation */
#define NETIO_UDP_PORT_ZEP               17754 /* Encap. ZigBee Packets */
#define NETIO_UDP_PORT_ZIGBEE_IP         17755 /* ZigBee IP Transport Service */
#define NETIO_UDP_PORT_ZIGBEE_IPS        17756 /* ZigBee IP Transport Secure Service */
#define NETIO_UDP_PORT_BIIMENU           18000 /* "Beckman Instruments */
#define NETIO_UDP_PORT_OPSEC_CVP         18181 /* OPSEC CVP */
#define NETIO_UDP_PORT_OPSEC_UFP         18182 /* OPSEC UFP */
#define NETIO_UDP_PORT_OPSEC_SAM         18183 /* OPSEC SAM */
#define NETIO_UDP_PORT_OPSEC_LEA         18184 /* OPSEC LEA */
#define NETIO_UDP_PORT_OPSEC_OMI         18185 /* OPSEC OMI */
#define NETIO_UDP_PORT_OHSC              18186 /* Occupational Health Sc */
#define NETIO_UDP_PORT_OPSEC_ELA         18187 /* OPSEC ELA */
#define NETIO_UDP_PORT_CHECKPOINT_RTM    18241 /* Check Point RTM */
#define NETIO_UDP_PORT_GV_PF             18262 /* GV NetConfig Service */
#define NETIO_UDP_PORT_AC_CLUSTER        18463 /* AC Cluster */
#define NETIO_UDP_PORT_RDS_IB            18634 /* Reliable Datagram Service */
#define NETIO_UDP_PORT_RDS_IP            18635 /* Reliable Datagram Service over IP */
#define NETIO_UDP_PORT_IQUE              18769 /* IQue Protocol */
#define NETIO_UDP_PORT_INFOTOS           18881 /* Infotos */
#define NETIO_UDP_PORT_APC_NECMP         18888 /* APCNECMP */
#define NETIO_UDP_PORT_IGRID             19000 /* iGrid Server */
#define NETIO_UDP_PORT_SCINTILLA         19007 /* Scintilla protocol for device services */
#define NETIO_UDP_PORT_OPSEC_UAA         19191 /* OPSEC UAA */
#define NETIO_UDP_PORT_UA_SECUREAGENT    19194 /* UserAuthority SecureAgent */
#define NETIO_UDP_PORT_KEYSRVR           19283 /* Key Server for SASSAFRAS */
#define NETIO_UDP_PORT_KEYSHADOW         19315 /* Key Shadow for SASSAFRAS */
#define NETIO_UDP_PORT_MTRGTRANS         19398 /* mtrgtrans */
#define NETIO_UDP_PORT_HP_SCO            19410 /* hp-sco */
#define NETIO_UDP_PORT_HP_SCA            19411 /* hp-sca */
#define NETIO_UDP_PORT_HP_SESSMON        19412 /* HP-SESSMON */
#define NETIO_UDP_PORT_FXUPTP            19539 /* FXUPTP */
#define NETIO_UDP_PORT_SXUPTP            19540 /* SXUPTP */
#define NETIO_UDP_PORT_JCP               19541 /* JCP Client */
#define NETIO_UDP_PORT_MLE               19788 /* Mesh Link Establishment */
#define NETIO_UDP_PORT_DNP_SEC           19999 /* Distributed Network Protocol - Secure */
#define NETIO_UDP_PORT_DNP               20000 /* DNP */
#define NETIO_UDP_PORT_MICROSAN          20001 /* MicroSAN */
#define NETIO_UDP_PORT_COMMTACT_HTTP     20002 /* Commtact HTTP */
#define NETIO_UDP_PORT_COMMTACT_HTTPS    20003 /* Commtact HTTPS */
#define NETIO_UDP_PORT_OPENWEBNET        20005 /* OpenWebNet protocol for electric network */
#define NETIO_UDP_PORT_SS_IDI_DISC       20012 /* Samsung Interdevice Interaction discovery */
#define NETIO_UDP_PORT_OPENDEPLOY        20014 /* OpenDeploy Listener */
#define NETIO_UDP_PORT_NBURN_ID          20034 /* "NetBurner ID Port */
#define NETIO_UDP_PORT_TMOPHL7MTS        20046 /* TMOP HL7 Message Transfer Service */
#define NETIO_UDP_PORT_MOUNTD            20048 /* NFS mount protocol */
#define NETIO_UDP_PORT_NFSRDMA           20049 /* Network File System (NFS) over RDMA */
#define NETIO_UDP_PORT_TOLFAB            20167 /* TOLfab Data Change */
#define NETIO_UDP_PORT_IPDTP_PORT        20202 /* IPD Tunneling Port */
#define NETIO_UDP_PORT_IPULSE_ICS        20222 /* iPulse-ICS */
#define NETIO_UDP_PORT_EMWAVEMSG         20480 /* emWave Message Service */
#define NETIO_UDP_PORT_TRACK             20670 /* Track */
#define NETIO_UDP_PORT_ATHAND_MMP        20999 /* AT Hand MMP */
#define NETIO_UDP_PORT_IRTRANS           21000 /* IRTrans Control */
#define NETIO_UDP_PORT_DFSERVER          21554 /* MineScape Design File Server */
#define NETIO_UDP_PORT_VOFR_GATEWAY      21590 /* VoFR Gateway */
#define NETIO_UDP_PORT_TVPM              21800 /* TVNC Pro Multiplexing */
#define NETIO_UDP_PORT_WEBPHONE          21845 /* webphone */
#define NETIO_UDP_PORT_NETSPEAK_IS       21846 /* NetSpeak Corp. Directory Services */
#define NETIO_UDP_PORT_NETSPEAK_CS       21847 /* NetSpeak Corp. Connection Services */
#define NETIO_UDP_PORT_NETSPEAK_ACD      21848 /* NetSpeak Corp. Automatic Call Distribution */
#define NETIO_UDP_PORT_NETSPEAK_CPS      21849 /* NetSpeak Corp. Credit Processing System */
#define NETIO_UDP_PORT_SNAPENETIO        22000 /* SNAPenetIO */
#define NETIO_UDP_PORT_OPTOCONTROL       22001 /* OptoControl */
#define NETIO_UDP_PORT_OPTOHOST002       22002 /* Opto Host Port 2 */
#define NETIO_UDP_PORT_OPTOHOST003       22003 /* Opto Host Port 3 */
#define NETIO_UDP_PORT_OPTOHOST004       22004 /* Opto Host Port 4 */
#define NETIO_UDP_PORT_OPTOHOST005       22005 /* Opto Host Port 5 */
#define NETIO_UDP_PORT_WNN6              22273 /* wnn6 */
#define NETIO_UDP_PORT_CIS               22305 /* CompactIS Tunnel */
#define NETIO_UDP_PORT_CIS_SECURE        22343 /* CompactIS Secure Tunnel */
#define NETIO_UDP_PORT_WIBUKEY           22347 /* WibuKey Standard WkLan */
#define NETIO_UDP_PORT_CODEMETER         22350 /* CodeMeter Standard */
#define NETIO_UDP_PORT_VOCALTEC_PHONE    22555 /* Vocaltec Internet Phone */
#define NETIO_UDP_PORT_TALIKASERVER      22763 /* Talika Main Server */
#define NETIO_UDP_PORT_AWS_BRF           22800 /* Telerate Information Platform LAN */
#define NETIO_UDP_PORT_BRF_GW            22951 /* Telerate Information Platform WAN */
#define NETIO_UDP_PORT_INOVAPORT1        23000 /* Inova LightLink Server Type 1 */
#define NETIO_UDP_PORT_INOVAPORT2        23001 /* Inova LightLink Server Type 2 */
#define NETIO_UDP_PORT_INOVAPORT3        23002 /* Inova LightLink Server Type 3 */
#define NETIO_UDP_PORT_INOVAPORT4        23003 /* Inova LightLink Server Type 4 */
#define NETIO_UDP_PORT_INOVAPORT5        23004 /* Inova LightLink Server Type 5 */
#define NETIO_UDP_PORT_INOVAPORT6        23005 /* Inova LightLink Server Type 6 */
#define NETIO_UDP_PORT_S102              23272 /* S102 application */
#define NETIO_UDP_PORT_ELXMGMT           23333 /* Emulex HBAnyware Remote Management */
#define NETIO_UDP_PORT_NOVAR_DBASE       23400 /* Novar Data */
#define NETIO_UDP_PORT_NOVAR_ALARM       23401 /* Novar Alarm */
#define NETIO_UDP_PORT_NOVAR_GLOBAL      23402 /* Novar Global */
#define NETIO_UDP_PORT_MED_LTP           24000 /* med-ltp */
#define NETIO_UDP_PORT_MED_FSP_RX        24001 /* med-fsp-rx */
#define NETIO_UDP_PORT_MED_FSP_TX        24002 /* med-fsp-tx */
#define NETIO_UDP_PORT_MED_SUPP          24003 /* med-supp */
#define NETIO_UDP_PORT_MED_OVW           24004 /* med-ovw */
#define NETIO_UDP_PORT_MED_CI            24005 /* med-ci */
#define NETIO_UDP_PORT_MED_NET_SVC       24006 /* med-net-svc */
#define NETIO_UDP_PORT_FILESPHERE        24242 /* fileSphere */
#define NETIO_UDP_PORT_VISTA_4GL         24249 /* Vista 4GL */
#define NETIO_UDP_PORT_ILD               24321 /* Isolv Local Directory */
#define NETIO_UDP_PORT_HID               24322 /* Transport of Human Interface Device data streams */
#define NETIO_UDP_PORT_INTEL_RCI         24386 /* "Intel RCI */
#define NETIO_UDP_PORT_TONIDODS          24465 /* Tonido Domain Server */
#define NETIO_UDP_PORT_BINKP             24554 /* BINKP */
#define NETIO_UDP_PORT_CANDITV           24676 /* Canditv Message Service */
#define NETIO_UDP_PORT_FLASHFILER        24677 /* FlashFiler */
#define NETIO_UDP_PORT_PROACTIVATE       24678 /* Turbopower Proactivate */
#define NETIO_UDP_PORT_TCC_HTTP          24680 /* TCC User HTTP Service */
#define NETIO_UDP_PORT_ASSOC_DISC        24850 /* Device Association Discovery */
#define NETIO_UDP_PORT_FIND              24922 /* Find Identification of Network Devices */
#define NETIO_UDP_PORT_ICL_TWOBASE1      25000 /* icl-twobase1 */
#define NETIO_UDP_PORT_ICL_TWOBASE2      25001 /* icl-twobase2 */
#define NETIO_UDP_PORT_ICL_TWOBASE3      25002 /* icl-twobase3 */
#define NETIO_UDP_PORT_ICL_TWOBASE4      25003 /* icl-twobase4 */
#define NETIO_UDP_PORT_ICL_TWOBASE5      25004 /* icl-twobase5 */
#define NETIO_UDP_PORT_ICL_TWOBASE6      25005 /* icl-twobase6 */
#define NETIO_UDP_PORT_ICL_TWOBASE7      25006 /* icl-twobase7 */
#define NETIO_UDP_PORT_ICL_TWOBASE8      25007 /* icl-twobase8 */
#define NETIO_UDP_PORT_ICL_TWOBASE9      25008 /* icl-twobase9 */
#define NETIO_UDP_PORT_ICL_TWOBASE10     25009 /* icl-twobase10 */
#define NETIO_UDP_PORT_VOCALTEC_HOS      25793 /* Vocaltec Address Server */
#define NETIO_UDP_PORT_TASP_NET          25900 /* TASP Network Comm */
#define NETIO_UDP_PORT_NIOBSERVER        25901 /* NIObserver */
#define NETIO_UDP_PORT_NILINKANALYST     25902 /* NILinkAnalyst */
#define NETIO_UDP_PORT_NIPROBE           25903 /* NIProbe */
#define NETIO_UDP_PORT_BF_GAME           25954 /* Bitfighter game server */
#define NETIO_UDP_PORT_BF_MASTER         25955 /* Bitfighter master server */
#define NETIO_UDP_PORT_QUAKE             26000 /* quake */
#define NETIO_UDP_PORT_SCSCP             26133 /* Symbolic Computation Software Composability Protocol */
#define NETIO_UDP_PORT_WNN6_DS           26208 /* wnn6-ds */
#define NETIO_UDP_PORT_EZPROXY           26260 /* eZproxy */
#define NETIO_UDP_PORT_EZMEETING         26261 /* eZmeeting */
#define NETIO_UDP_PORT_K3SOFTWARE_SVR    26262 /* K3 Software-Server */
#define NETIO_UDP_PORT_K3SOFTWARE_CLI    26263 /* K3 Software-Client */
#define NETIO_UDP_PORT_EXOLINE_UDP       26486 /* EXOline-UDP */
#define NETIO_UDP_PORT_EXOCONFIG         26487 /* EXOconfig */
#define NETIO_UDP_PORT_EXONET            26489 /* EXOnet */
#define NETIO_UDP_PORT_IMAGEPUMP         27345 /* ImagePump */
#define NETIO_UDP_PORT_JESMSJC           27442 /* Job controller service */
#define NETIO_UDP_PORT_KOPEK_HTTPHEAD    27504 /* Kopek HTTP Head Port */
#define NETIO_UDP_PORT_ARS_VISTA         27782 /* ARS VISTA Application */
#define NETIO_UDP_PORT_TW_AUTH_KEY       27999 /* Attribute Certificate Services */
#define NETIO_UDP_PORT_NXLMD             28000 /* NX License Manager */
#define NETIO_UDP_PORT_A27_RAN_RAN       28119 /* A27 cdma2000 RAN Management */
#define NETIO_UDP_PORT_VOXELSTORM        28200 /* VoxelStorm game server */
#define NETIO_UDP_PORT_SIEMENSGSM        28240 /* Siemens GSM */
#define NETIO_UDP_PORT_OTMP              29167 /* ObTools Message Protocol */
#define NETIO_UDP_PORT_PAGO_SERVICES1    30001 /* Pago Services 1 */
#define NETIO_UDP_PORT_PAGO_SERVICES2    30002 /* Pago Services 2 */
#define NETIO_UDP_PORT_AMICON_FPSU_RA    30003 /* Amicon FPSU-IP Remote Administration */
#define NETIO_UDP_PORT_AMICON_FPSU_S     30004 /* Amicon FPSU-IP VPN */
#define NETIO_UDP_PORT_KINGDOMSONLINE    30260 /* Kingdoms Online (CraigAvenue) */
#define NETIO_UDP_PORT_SAMSUNG_DISC      30832 /* Samsung Convergence Discovery Protocol */
#define NETIO_UDP_PORT_OVOBS             30999 /* OpenView Service Desk Client */
#define NETIO_UDP_PORT_YAWN              31029 /* YaWN - Yet Another Windows Notifier */
#define NETIO_UDP_PORT_XQOSD             31416 /* XQoS network monitor */
#define NETIO_UDP_PORT_TETRINET          31457 /* TetriNET Protocol */
#define NETIO_UDP_PORT_LM_MON            31620 /* lm mon */
#define NETIO_UDP_PORT_GAMESMITH_PORT    31765 /* GameSmith Port */
#define NETIO_UDP_PORT_ICEEDCP_TX        31948 /* "Embedded Device Configuration Protocol TX */
#define NETIO_UDP_PORT_ICEEDCP_RX        31949 /* "Embedded Device Configuration Protocol RX */
#define NETIO_UDP_PORT_IRACINGHELPER     32034 /* iRacing helper service */
#define NETIO_UDP_PORT_T1DISTPROC60      32249 /* T1 Distributed Processor */
#define NETIO_UDP_PORT_APM_LINK          32483 /* Access Point Manager Link */
#define NETIO_UDP_PORT_SEC_NTB_CLNT      32635 /* SecureNotebook-CLNT */
#define NETIO_UDP_PORT_DMEXPRESS         32636 /* DMExpress */
#define NETIO_UDP_PORT_FILENET_POWSRM    32767 /* FileNet BPM WS-ReliableMessaging Client */
#define NETIO_UDP_PORT_FILENET_TMS       32768 /* Filenet TMS */
#define NETIO_UDP_PORT_FILENET_RPC       32769 /* Filenet RPC */
#define NETIO_UDP_PORT_FILENET_NCH       32770 /* Filenet NCH */
#define NETIO_UDP_PORT_FILENET_RMI       32771 /* FileNet RMI */
#define NETIO_UDP_PORT_FILENET_PA        32772 /* FileNET Process Analyzer */
#define NETIO_UDP_PORT_FILENET_CM        32773 /* FileNET Component Manager */
#define NETIO_UDP_PORT_FILENET_RE        32774 /* FileNET Rules Engine */
#define NETIO_UDP_PORT_FILENET_PCH       32775 /* Performance Clearinghouse */
#define NETIO_UDP_PORT_FILENET_PEIOR     32776 /* FileNET BPM IOR */
#define NETIO_UDP_PORT_FILENET_OBROK     32777 /* FileNet BPM CORBA */
#define NETIO_UDP_PORT_MLSN              32801 /* Multiple Listing Service Network */
#define NETIO_UDP_PORT_IDMGRATM          32896 /* Attachmate ID Manager */
#define NETIO_UDP_PORT_AURORA_BALAENA    33123 /* Aurora (Balaena Ltd) */
#define NETIO_UDP_PORT_DIAMONDPORT       33331 /* DiamondCentral Interface */
#define NETIO_UDP_PORT_SPEEDTRACE_DISC   33334 /* SpeedTrace TraceAgent Discovery */
#define NETIO_UDP_PORT_TRACEROUTE        33434 /* traceroute use */
#define NETIO_UDP_PORT_SNIP_SLAVE        33656 /* SNIP Slave */
#define NETIO_UDP_PORT_TURBONOTE_2       34249 /* TurboNote Relay Server Default Port */
#define NETIO_UDP_PORT_P_NET_LOCAL       34378 /* P-Net on IP local */
#define NETIO_UDP_PORT_P_NET_REMOTE      34379 /* P-Net on IP remote */
#define NETIO_UDP_PORT_PROFINET_RT       34962 /* PROFInet RT Unicast */
#define NETIO_UDP_PORT_PROFINET_RTM      34963 /* PROFInet RT Multicast */
#define NETIO_UDP_PORT_PROFINET_CM       34964 /* PROFInet Context Manager */
#define NETIO_UDP_PORT_ETHERCAT          34980 /* EhterCAT Port */
#define NETIO_UDP_PORT_RT_VIEWER         35001 /* ReadyTech Viewer */
#define NETIO_UDP_PORT_RT_CLASSMANAGER   35004 /* ReadyTech ClassManager */
#define NETIO_UDP_PORT_ALTOVA_LM_DISC    35355 /* Altova License Management Discovery */
#define NETIO_UDP_PORT_ALLPEERS          36001 /* AllPeers Network */
#define NETIO_UDP_PORT_KASTENXPIPE       36865 /* KastenX Pipe */
#define NETIO_UDP_PORT_NECKAR            37475 /* science + computing's Venus Administration Port */
#define NETIO_UDP_PORT_UNISYS_EPORTAL    37654 /* Unisys ClearPath ePortal */
#define NETIO_UDP_PORT_GALAXY7_DATA      38201 /* Galaxy7 Data Tunnel */
#define NETIO_UDP_PORT_FAIRVIEW          38202 /* Fairview Message Service */
#define NETIO_UDP_PORT_AGPOLICY          38203 /* AppGate Policy Server */
#define NETIO_UDP_PORT_TURBONOTE_1       39681 /* TurboNote Default Port */
#define NETIO_UDP_PORT_SAFETYNETP        40000 /* SafetyNET p */
#define NETIO_UDP_PORT_CSCP              40841 /* CSCP */
#define NETIO_UDP_PORT_CSCCREDIR         40842 /* CSCCREDIR */
#define NETIO_UDP_PORT_CSCCFIREWALL      40843 /* CSCCFIREWALL */
#define NETIO_UDP_PORT_ORTEC_DISC        40853 /* ORTEC Service Discovery */
#define NETIO_UDP_PORT_FS_QOS            41111 /* Foursticks QoS Protocol */
#define NETIO_UDP_PORT_CRESTRON_CIP      41794 /* Crestron Control Port */
#define NETIO_UDP_PORT_CRESTRON_CTP      41795 /* Crestron Terminal Port */
#define NETIO_UDP_PORT_CANDP             42508 /* Computer Associates network discovery protocol */
#define NETIO_UDP_PORT_CANDRP            42509 /* CA discovery response */
#define NETIO_UDP_PORT_CAERPC            42510 /* CA eTrust RPC */
#define NETIO_UDP_PORT_RECVR_RC_DISC     43000 /* Receiver Remote Control Discovery */
#define NETIO_UDP_PORT_REACHOUT          43188 /* REACHOUT */
#define NETIO_UDP_PORT_NDM_AGENT_PORT    43189 /* NDM-AGENT-PORT */
#define NETIO_UDP_PORT_IP_PROVISION      43190 /* IP-PROVISION */
#define NETIO_UDP_PORT_SHAPERAI_DISC     43210 /* Shaper Automation Server Management Discovery */
#define NETIO_UDP_PORT_EQ3_CONFIG        43439 /* EQ3 discovery and configuration */
#define NETIO_UDP_PORT_EW_DISC_CMD       43440 /* Cisco EnergyWise Discovery and Command Flooding */
#define NETIO_UDP_PORT_CISCOCSDB         43441 /* Cisco NetMgmt DB Ports */
#define NETIO_UDP_PORT_PMCD              44321 /* PCP server (pmcd) */
#define NETIO_UDP_PORT_PMCDPROXY         44322 /* PCP server (pmcd) proxy */
#define NETIO_UDP_PORT_DOMIQ             44544 /* DOMIQ Building Automation */
#define NETIO_UDP_PORT_RBR_DEBUG         44553 /* REALbasic Remote Debug */
#define NETIO_UDP_PORT_ASIHPI            44600 /* AudioScience HPI */
#define NETIO_UDP_PORT_ETHERNET_IP_2     44818 /* "EtherNet/IP messaging */
#define NETIO_UDP_PORT_M3DA_DISC         44900 /* M3DA Discovery is used for efficient machine-to-machine communications */
#define NETIO_UDP_PORT_ASMP_MON          45000 /* NSi AutoStore Status Monitoring Protocol device monitoring */
#define NETIO_UDP_PORT_INVISION_AG       45054 /* InVision AG */
#define NETIO_UDP_PORT_EBA               45678 /* EBA PRISE */
#define NETIO_UDP_PORT_QDB2SERVICE       45825 /* Qpuncture Data Access Service */
#define NETIO_UDP_PORT_SSR_SERVERMGR     45966 /* SSRServerMgr */
#define NETIO_UDP_PORT_MEDIABOX          46999 /* MediaBox Server */
#define NETIO_UDP_PORT_MBUS              47000 /* Message Bus */
#define NETIO_UDP_PORT_JVL_MACTALK       47100 /* Configuration of motors connected to Industrial Ethernet */
#define NETIO_UDP_PORT_DBBROWSE          47557 /* Databeam Corporation */
#define NETIO_UDP_PORT_DIRECTPLAYSRVR    47624 /* Direct Play Server */
#define NETIO_UDP_PORT_AP                47806 /* ALC Protocol */
#define NETIO_UDP_PORT_BACNET            47808 /* Building Automation and Control Networks */
#define NETIO_UDP_PORT_PRESONUS_UCNET    47809 /* PreSonus Universal Control Network Protocol */
#define NETIO_UDP_PORT_NIMCONTROLLER     48000 /* Nimbus Controller */
#define NETIO_UDP_PORT_NIMSPOOLER        48001 /* Nimbus Spooler */
#define NETIO_UDP_PORT_NIMHUB            48002 /* Nimbus Hub */
#define NETIO_UDP_PORT_NIMGTW            48003 /* Nimbus Gateway */
#define NETIO_UDP_PORT_ISNETSERV         48128 /* Image Systems Network Services */
#define NETIO_UDP_PORT_BLP5              48129 /* Bloomberg locator */
#define NETIO_UDP_PORT_COM_BARDAC_DW     48556 /* com-bardac-dw */
#define NETIO_UDP_PORT_IQOBJECT          48619 /* iqobject */
#define NETIO_UDP_PORT_ROBOTRACONTEUR    48653 /* Robot Raconteur transport */


struct netio_udp
{
	netio_header_t   nudp_header;
	int              nudp_src;
	int              nudp_dest;
	int              nudp_len;
	int              nudp_sum;
};


int netio_udp_init(netio_udp_t *this);


int netio_udp_checksum(const netio_udp_t *this, const netio_ip_t *pseudo,
		       const char *data, size_t size);

int netio_udp_auto_checksum(const netio_udp_t *this);


const char *netio_udp_portalias(int port);


int netio_udp_setsrc(netio_udp_t *this, int src);

int netio_udp_setdest(netio_udp_t *this, int dest);

int netio_udp_setlen(netio_udp_t *this, int len);

int netio_udp_setsum(netio_udp_t *this, int sum);


int netio_udp_getsrc(const netio_udp_t *this);

int netio_udp_getdest(const netio_udp_t *this);

int netio_udp_getlen(const netio_udp_t *this);

int netio_udp_getsum(const netio_udp_t *this);


#endif
