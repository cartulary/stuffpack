# New ports collection makefile for:	ttt
# Date created:				11 July 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD: ports/games/ttt/Makefile,v 1.6 2008/03/13 14:28:09 miwi Exp $
#

PORTNAME=		ttt-text
PORTVERSION=	0.3
CATEGORIES=		games
MASTER_SITES=	http://stuffpack.googlecode.com/files/

MAINTAINER=	EitanAdlerList@gmail.com
COMMENT=	Simple one player command line Tic Tac Toe game

.include <bsd.port.pre.mk>
do-install:
# Program.
	${INSTALL_PROGRAM} ${WRKSRC}/$(PORTNAME) ${PREFIX}/bin
.include <bsd.port.post.mk>
