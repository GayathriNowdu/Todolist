#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 typedef struct {//using task after base so we ill keep typedef//
    char *task;
    int completed;//one represent true and zero represents false//
} Task;
  Task *tasks=NULL;
    int length=0;
    void addTask(const char *task){
      tasks =(Task *)realloc(tasks, (length + 1) * sizeof(Task));
      tasks[length].task=(char*)malloc(strlen(task)+1);//for every string their is \0 for that adding +1//
      tasks[length].completed=0;
      strcpy(tasks[length].task,task);
      length ++;
      printf("Task added\n");
    }
    void listTasks(){ 
        char status;
        for(int i=0;i<length;i++)
        {
            if(tasks[length].completed==1){
                status='d';
            }
            else{
                status='n';
            }
            printf("%d .%s [%c]\n",i+1,tasks[i].task,status);
        }
    }
    void markcompleted(int index){
      if(index <=length && index>0){
        tasks[index-1].completed=1;//here -1 is beacause we are start from 1 but for compiler it starts from 0//
        printf("Task marked as completed\n");
      }
      else{
        printf("Invalid index\n");
      }
    }
    void deleteTask(int index){
      if(index <=length && index>0){
        index=index-1;
        free(tasks[index].task);
        for(int i=index;i<length-1;i++){     //here the case is for deleting so we are using -1.//
        tasks[i]=tasks[i+1];
        length--;
        tasks=(Task *)realloc(tasks,(length*sizeof(Task)));
        }
      }
      else{
        printf("invalid index\n");
      }
    }
    void edittask(int index, const char* task){
      if(index <=length && index>0){
        index=index-1;
        char *editedtask=(char *)realloc(tasks[index].task,strlen(task)+1);
      if(editedtask!=NULL){
        tasks[index].task=editedtask;
        strcpy(tasks[index].task,task);
        printf("Tasks updated successfully\n");
      }
      else
          printf("invalid index\n");
     }
    }
int main(){
    int running=1,choice,indexinput;
    char taskinput[100];
    printf("\n options \n");
    printf("1.Add a task\n");
    printf("2.list all tasks\n");
    printf("3.Mark as complete\n");
    printf("4.Edit task\n");
    printf("5.Delete task\n");
    printf("6.Exit\n");
    while(running == 1){
        printf("Enter choice(1,2,3,4,5,6):");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter task:\n");
            getchar();
            fgets(taskinput,sizeof(taskinput),stdin);
            taskinput[strcspn(taskinput,"\n")]='\0';
            addTask(taskinput);
            break;//here break is needed//
            case 2:
            listTasks();
            break;
            case 3:
            printf("enter index:");
            scanf("%d",&indexinput);
            markcompleted(indexinput);
            break;
            case 4:
             printf("enter index:");
            scanf("%d",&indexinput);
            printf("enter edited task:");
            getchar();
            fgets(taskinput,sizeof(taskinput),stdin);
             taskinput[strcspn(taskinput,"\n")]='\0';
             edittask(indexinput,taskinput);
             break;
            case 5:
             printf("enter index:");
            scanf("%d",&indexinput);
            deleteTask(indexinput);
            break;
            case 6:
            default:
            printf("Invalid choice\n");
            break;//using break is not that much necessary here//
        }
    }
     free(tasks);
     return 0;
}