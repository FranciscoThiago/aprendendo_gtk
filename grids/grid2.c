#include <gtk/gtk.h>

void init_app(GtkApplication *app,gpointer data);
void click(GtkWidget *button,gpointer data);
void click2(GtkWidget *button,gpointer data);

int main(int argc,char **argv)
{
	int status;
	GtkApplication *app = gtk_application_new("com.aprendendo_gtk.grid2",G_APPLICATION_FLAGS_NONE);
	
	
	g_signal_connect(app,"activate",G_CALLBACK(init_app),NULL);
	
	status = g_application_run(G_APPLICATION(app),argc,argv);
	
	g_object_unref(app);
	
	return status;
}

void init_app(GtkApplication *app,gpointer data)
{
	GtkWidget *window = gtk_application_window_new(app);
	GtkWidget *b1,*b2,*entry,*grid;
	
	grid = gtk_grid_new();
	
	gtk_container_add(GTK_CONTAINER(window),grid);
	
	entry = gtk_entry_new();
	
	b1 = gtk_button_new_with_label("Apagar");
	b2 = gtk_button_new_with_label("print");
	
	gtk_grid_attach(GTK_GRID(grid),entry,0,0,2,1);
	gtk_grid_attach(GTK_GRID(grid),b1,0,1,1,1);
	gtk_grid_attach(GTK_GRID(grid),b2,1,1,1,1);
	
	
	g_signal_connect(b1,"clicked",G_CALLBACK(click),entry);
	g_signal_connect(b2,"clicked",G_CALLBACK(click2),entry);
	gtk_widget_show_all(window);
}

void click(GtkWidget *button,gpointer data)
{
	gtk_entry_set_text(GTK_ENTRY(data)," ");
}

void click2(GtkWidget *button,gpointer data)
{
	char *a = (char *)gtk_entry_get_text(GTK_ENTRY(data));
	g_print("%s",a);
}
