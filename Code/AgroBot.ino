void MoveLeft()
{
    digitalWrite(11,LOW);
      
    digitalWrite(10,LOW);
    
    digitalWrite(13,LOW);
    
    digitalWrite(12,HIGH);
}

void MoveRight()
{
    digitalWrite(11,LOW); 
    
    digitalWrite(10,HIGH);
    
    digitalWrite(13,LOW);
    
    digitalWrite(12,LOW);
}

void MoveFront()
{
    digitalWrite(11,LOW);
    
    digitalWrite(10, HIGH);
    
    digitalWrite(13,LOW); 
    
    digitalWrite(12, HIGH);
}


void Stop()
{
    digitalWrite(11,LOW);
    
    digitalWrite(10,LOW);
    
    digitalWrite(13,LOW); 
    
    digitalWrite(12,LOW);
}

void MoveBack()
{
    digitalWrite(11,HIGH);
    
    digitalWrite(10,LOW);
    
    digitalWrite(13,HIGH);
    
    digitalWrite(12,LOW);
}

void MoveUp()
{
    digitalWrite(7,HIGH);
    
    digitalWrite(6,LOW);
}

void MoveDown()
{
    digitalWrite(7,LOW);
    
    digitalWrite(6,HIGH);
}

void ProkStop()
{
    digitalWrite(7,LOW);
    
    digitalWrite(6,LOW);
}

void setup()
{
    Serial.begin(9600);
    
    pinMode(AO,INPUT); 
    
    pinMode(13,OUTPUT); 
    pinMode(12,OUTPUT);
    pinMode(11,OUTPUT); 
    pinMode(10,OUTPUT); 
    pinMode(9,OUTPUT); 
    pinMode(8,OUTPUT); 
    pinMode(7,OUTPUT);
    pinMode(6,OUTPUT);
    
    Serial.write("begin");
}

void loop()
{
    int sensorValue=analogRead(A0);
    
    if (sensorValue>500)
    {
        digitalWrite(9,HIGH);
        
        digitalWrite(8,LOW);
        
        Serial.print("PUMP ON\n");
    }
    
    else
    {
        digitalWrite(9,LOW);
        
        digitalWrite(8,LOW);
        
        Serial.print("PUMP OFF\n");
    }
    
    if(Serial.available())
    {
        char Data = Serial.read();
        
        if(Data == "'F')
        {
            Serial.print("FORWARD"):
            
            Stop();
            
            delay(10);
            
            MoveFront();
            
            Serial.print("FORWARD");
        }
        
        
        else if(Data =='S')
        {
            Stop();
            
            Serial.print("STOP\n");
        }
        
        else if(Data == 'L')
        {
            Stop();
            
            delay(10);
            
            Moveteft();
            
            Serial.print("LEFT\n");
        }
    
        else if(Data == 'R')
        {
            Stop();
            
            delay(10);
            
            MoveRight();
            
            Serial.print("RIGHT\n");
        }
        
        else if(Data == 'B')
        {
            Stop();
            
            delay(10):
            
            MoveBack();
            
            Serial.print("BACK");
        }
        else if(Data == 'a')
        {
            Stop():
            
            delay(10);
            
            MoveUpl):
            
            Serial.print("PROK UP\n");
        }
        
        else if(Data == 'b')
        {
            Stop();
            
            delay(10);
            
            MoveDown();
            
            Serial.print("PROK DOWN\n");
        }
        
        else if(Data == 'c')
        {
            Stop();
            
            delay(10);
            
            ProkStop():
            
            Serial.print("PROK STOP\n");
        }
    }
}
