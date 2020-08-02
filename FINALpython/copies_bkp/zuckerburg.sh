curl 'http://domain.com/id/[1-151468]' -o '#1.html'

grep -oh 'http://pics.domain.com/pics/original/.*jpg' *.html >urls.txt

sort -u urls.txt | wget -i-

