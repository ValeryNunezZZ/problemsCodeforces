fun mostrarCanciones(topCanciones: List<List<String>>) {
    for (i in 1..topCanciones.size) {
        val nombreCancion = topCanciones.get(i - 1).get(1)
        val nombreArtista = topCanciones.get(i - 1).get(2)
        val views = topCanciones.get(i - 1).get(3)
        
        println("$i $nombreCancion : nombreArtista($views)")
    }
}

fun playlistUno() : List<List<String>> {
    val canciones: List<List<String>> = listOf(
        listOf("1", "Aca entre nos", "Vicente Fernandez", "1"),
        listOf("2", "Shape Of You", "Ed Sheeran", "5.10")
    )
    return canciones
}

fun playlistDos() : List<List<String>> {
    val canciones: List<List<String>> = listOf(
        listOf("1", "Starboy", "The Weeknd ft. Daft Punk", "4.76"),
        listOf("2", "As It Was", "Harry Styles", "4.62")
    )
    return canciones
}

fun playlistTres() : List<List<String>> {
    val canciones: List<List<String>> = listOf(
        listOf("1", "Treasure", "Bruno Mars", "10"),
        listOf("2", "Uptown Funk", "Bruno Mars", "50"),
        listOf("3", "As It Was", "Harry Styles", "4.62")
    )
    return canciones
}

fun revolver(lista : List<List<String>>){
    
    val res = lista.shuffled()
    
    println("\nTOP CANCIONES MUNDIALES (REVUELTAS)\n")
    mostrarCanciones(res);
}

fun eliminarRepetidos(p1: MutableList<List<String>>, p2: List<List<String>>) {
    for (i in p1.size - 1 downTo 0) {
        for (j in 0..p2.size - 1) {
            if (p1.get(i).get(1) == p2.get(j).get(1)) {
                p1.removeAt(i)
                break
            }
        }
    }
    
    
    println("\nREPETIDOS ELIMINADOS\n\nPLAYLIST 1:\n")
    mostrarCanciones(p1)
    println("\nPLAYLIST 2:\n")
    mostrarCanciones(p2)
}

fun imprimirSubLista(lista: List<List<String>>, inicio: Int, fin: Int): List<List<String>> {
    val subLista: MutableList<List<String>> = mutableListOf()
    var finLocal = fin
    
    if (finLocal > lista.size) {
        finLocal = lista.size
    }
    
    for (i in inicio - 1..finLocal - 1) {
        subLista.add(lista.get(i))
    }
    
    return subLista
}

fun ordenar(lista : List<List<String>>){
    val ordenada = lista.sortedBy{it[1]}
    
    mostrarCanciones(ordenada)
}


fun main() {
    val topCancionesMundiales: List<List<String>> = listOf(
        listOf("1", "Blinding Lights", "The Weeknd", "5.59"),
        listOf("2", "Shape Of You", "Ed Sheeran", "5.10"),
        listOf("3", "Sweater Weather", "The Neighbourhood", "4.88"),
        listOf("4", "Starboy", "The Weeknd ft. Daft Punk", "4.76"),
        listOf("5", "As It Was", "Harry Styles", "4.62"),
        listOf("6", "One Dance", "Drake ft. Wizkid & Kyla", "4.47"),
        listOf("7", "Sunflower", "Post Malone & Swae Lee", "4.46"),
        listOf("8", "Someone You Loved", "Lewis Capaldi", "4.43"),
        listOf("9", "Perfect", "Ed Sheeran", "4.11"),
        listOf("10", "Stay", "The Kid LAROI & Justin Bieber", "4.07")
    )
        
    println("TOP CANCIONES MUNDIALES\n")
    mostrarCanciones(topCancionesMundiales)
    
    val p1 = playlistUno()
    val p2 = playlistDos().toMutableList()
    val p3 = playlistTres()
    
    eliminarRepetidos(p2, p3)
    
    println("\nTOP CANCIONES MUNDIALES (ORDENADAS)\n")
    ordenar(topCancionesMundiales);
    
    revolver(topCancionesMundiales)
}
