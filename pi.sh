sudo apt-get update
sudo apt-get install ssh xclip
mkdir -p $HOME/.ssh
chmod 0700 $HOME/.ssh
ssh-keygen -t rsa
cat $HOME/.ssh/id_rsa.pub | xclip -i -selection clipboard
cat >> $HOME/.ssh/config << EOF
Host raspberrypi
Hostname 90.127.204.41
Port 60022
User pi
EOF
