#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int n, processes[MAX], processesId[MAX];
int coordinator;

// Sorting processes in ascending order based on process ID
void bubbleSort(int processesId[], int processes[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (processesId[j] > processesId[j + 1]) 
            {
                // Swap process IDs
                int temp = processesId[j];
                processesId[j] = processesId[j + 1];
                processesId[j + 1] = temp;
                
                // Swap corresponding process numbers
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to simulate communication with coordinator
int checkCoordinatorResponse(int process) 
{
    int response;
    printf("\nProcess %d is sending message to Coordinator (Process %d)...\n", process, coordinator);
    printf("Did the coordinator respond? (1 for Yes, 0 for No): ");
    scanf("%d", &response);
    return response;
}

// Function to initiate election from a specific node
void initiateElection(int initiator) 
{
    printf("\nProcess %d initiated election.\n", initiator);
    int new_coordinator = initiator;
    for (int i = 0; i < n; i++) 
    {
        if (processesId[i] > processesId[initiator]) 
        {
            printf("Process %d sends election message to Process %d\n", initiator, processes[i]);
            new_coordinator = processes[i];
        }
    }
    coordinator = new_coordinator;
    printf("\nNew Coordinator is Process %d\n", coordinator);
}

// Function to handle rejoining of initial coordinator
void rejoinCoordinator(int old_coordinator) 
{
    printf("\nInitial Coordinator Process %d is back online!\n", old_coordinator);
    if (old_coordinator > coordinator) 
    {
        coordinator = old_coordinator;
        printf("Process %d takes back leadership as the Coordinator!\n", coordinator);
    }
    else 
    {
        printf("Process %d remains the Coordinator!\n", coordinator);
    }
}

int main() 
{   
    int choice, initiator, old_coordinator;
    
    while (1) 
    {
        printf("\nChoose an option:\n");
        printf("1. Enter the number of nodes\n");
        printf("2. Enter individual node IDs\n");
        printf("3. Declare initial coordinator\n");
        printf("4. Simulate process communication with coordinator\n");
        printf("5. Initiate election algorithm\n");
        printf("6. Initial coordinator comes up\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                printf("Enter the number of processes: ");
                scanf("%d", &n);
                break;
                
            case 2:
                for (int i = 0; i < n; i++) 
                {
                    printf("Enter Process ID for process %d: ", (i + 1));
                    scanf("%d", &processesId[i]);
                    processes[i] = i + 1;
                }
                bubbleSort(processesId, processes, n);
                break;
                
            case 3:
                coordinator = processes[n - 1];
                printf("The initial coordinator is Process %d\n", coordinator);
                break;
                
            case 4:
                for (int i = 0; i < n; i++)
                {
                    if (!checkCoordinatorResponse(processes[i]))
                    {
                        printf("Process %d did not receive a response. Initiating election...\n", processes[i]);
                        initiator = processes[i];
                        break;
                    }
                }
                break;
                
            case 5:
                if (initiator >= 0 && initiator < n)
                {
                    initiateElection(initiator);
                }
                else
                {
                    printf("Invalid process number!\n");
                }
                break;
                
            case 6:
                printf("Enter the ID of the initial coordinator that is back: ");
                scanf("%d", &old_coordinator);
                rejoinCoordinator(old_coordinator);
                break;
                
            case 7:
                printf("Exiting program.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
