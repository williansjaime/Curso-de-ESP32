/*Objetivo: Iniciar uma quantidade de tarefas e criar um semaforo para que todas sejam concluidas, antes que se acesse o loop. */

int nTarefas = 4;

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
