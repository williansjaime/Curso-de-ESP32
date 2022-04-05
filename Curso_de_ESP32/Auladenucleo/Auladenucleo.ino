/*Aula de semaforo = usado para executar ntarefas*/

/*Objetivo: Iniciar uma quantidade de tarefas e criar um semaforo para que todas sejam concluidas, antes que se acesse o loop. */

/*int nTarefas = 4;

int j = 0;

SemaphoreHandle_t Semaforo = xSemaphoreCreateCounting( nTarefas, 0 );

void setup() 
{ 
  
  Serial.begin(115200);
  delay(1000);
    
  Serial.println("Iniciando pra executar as funções.."); 

  int i;
 
  for(i = 0; i < nTarefas; i++)
  {
    xTaskCreatePinnedToCore
    (
      Tarefa,         
      "Tarefa",       
      10000,          
      (void *)i,      
      0,              
      NULL,           
      0              
    );
  }

  for(i= 0; i < nTarefas; i++)
  {    
    xSemaphoreTake(Semaforo, portMAX_DELAY);
  }
  
  Serial.println("Tarefas concluídas e semaforo vencido...");
  
}
 
void loop() 
{
  
  j++;
  delay(1500);
  Serial.print("Loop Funcionando: ");
  Serial.println(j);
    
}

void Tarefa( void * parametro )
{   
  String mensagem = "Número da Tarefa: ";
  mensagem = mensagem + ((int)parametro); 
  Serial.println(mensagem);
   
  xSemaphoreGive(Semaforo); 
    
  vTaskDelete(NULL);
}
/*int nTarefas = 4;
int j = 0;

SemaphoreHandle_t Semaforo = xSemaphoreCreateCounting( nTarefas, 0 );
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.println("Iniciando praexecutar as funções");

  int i =0;
  for(i=0; i < nTarefas; i++){
    xTaskCreatePinnedToCore  //essa funcao cria uma tarefa
    (
      Tarefa,
      "Tarefa",
      10000,
      (void *)i,
      0,
      NULL,
      0
      );
    }

    for(i=0; i< nTarefas; i++)
    {
        xSemaphoreTake(Semaforo, portMAX_DELAY);
      }
    Serial.println("Tarefas concluidas e semaforo Vencido...");
}

void loop() {
  // put your main code here, to run repeatedly:
  j++;
  delay(500);
  Serial.println("Laços infinito está rodando no Núcleo: ");
  Serial.println(j);

  
}

void Tarefa( void * parametro )
{   
  String mensagem = "Número da Tarefa: ";
  mensagem = mensagem + ((int)parametro); 
  Serial.println(mensagem);
   
  xSemaphoreGive(Semaforo); 
    
  vTaskDelete(NULL);
}



/*int Nucleo = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(1000);
xTaskCreatePinnedToCore  //essa funcao cria uma tarefa
(
  Tarefa,
  "Tarefa",
  10000,
  NULL,
  0,
  NULL,
  Nucleo
  );
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Laços infinito está rodando no Núcleo: ");
  Serial.println(xPortGetCoreID());

  delay(10000);
}

void Tarefa(void * Paramentro)
{ 
  while(true){
      String Mensagem = "A tarefa está rodando no Núcleo: ";
      Mensagem = Mensagem + xPortGetCoreID();
      Serial.println(Mensagem);
      delay(10000);
    }
   vTaskDelete(NULL); 
  }*/
