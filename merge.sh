
if [ "$#" -ne 2 ]; then
	echo "Need to have 2 parameters"
	exit 0
fi

git remote add -f $2 $1
git merge "$2/master" --allow-unrelated-histories
mkdir $2
git mv ex* $2
git mv .gitignore $2
git commit -m "Moved $2 files into subdir"
