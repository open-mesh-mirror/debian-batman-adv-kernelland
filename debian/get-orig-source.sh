#! /bin/sh
set -e

REV="`dpkg-parsechangelog|grep '^Version: '|sed 's/^Version:\s*\([0-9]*:\)\?\(.*\)-[0-9]*/\2/'`"
GITREV="`echo v${REV}|grep "[~+]g"|sed 's/[~+]/-/g'`"
DIR="`dpkg-parsechangelog|grep '^Source: '|sed 's/^Source:\s*//'`"
TARNAME="${DIR}_${REV}.orig.tar.gz"
UPSTREAM="`echo ${DIR}|sed 's/\-kernelland$//'`"
SNAPSHOT="http://git.open-mesh.org/?p=${UPSTREAM}.git;a=snapshot;h=${GITREV};sf=tgz"

# try to download source package
if [ ! -s "${TARNAME}" ]; then
	if [ -z "${GITREV}" ]; then
		uscan --verbose --force-download --download-version "${REV}" --destdir ..
	else
		TMPGZ="`mktemp -t`"
		TMPTAR="`mktemp -t`"
		wget -q "${SNAPSHOT}" -O "${TMPGZ}"
		zcat "${TMPGZ}" > "${TMPTAR}"
		rm -f "${TMPGZ}"
		gzip -n -m -f -c "${TMPTAR}" > "../${TARNAME}"
		rm -f "${TMPTAR}"
	fi
fi
