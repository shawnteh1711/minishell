# Github Flow
1. my github repo is the "canonical" version. David forks from it. 
2. instead of committing to the master branch, we worked on the development branch.

So when David tries to contribute his code, we will be doing these:
you (David) do the following:
1. git checkout development   ---   This moves you to your local development branch.
2. git pull <my_repo_name>   ---   This pulls any changes to the development branch at my github repo to your local repo.
3. git merge <working_branch>   ---   You are trying to merge the changes that's in the working_branch to your local development branch.
4. You might see some conflicts. Resolve them.  (You may want to check online on how you do this)
5. Once merged, you will see that your development branch is one step ahead of your working_branch.
6. do a git push to your repository.   ---   This is to update your github repository with the changes. 

then I (Hean) will:
1. git checkout development   ---   This moves me to my local development branch.
2. git pull <your_repo_name>   ---   This pulls any changes from your github repo development branch to my local repo. 

![github flow](images/github.png)
