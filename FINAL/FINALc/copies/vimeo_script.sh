#!/bin/sh
    
#block 1
#
#
if [ $# -ne 1 ]; then
exit 1
fi
ID=`echo $1 | awk -F / '{print $NF}'`

# Set the user agent ID to use
USER_AGENT="Mozilla/5.0"

# Check we have the tools we need
which wget
if [ $? -eq 1 ]; then
echo "ERROR: this tool requires wget on the path"
exit 1
fi

which perl
if [ $? -eq 1 ]; then
echo "ERROR: this tool requires perl on the path"
exit 1
fi

#block 2
#
#
VIDEO_XML=`wget -U \"${USER_AGENT}\" -q -O - http://vimeo.com/${ID}`

CONFIG_URL=`echo $VIDEO_XML | grep data-config-url | perl -p -e 's/^.*? data-config-url="(.*?)".*$/$1/g' | perl -pe 's/&amp;/&/g'`
VIDEO_CONFIG=`wget -U \"${USER_AGENT}\" -q -O - ${CONFIG_URL}`

#block 3
#
#
HD_URL=`echo $VIDEO_CONFIG | perl -pe 's/^.*"hd":{(.*?)}.*$/$1/g' | perl -pe 's/^.*"url":"(.*?)".*$/$1/g'`
SD_URL=`echo $VIDEO_CONFIG | perl -pe 's/^.*"sd":{(.*?)}.*$/$1/g' | perl -pe 's/^.*"url":"(.*?)".*$/$1/g'`
CAPTION=`echo $VIDEO_XML | perl -p -e '/^.*?\<meta property="og:title" content="(.*?)"\>.*$/; $_=$1; s/[^\w.]/-/g;'`


#block 4
#
#
if [ "$HD_URL" ]; then
DOWNLOAD_URL=$HD_URL
QUALITY="HD"
elif [ "$SD_URL" ]; then
DOWNLOAD_URL=$SD_URL
QUALITY="SD"
else
echo "ERROR: failed to download vimeo ID ${ID}"
echo "Please report this error at https://github.com/johnteslade/vimeo-downloader/issues"
fi

#block 5
#
#
FILENAME="${CAPTION}-(${QUALITY}-${ID}).flv"
wget -U \"${USER_AGENT}\" -O ${FILENAME} ${DOWNLOAD_URL}

