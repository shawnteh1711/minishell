# Github Flow
1. my github repo is the "canonical" version. Ansomn forks from it. 
2. instead of committing to the master branch, we worked on the development branch.

So when Ansomn tries to contribute his code, we will be doing these:
you (Ansomn) do the following:
1. git checkout development   ---   This moves you to your local development branch.
2. git pull <my_repo_name>   ---   This pulls any changes to the development branch at my github repo to your local repo.
3. git merge <working_branch>   ---   You are trying to merge the changes that's in the working_branch to your local development branch.
4. You might see some conflicts. Resolve them.  (You may want to check online on how you do this)
5. Once merged, you will see that your development branch is one step ahead of your working_branch.
6. do a git push to your repository.   ---   This is to update your github repository with the changes. 

then I (Shawn) will:
1. git checkout development   ---   This moves me to my local development branch.
2. git pull <your_repo_name>   ---   This pulls any changes from your github repo development branch to my local repo. 


<!-- $ cd PROJECT_NAME
$ git remote add upstream https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY.git
$ git fetch upstream

# then: (like "git pull" which is fetch + merge)
$ git merge upstream/master master

# or, better, replay your local work on top of the fetched branch
# like a "git pull --rebase"
$ git rebase upstream/master -->
![github flow](images/github.png)
