#include <iostream>
#include <random>
#include <vector>

using namespace std;

int inputValido(){
        int escolha;
        bool valido = false;
        do{
                cin >> escolha;
                if(cin.good()){
                        valido = true;
                }
                else{
                        cin.clear();
                        cin.ignore(999999, '\n');
                        cout << "Digite um número válido: " << endl;
                }
        }while(!valido);
        return escolha;
}

bool isSorted(vector<int> a){
	if(a.empty())
		return true;

	int tamanho, atual, ultimo;
	int i;
	tamanho = a.size();
	for(i = 0; i < tamanho-1; i++){
		if(a[i] > a[i+1]){
			return false;
		}
	}
	return true;

}


int main(){
	
	int randInt, tamLista, adicionado;
	vector<int> vetor, vetorSorted, aux;
	random_device rd;
	adicionado = 0;
	while(adicionado != -1){
		cout << "Digite um numero para colocar na lista: (-1 para finalizar)" << endl;
		adicionado = inputValido();
		if(adicionado != -1)
			vetor.push_back(adicionado);
	}

	cout << isSorted(vetor) << endl;
	
	aux = vetor;
	vetorSorted = vetor;
	int i = 0;
	int j, tamanhoTotal;
	tamanhoTotal = vetor.size();
	while(!isSorted(vetorSorted)){
		for(i = 0; i < tamanhoTotal; i++){
			tamLista = vetor.size();
			randInt = rd() % tamLista;
			vetorSorted[i] = vetor[randInt];
			vetor.erase(vetor.begin() + randInt);
			
		}
		vetor = aux;
		
		for(j = 0;j < tamanhoTotal;j++){
			cout << vetorSorted[j] << " ";
		}
		cout << endl;

	}
	cout << "Achooou" << endl;
	
}
