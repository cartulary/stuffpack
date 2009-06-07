# New ports collection makefile for:   symlink
# Date created:        Fri Jun 05 2009
# Whom:                Eitan Adler <EitanAdlerList@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	symlink
PORTVERSION=	4
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://isis.poly.edu/~eitan/files/
DISTNAME=	auto-symlink-virtual-${PORTVERSION}.sh
EXTRACT_SUFX=

MAINTAINER=	EitanAdlerList@gmail.com
COMMENT=	Automatically generate symlinks for virtual categories

NO_BUILD=	yes
EXTRACT_ONLY=	# nada

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
