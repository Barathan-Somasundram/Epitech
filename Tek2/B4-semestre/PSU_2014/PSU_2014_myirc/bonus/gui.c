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

int			dialog_refresh(t_gtk* gui, char* str)
{
  GtkTextBuffer*	text_buffer;
  GtkTextIter		end;

  text_buffer = 0;
  if ((text_buffer = gtk_text_view_get_buffer
       (GTK_TEXT_VIEW(gui->text_view))) == NULL)
    return (1);
  gtk_text_buffer_get_end_iter(text_buffer, &end);
  gtk_text_buffer_insert(text_buffer, &end,
			 g_locale_to_utf8(str, -1, NULL, NULL, NULL), -1);
  gtk_widget_show_all(gui->win);
  return (0);
}

int			get_text(GtkWidget* ign, t_gtk* gui)
{
  const gchar*		buffer;

  (void)ign;
  if ((buffer = gtk_entry_get_text(GTK_ENTRY(gui->entry))) == NULL)
    return (1);
  strcat((char*)buffer, "\n");
  printf("%s", buffer);
  gtk_entry_set_text(GTK_ENTRY(gui->entry) , "");
  if (dialog_refresh(gui, (char*)buffer) == 1)
    return (1);
  return (0);
}

int			dialog(t_gtk* gui)
{
  if ((gui->dialog_box = gtk_vbox_new(FALSE, 5)) == NULL)
    return (1);
  if ((gui->entry = gtk_entry_new()) == NULL)
    return (1);
  if ((gui->show = gtk_scrolled_window_new(NULL, NULL)) == NULL)
    return (1);
  if ((gui->text_view = gtk_text_view_new()) == NULL)
    return (1);
  gtk_container_add(GTK_CONTAINER(gui->win_box), gui->dialog_box);
  gtk_box_pack_start(GTK_BOX(gui->dialog_box), gui->show, TRUE, TRUE, 10);
  gtk_box_pack_end(GTK_BOX(gui->dialog_box), gui->entry, FALSE, TRUE, 0);
  gtk_text_view_set_editable(GTK_TEXT_VIEW(gui->text_view), FALSE);
  gtk_scrolled_window_add_with_viewport
    (GTK_SCROLLED_WINDOW(gui->show), gui->text_view);
  g_signal_connect(G_OBJECT(gui->entry) , "activate",
		   G_CALLBACK(get_text), (gui));
  return (0);
}

int			gui_make(t_gtk* gui)
{
  if ((gui->win = gtk_window_new(GTK_WINDOW_TOPLEVEL)) == NULL)
    return (1);
  gtk_window_set_title(GTK_WINDOW(gui->win), "my_irc");
  gtk_signal_connect(GTK_OBJECT(gui->win), "delete_event",
		     (GtkSignalFunc) gtk_exit, NULL);
  gtk_window_set_default_size(GTK_WINDOW(gui->win), WIDTH, HEIGHT);
  gtk_window_set_position(GTK_WINDOW(gui->win), GTK_WIN_POS_CENTER);
  if (menu(gui) == 1)
    return (1);
  if ((gui->win_box = gtk_hbox_new(FALSE, 5)) == NULL)
    return (1);
  gtk_container_add(GTK_CONTAINER(gui->menu_box), gui->win_box);
  if (channel(gui) == 1)
    return (1);
  gtk_box_pack_start(GTK_BOX(gui->win_box), gui->channel_box, TRUE, FALSE, 10);
  if (dialog(gui) == 1)
    return (1);
  gtk_box_pack_start(GTK_BOX(gui->win_box), gui->dialog_box, TRUE, FALSE, 10);
  if (user(gui) == 1)
    return (1);
  gtk_box_pack_start(GTK_BOX(gui->win_box), gui->user_box, TRUE, FALSE, 10);
  gtk_widget_show_all(gui->win);
  return (0);
}
