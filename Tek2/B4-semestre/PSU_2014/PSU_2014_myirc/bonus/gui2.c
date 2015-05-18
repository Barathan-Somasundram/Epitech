/*
** main.c for  in /home/somasu_b/rendu/Tek1/PSU_2014_myirc/bonus
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Apr 10 17:10:57 2015 SOMASUNDRAM Barathan
** Last update Sat Apr 11 01:08:06 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "client.h"

int			do_nothing(void)
{
  return (0);
}

int			channel(t_gtk* gui)
{
  if ((gui->channel_box = gtk_vbox_new(FALSE, 5)) == NULL)
    return (1);
  gtk_container_set_border_width(GTK_CONTAINER(gui->channel_box), 5);
  gtk_container_add(GTK_CONTAINER(gui->win_box), gui->channel_box);
  if ((gui->channel = gtk_scrolled_window_new(NULL, NULL)) == NULL)
    return (1);
  gtk_widget_set_usize(gui->channel, 50, 100);
  gtk_container_add(GTK_CONTAINER(gui->channel_box), gui->channel);
  gtk_widget_show(gui->channel);
  if ((gui->listChannel = gtk_list_new()) == NULL)
    return (1);
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(gui->channel),
					gui->listChannel);
  gtk_signal_connect(GTK_OBJECT(gui->listChannel), "selection_changed",
		     GTK_SIGNAL_FUNC(do_nothing), NULL);
  gtk_signal_connect(GTK_OBJECT(gui->listChannel), "button_release_event",
		     GTK_SIGNAL_FUNC(do_nothing), NULL);
  return (0);
}

int			user(t_gtk* gui)
{
  if ((gui->user_box = gtk_vbox_new(FALSE, 5)) == NULL)
    return (1);
  gtk_container_set_border_width(GTK_CONTAINER(gui->user_box), 5);
  gtk_container_add(GTK_CONTAINER(gui->win_box), gui->user_box);
  if ((gui->user = gtk_scrolled_window_new(NULL, NULL)) == NULL)
    return (1);
  gtk_widget_set_usize(gui->user, 50, 100);
  gtk_container_add(GTK_CONTAINER(gui->user_box), gui->user);
  gtk_widget_show(gui->user);
  if ((gui->listUser = gtk_list_new()) == NULL)
    return (1);
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(gui->user),
					gui->listUser);
  gtk_signal_connect(GTK_OBJECT(gui->listUser), "selection_changed",
		     GTK_SIGNAL_FUNC(do_nothing), NULL);
  gtk_signal_connect(GTK_OBJECT(gui->listUser), "button_release_event",
		     GTK_SIGNAL_FUNC(do_nothing), NULL);
  return (0);
}

int			menu(t_gtk* gui)
{
  if ((gui->menu_box = gtk_vbox_new(FALSE, 0)) == NULL)
    return (1);
  gtk_container_add(GTK_CONTAINER(gui->win), gui->menu_box);
  if ((gui->barmenu = gtk_menu_bar_new()) == NULL)
    return (1);
  if ((gui->filemenu = gtk_menu_new()) == NULL)
    return (1);
  if ((gui->file = gtk_menu_item_new_with_label("File")) == NULL)
    return (1);
  if ((gui->quit = gtk_menu_item_new_with_label("Exit")) == NULL)
    return (1);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(gui->file), gui->filemenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(gui->filemenu), gui->quit);
  gtk_menu_shell_append(GTK_MENU_SHELL(gui->barmenu), gui->file);
  gtk_box_pack_start(GTK_BOX(gui->menu_box), gui->barmenu, FALSE, FALSE, 3);
  g_signal_connect(G_OBJECT(gui->quit), "activate",
		   G_CALLBACK(gtk_main_quit), NULL);
  return (0);
}
