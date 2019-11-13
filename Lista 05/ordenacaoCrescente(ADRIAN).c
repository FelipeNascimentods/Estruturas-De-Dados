void ordenaCrescente(TipoFila *Fila){
    Apontador aux, aux2, menor, primeiro, anteriorAux, anteriorFinal;
    aux = Fila->frente;

    while(aux->prox != NULL){
        menor = aux->prox;
        aux2 = aux ->prox;
        anteriorAux = aux->prox;
        primeiro = aux->prox;

        while(aux2 != NULL){
            if(menor->item.chave > aux2->item.chave){
                anteriorFinal = anteriorAux;
                menor->item = aux2->item;
            }
            anteriorAux = aux2;
            aux2 = aux2->prox;
        }

        anteriorFinal->prox = menor->prox;
        menor->prox = primeiro->prox;
        primeiro->prox = menor

        aux = aux->prox;
    }
}
