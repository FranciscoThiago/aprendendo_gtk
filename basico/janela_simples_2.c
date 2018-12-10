#include <gtk/gtk.h>

/*
 * Dica funções referentes a vaiveis começam com gtk, já as outras funções e macros começam com g
 */
 
void janela_init(GtkApplication *app,gpointer data);
void clicado(GtkWidget *botao,gpointer data);
int main(int argc,char **argv)
{
	int status;
	GtkApplication *app = gtk_application_new("com.aprendendo_gtk.janela_simple_2",G_APPLICATION_FLAGS_NONE);
	
	g_signal_connect(app,"activate",G_CALLBACK(janela_init),NULL);
	
	status = g_application_run(G_APPLICATION(app),argc,argv);
	
	g_object_unref(app);
}

/*Dica: A maioria das funções que envolvem objetos no Gtk
 * necessitan de um macro, do seu memo tipo
 * 
 * exemplo: A função que envolvem window necessita do macro GTK_WINDOW
 * 			As que envolvem containers exigem GTK_CONTAINER
 */
void janela_init(GtkApplication *app,gpointer data)
{
	GtkWidget *janela = gtk_application_window_new(app);
	
	gtk_window_set_title(GTK_WINDOW(janela),"Janela 2");
	
	GtkWidget *botao = gtk_button_new_with_label("Click Me");
	
	g_signal_connect(botao,"clicked",G_CALLBACK(clicado),NULL);
	
	gtk_container_add(GTK_CONTAINER(janela),botao);
	gtk_widget_show_all(janela);
}

void clicado(GtkWidget *botao,gpointer data)
{
	g_print("Clicado\n");
}

