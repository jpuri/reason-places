git subtree split --prefix public -b gh-pages
rm .gitignore
git push -f origin gh-pages:gh-pages
git checkout .
git branch -D gh-pages
