clear
echo "#############################################"
echo "#            dewitcher Framework            #"
echo "#               Commit Script               #"
echo "#############################################"
echo "#        Copyright(C) dewitcher Team        #"
echo "#############################################"
echo "#              Imardin VM rocks              "
echo "#############################################"
echo "#         Press any key to continue         #"
read

clear
echo "#############################################"
echo "#          Initializing Repository          #"
echo "#############################################"
git init

clear
echo "#############################################"
echo "# DONE Initializing Repository              #"
echo "#############################################"
echo "#            Merging contents...            #"
echo "#############################################"
git pull

clear
echo "#############################################"
echo "# DONE Initializing Repository              #"
echo "# DONE Merging contents                     #"
echo "#############################################"
echo "#             Adding content...             #"
echo "#############################################"
git add .

clear
echo "#############################################"
echo "# DONE Initializing Repository              #"
echo "# DONE Merging contents                     #"
echo "# DONE Adding content                       #"
echo "#############################################"
echo "#            Cleaning Repository            #"
echo "#############################################"
# nothing to do
# please use clean.sh

clear
echo "#############################################"
echo "# DONE Initializing Repository              #"
echo "# DONE Merging contents                     #"
echo "# DONE Adding content                       #"
echo "# DONE Cleaning Repository                  #"
echo "#############################################"
echo "#   Please type a message for this commit   #"
echo "#############################################"
git commit -a

clear
echo.
echo "#############################################"
echo "#                   Done!                   #"
echo "#############################################"
echo "#       Please run SimplePush.sh now!       #"
echo "#############################################"
read

# End of Script
