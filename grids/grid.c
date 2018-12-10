#include <gtk/gtk.h>

void init_app(GtkApplication *app,gpointer *data);

int main(int argc, char **argv)
{
	GtkApplication *app = gtk_application_new("com.aprendendo_gtk.grids",G_APPLICATION_FLAGS_NONE);
	
	int status;
	
	g_signal_connect(app,"activate",G_CALLBACK(init_app),NULL);
	
	status = g_application_run(G_APPLICATION(app),argc,argv);
	
	g_object_unref(app);
	
	return status;	
}

void init_app(GtkApplication *app,gpointer *data)
{
	GtkWidget *window = gtk_application_window_new(app);
	
	GtkWidget *b1,*b2,*b3,*grid;
	
	grid = gtk_grid_new();
	
	gtk_container_add(GTK_CONTAINER(window),grid);
	
	b1 = gtk_button_new_with_label("Botão 1");
	b2 = gtk_button_new_with_label("Botão 2");
	b3 = gtk_button_new_with_label("Botão 3");
	
	gtk_grid_attach(GTK_GRID(grid),b1,0,0,2,1);
	gtk_grid_attach(GTK_GRID(grid),b2,0,1,1,1);
	gtk_grid_attach(GTK_GRID(grid),b3,1,1,1,1);
	
	gtk_widget_show_all(window);
	
}