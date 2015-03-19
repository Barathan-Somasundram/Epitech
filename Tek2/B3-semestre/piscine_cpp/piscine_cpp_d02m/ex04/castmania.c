/*
** castmania.c for castmania in /home/somasu_b/rendu/piscine_cpp_d02m/ex04
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 14:42:58 2015 SOMASUNDRAM Barathan
** Last update Thu Jan  8 18:08:04 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "castmania.h"

void	exec_operation(t_instruction_type instruction_type, void *data)
{

  if (instruction_type == ADD_OPERATION)
    exec_add((t_add*)((t_instruction*)data)->operation);
  else if (instruction_type == DIV_OPERATION)
    exec_div((t_div*)((t_instruction*)data)->operation);
  if (((t_instruction*)data)->output_type == VERBOSE)
    {
      if (instruction_type == ADD_OPERATION)
	printf("%d\n", ((t_add*)(((t_instruction*)data)->operation))->add_op.res);
      else if (instruction_type == DIV_OPERATION)
	{
	  if (((t_div*)((t_instruction*)data)->operation)->div_type == INTEGER)
	    printf("%d\n", ((t_integer_op*)((t_div*)((t_instruction*)data)->operation)->div_op)->res);
	  else if (((t_div*)((t_instruction*)data)->operation)->div_type == DECIMALE)
	    printf("%f\n", ((t_decimale_op*)((t_div*)((t_instruction*)data)->operation)->div_op)->res);
	}
    }
}

void	exec_instruction(t_instruction_type instruction_type, void *data)
{
  if (instruction_type == PRINT_INT)
    printf("%d\n", *((int*)(data)));
  else if (instruction_type == PRINT_FLOAT)
    printf("%f\n", *((float*)(data)));
  else
    exec_operation(instruction_type, data);
}
