#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_URL_LENGTH 100

 struct tnode { /* the tree node: */
   char *key; /* points to the url string */
   int count; /* number of occurrences */
   struct tnode *left; /* left child */
   struct tnode *right; /* right child */
 };


 /* add_to_tree:  add a node with url, at or below p 
  * p: pointer to the root of the (sub)tree where you must add a value
  * url: the URL to be added
  */
 struct tnode* add_to_tree(struct tnode* p, char* url)
 {
	 if (p == NULL) {
			 p = malloc(sizeof(struct tnode));
			 p->count = 1;
			 p->key = (char*)malloc(sizeof(char) *MAX_URL_LENGTH);
			 p->left = NULL;
			 p->right = NULL;
			 strcpy(p->key, url);
			 return p;
		 }		 
	 if (strcmp(url, p->key) == 0) {
		 p->count++;
		 return p;
	 } 
	 if (strcmp(url, p->key) < 0) {
		 p->left = add_to_tree(p->left, url);
		 return p;
	 }
	 else if (strcmp(url, p->key) > 0)
		 p->right = add_to_tree(p->right, url);
	 return p;
 }
	
		 // create a for loop that checks down the tree for a node with the same URL, if none exists, add a new node, if one does exist, then increment the count



 /* populate_tree: repeatedly call add_to_tree on urls from a file 
  * url_file: name of file to read URLs from
  * R: pointer to the root pointer of the tree
  */
 void populate_tree(char *url_file, struct tnode** R)
 {
	 FILE *fp;
	 fp = fopen(url_file, "r");
	 if (fp == NULL)
	 {
		 printf("Can't open %s\n", url_file);
		 exit(EXIT_FAILURE);
	 }
	 char s[MAX_URL_LENGTH];
	 while (feof(fp) == 0) {
		fgets(s, MAX_URL_LENGTH, fp);
		if(feof(fp)) { break; }
		for (int i = 0; i < MAX_URL_LENGTH; i++) {
			if (s[i] == '\n')
				s[i] = '\0';
		}

		 *R = add_to_tree(*R, s);
	 }
 }





 /* lookup:  look up a url in the tree rooted at p, return the frequency of that url
  * p: pointer to the root of the (sub)tree
  * url: url to look for
  */
 int lookup(struct tnode* p, char* url) // Return the frequency of the url
 {

	 if (strcmp(url, p->key) == 0)
		 return p->count;
	 if (strcmp(url, p->key) < 0)
		 return lookup(p->left, url);
	 else if (strcmp(url, p->key) > 0)
		 return lookup(p->right, url);

 }


 /* treeprint:  in-order print of tree p
  * Set the urls in the passed in array in alphabetical fashion. Also set their respective frequencies in a second int array.
  * Return the number of elements set
  * size: how many elements you have currently inserted into the array(s)
  * p: pointer to the root of the (sub)tree
  * URL_array: array to store URLs in
  * n: integer array to store frequencies in
  */ 
int treeprint(int size, struct tnode* p, char URL_array[][MAX_URL_LENGTH], int *n)
{
	if (p->left != NULL)
		size = treeprint(size, p->left, URL_array, n);
	if (size < 10) {
		strcpy(URL_array[size], p->key);
		n[size] = p->count;
		size++;
	}
	if (p->right != NULL)
		size = treeprint(size, p->right, URL_array, n);
	if (size > 9)
		return 10;
	return size;
}

