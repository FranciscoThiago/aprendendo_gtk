#include <gtk/gtk.h>


void init_janela(GtkApplication *app, gpointer data);

//argc e argv sempre devem ser passados como parametro
int main(int argc,char **argv )
{
	/*
	 * Aplicativo gtk. Necessita de um endereço como paramentro
	 * deve ser único para não ser confundido com outros programas
	 */
	GtkApplication *app = gtk_application_new("com.aprendendo_gtk.janela_simple",G_APPLICATION_FLAGS_NONE);
	
	/*
	 *Conecta o sinal "activate" ao app, chamando a função init_janela 
	 */
	g_signal_connect(app,"activate",G_CALLBACK(init_janela),NULL);
	
	// recebe o resultado da execução
	
	int status;
	
	status = g_application_run(G_APPLICATION(app),argc,argv);
	
	//desaloca o app
	
	g_object_unref(app);
	
	return status;
	
}

//O parametro app vai receber o app passado na função siganl connect da linha 18, o paramentro data recebera NULL
void init_janela(GtkApplication *app, gpointer data)
{
	//Cria a janela do app
	GtkWidget *janela;
	janela = gtk_application_window_new(app);
	
	//Mostra a janelas
	gtk_widget_show_all(janela);
}
