/*
** simple_btree.c for simple_btree in /home/somasu_b/rendu/piscine_cpp_d02a/ex01
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 23:44:53 2015 SOMASUNDRAM Barathan
** Last update Fri Jan  9 09:46:01 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include "simple_btree.h"

t_bool	btree_is_empty(t_tree tree)
{
  if (tree == NULL)
    return (TRUE);
  return (FALSE);
}

unsigned int	btree_get_size(t_tree tree)
{
  t_tree	tmp = tree;
  unsigned int	size = 0;

  if (tree)
    size = size + 1 + btree_get_size(tmp->right)
      + btree_get_size(tmp->left);
  return (size);
}

unsigned int	btree_get_depth(t_tree tree)
{
  unsigned int	depthr = 0;
  unsigned int	depthl = 0;

  if (tree == NULL)
    return (0);
  depthr = depthr + 1 + btree_get_depth(tree->right);
  depthl = depthl + 1 + btree_get_depth(tree->left);
  return ((depthr > depthl ? depthr : depthl));
}

t_bool	btree_create_node(t_tree *root_ptr, double value)
{
  t_tree	new = NULL;
  
  if ((new = malloc(sizeof(*new))) == NULL)
    return (FALSE);
  new->value = value;
  new->right = NULL;
  new->left = NULL;
  *root_ptr = new;
  return (TRUE);
}

t_bool	btree_delete(t_tree *root_ptr)
{
  t_tree	tmpr = NULL;
  t_tree	tmpl = NULL;

  if (*root_ptr == NULL)
    return (FALSE);
  free(*root_ptr);
  tmpr = (*root_ptr)->right;
  if (tmpr != NULL)
    return (btree_delete(&tmpr));
  tmpl = (*root_ptr)->left;
  if (tmpl != NULL)
    return (btree_delete(&tmpl));
  return (TRUE);
}

double	btree_get_max_value(t_tree tree)
{
  double	maxr = 0;
  double	maxl = 0;

  if (tree == NULL)
    return (0);
  if (tree->right != NULL)
    maxr = btree_get_max_value(tree->right);
  if (tree->left != NULL)
    maxl = btree_get_max_value(tree->left);
  return ((maxr > tree->value ? maxr : tree->value) > maxl ?
	  (maxr > tree->value ? maxr : tree->value) : maxl);
}

double	btree_get_min_value(t_tree tree)
{
  double	minr = 0;
  double	minl = 0;
  double	min;

  if (tree == NULL)
    return (0);
  min = tree->value;
  if (tree->right != NULL)
    {
      minr = btree_get_min_value(tree->right);
      if (minr < min)
	min = minr;
    }
  if (tree->left != NULL)
    {
      minl = btree_get_min_value(tree->left);
      if (minl < min)
	min = minl;
    }
  return (min);
}
