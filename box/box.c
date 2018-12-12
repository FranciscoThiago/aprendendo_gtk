#include <gtk/gtk.h>
   
void init_app(GtkApplication *app,gpointer data);
void cadastro(GtkWidget *button,gpointer app);
int main(int argc,char **argv)
{
    GtkApplication *app = gtk_application_new("com.aprendendo_gtk.box",G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app,"activate",G_CALLBACK(init_app),NULL);

    int status;
    
    status = g_application_run(G_APPLICATION(app),argc,argv);

    g_object_unref(app);

    return status;
}

void init_app(GtkApplication *app,gpointer data)
{
    GtkWidget *window = gtk_application_window_new(app);
	
	gtk_window_set_default_size (GTK_WINDOW(window),600,100);
	gtk_window_set_title (GTK_WINDOW(window),"GUI");
    
	GtkWidget *botao1,*botao2,*entry1,*entry2,*label1,*label2,*box,*box2,*box3,*box4;

	
    box = gtk_box_new(1,0);
	box2 = gtk_box_new(1,0);
	box3= gtk_box_new(1,0);
	box4= gtk_box_new(0,0);

    botao1 = gtk_button_new_with_label("Entrar");
    botao2 = gtk_button_new_with_label("Cadastrar");

    label1 = gtk_label_new("E-mail");
    label2 = gtk_label_new("Senha");

    entry1 = gtk_entry_new();
    entry2 = gtk_entry_new();
    
	/*
	 * Expand: Espaço extra vai ser alocado, ou seja
	 * todo o espço extra no container vai ser dividido entre os elementos com esse
	 * opção
	 * 
	 * exemplo: 5 elemetos sem spacing cada um com 25px em um container de 800px
	 * 
	 *os dois primeiros não possuim o expand, seus tamanhos serão alocados normalmente
	 *os outros 3 possuim, então seu espaço serão divididos nos 750 (800 - 2*25) restantes
	 * Fill: Preenche seu espaço
	 * Spacing: Espaço entre os elementos
	 */ 
	 
	gtk_box_pack_start(GTK_BOX(box2),label1,0,0,10);
	gtk_box_pack_start(GTK_BOX(box2),entry1,0,0,10);
	
	gtk_box_pack_start(GTK_BOX(box3),label2,0,0,10);
	gtk_box_pack_start(GTK_BOX(box3),entry2,0,0,10);
	

	gtk_box_pack_start(GTK_BOX(box4),botao1,1,1,1);
	gtk_box_pack_start(GTK_BOX(box4),botao2,1,1,1);
	
	
	gtk_box_pack_start(GTK_BOX(box),box2,1,0,50);
	gtk_box_pack_start(GTK_BOX(box),box3,1,0,50);
	gtk_box_pack_end(GTK_BOX(box),box4,0,0,30);
	
	g_signal_connect(botao2,"clicked",G_CALLBACK(cadastro),app);
	
	
	gtk_container_add(GTK_CONTAINER(window),box);
	gtk_widget_show_all(window);
      
}

void cadastro(GtkWidget *button,gpointer app)
{
	GtkWidget *window = gtk_application_window_new(app);
	gtk_window_set_default_size (GTK_WINDOW(window),600,100);
	gtk_window_set_title (GTK_WINDOW(window),"Cadastro");
	gtk_window_set_resizable(GTK_WINDOW(window),0);
	
	GtkWidget *label1,*label2,*entry1,*entry2,*botao1,*box1,*box2,*box;
	
	box = gtk_box_new(1,0);
	box1 = gtk_box_new(0,0);
	box2 = gtk_box_new(0,0);
	
	label1 = gtk_label_new("Email: ");
	label2 = gtk_label_new("Senha: ");
	
	entry1 = gtk_entry_new();
	entry2 = gtk_entry_new();
	
	botao1 = gtk_button_new_with_label("Cadastrar");
	
	gtk_box_pack_start(GTK_BOX(box1),label1,0,0,1);
	gtk_box_pack_start(GTK_BOX(box1),entry1,1,1,1);
	
	gtk_box_pack_start(GTK_BOX(box2),label2,0,0,1);
	gtk_box_pack_start(GTK_BOX(box2),entry2,1,1,1);
	
	gtk_box_pack_start(GTK_BOX(box),box1,1,0,1);
	gtk_box_pack_start(GTK_BOX(box),box2,1,0,1);
	gtk_box_pack_end(GTK_BOX(box),botao1,0,0,1);
	
	gtk_container_add(GTK_CONTAINER(window),box);
	
	gtk_widget_show_all(window);
	
}