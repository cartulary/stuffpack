# New ports collection makefile for:   symlink
# Date created:        Fri Jun 05 2009
# Whom:                Eitan Adler <EitanAdlerList@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	symlink
PORTVERSION=	2
CATEGORIES= ports-mgmt
MASTER_SITES=	http://isis.poly.edu/~eitan/files/
DISTFILES=auto-symlink-virtual-$(PORTVERSION).sh

MAINTAINER=	EitanAdlerList@gmail.com
COMMENT=	Automatically generate symlinks for virtual categories.

NO_BUILD=	yes
NO_EXTRACT=	yes
EXTRACT_CMD=true

PLIST_FILES=bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTFILES} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
