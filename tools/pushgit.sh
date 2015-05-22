
git init
fossil export --git | git fast-import
echo GitHub:
git remote add origin https://github.com/ksshannon/rot
git push -f origin trunk lcov c89
git remote rm origin
echo GitLab:
git remote add origin https://gitlab.com/ksshannon/rot.git
git push -f origin trunk lcov c89
git remote rm origin
echo BitBucket:
git remote add origin https://bitbucket.org/ksshannon/rot
git push -f origin trunk lcov c89
git remote rm origin
rm -rf .git/

