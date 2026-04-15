#include <stdio.h>
#define MAXNUM_VERTICES 100

/*
Struktur data untuk merepresentasikan sebuah graf dengan
menggunakan adjacency matrix.
Graph akan memiliki sebanyak n_vertices simpul dan n_edges sisi.
Kita mengasumsikan bahwa graph akan memiliki maksimal hanya MAXNUM_VERTICES simpul.
*/

typedef struct
{
    int n_vertices;
    int n_edges;
    int adjacency_matrix[MAXNUM_VERTICES][MAXNUM_VERTICES];
} Graph;


/*
Fungsi untuk menginisialisasi adjacency matrix graph dg cara mengisi
sub-matrix kiri atas dg ukuran n_vertices x n_vertices dari adjacency matrix
dg nilai 0, sedangkan sisanya (yang tidak relevan untuk tujuan representasi graph dg jumlah vertex sebanyak n_vertices) akan diisi dg nilai -1.
*/

void inisialisasi_graph (Graph *g, int n_v, int n_e)
{
    int i,j;

    g->n_vertices = n_v;
    g->n_edges = n_e;

    for(i = 0; i < MAXNUM_VERTICES; i++)
    {
        for(j=0; j < MAXNUM_VERTICES; j++)
        {
            if(i < n_v && j < n_v)
            /* Soal no. 1: lengkapi untuk menyimpan nilai 0 pada sub-matrix kiri-atas dari adjacency matrix*/ 
            else
            /* Soal no. 2: lengkapi untuk menyimpan nilai -1 pada elemen-elemen sisanya */
        }
    }
}

/*
Fungsi untuk mencetak adjacency matrix dari sebuah graph g
*/
void print_adjacency_matrix(Graph *g)
{
    int i,j;
    for(i = 0; i < g->n_vertices; i++)
        printf("\t%d", i);
    printf("\n");
    
    for(i = 0; i < g->n_vertices; i++)
    {
        printf("%d", i);
        for(j = 0; j < g->n_vertices; j++)
        {
            printf("\t%d", g->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

/*
catatan:
compile bisa lewat vscode
jalankan "adjacency < input.txt" lewat cmd, bukan powershell atau terminal vscode
*/

int main()
{
    int n_v = 0;
    int n_e = 0;
    int i,j;
    scanf("%d %d", &n_v, &n_e);

    Graph g;
    inisialisasi_graph (&g, n_v, n_e);

    for(i = 0; i < n_e; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        /* Soal 3 lengkapi agar adjacency matrix pada g menyimpan nilai 1 pada baris a kolom b */
    }
    print_adjacency_matrix(&g);
return 0;
}