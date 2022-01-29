//
// Default DECOMPILED FUNCTIONS!!!
//
void flight(bool go)
{
    int32_t iVar1;
    double extraout_XMM0_Qa;
    uint64_t var_4h;

    if (semDown(semgid, sh->mutex) == -1)
    {
        perror("error on the up operation for semaphore access (PT)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    if ((char)go == '\0')
    {
        sh->fSt.st.pilotStat = 0;
    }
    else
    {
        sh->fSt.st.pilotStat = 3;
    }
    saveState(nFic, &sh->fSt);
    if (semUp (semgid, sh->mutex) == -1)
    {
        perror("error on the up operation for semaphore access (PT)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    random();
    floor();
    usleep((int64_t)extraout_XMM0_Qa & 0xffffffff);
    return;
}

void signalReadyForBoarding(void)
{
    int32_t iVar1;
    
    iVar1 = semDown((semgid, sh->mutex));
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    sh->fSt.st.pilotStat = 1; // ready for boarding
    sh->fSt.nFlight = sh->fSt.nFlight + 1;
    saveState(nFic, &sh->fSt);
    saveStartBoarding(nFic, &sh->fSt);
    iVar1 = semUp((semgid, sh->mutex));
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    iVar1 = semUp(semgid, sh->readyForBoarding);
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    return;
}

void waitUntilReadyToFlight(void)
{
    int32_t iVar1;
    
    iVar1 = semDown(semgid, sh->mutex);
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    sh->fSt.st.pilotStat = 2; // waiting for boarding
    saveState(nFic, &sh->fSt);
    iVar1 = semUp(semgid, sh->mutex);
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    iVar1 = semDown(semgid, sh->readyToFlight);
    if (iVar1 == -1) {
        perror("error on the down operation for semaphore readyToFLight (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    return;
}


void dropPassengersAtTarget(void)
{
    int32_t iVar1;
    int64_t var_4h;
    
    iVar1 = semDown(semgid, sh->mutex);
    if (iVar1 == -1) {
        perror("error on the down operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    saveFlightArrived(nFic, &sh->fSt);
    sh->fSt.st.pilotStat = 4; // dropping passengers
    saveState(nFic, &sh->fSt);
    // for (var_4h._0_4_ = sh->fSt.nPassInFlight; 0 < (int32_t)var_4h; var_4h._0_4_ = (int32_t)var_4h + -1) {
    //     semUp((uint64_t)_semgid, (uint64_t)*(uint32_t *)(_sh + 0x15));
    // }
    for (num = sh->fSt.nPassInFlight; 0 < num; num--) {
         if (semUp (semgid, sh->passengersWaitInFlight == -1)){
            perror("error on the down operation for semaphore access (PT)");
            exit (EXIT_FAILURE);
            }
    }
    iVar1 = semUp(semgid, sh->mutex);
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    semDown(semgid, sh->planeEmpty);
    iVar1 = semDown(semgid, sh->mutex);
    if (iVar1 == -1) {
        perror("error on the down operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    saveFlightReturning((int64_t)nFic, (int64_t)_sh);
    iVar1 = semUp(semgid, sh->mutex);
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    return;
}



// alteracoes no historico de versao do git

 static void dropPassengersAtTarget()
{
    if (semDown(semgid, sh->mutex) == -1)
    { /* enter critical region */
        perror("error on the down operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }
    saveFlightArrived(nFic, &sh->fSt);
    sh->fSt.st.pilotStat = DROPING_PASSENGERS;
    saveState(nFic, &(sh->fSt));
    while (sh->fSt.nPassengersInFlight[sh->fSt.nFlight - 1] > 0)
    {
        sh->fSt.nPassengersInFlight[sh->fSt.nFlight - 1]--;
    }

        if (semUp (semgid, sh->passengersWaitInFlight == -1)){
            perror("error on the down operation for semaphore access");
            exit (EXIT_FAILURE);
        }
                
    if (semUp(semgid, sh->mutex) == -1)
    { /* exit critical region */
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }

    /* insert your code here */

    if (semDown (semgid, sh->mutex) == -1) {                                                  /* enter critical region */
        perror ("error on the down operation for semaphore access (PT)");
    if (semDown(semgid, sh->planeEmpty) == -1)
    {
        perror("error on the down operation for semaphore access");
        exit(EXIT_FAILURE);
    }

        
        if (semDown (semgid, sh->planeEmpty) == -1){
            perror("error on the down operation for semaphore access");
    if (semDown(semgid, sh->mutex) == -1)
    { /* enter critical region */
        perror("error on the down operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }
    
        if (sh->fSt.nPassengersInFlight == 0){
            sh->fSt.st.pilotStat = FLYING_BACK;
    saveFlightReturning(nFic, &sh->fSt);
        }

    if (semUp(semgid, sh->mutex) == -1)
    { /* exit critical region */
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }
}


void dropPassengersAtTarget(void)
{
    int32_t iVar1;
    int64_t var_4h;
    
    iVar1 = semDown((uint64_t)_semgid, (uint64_t)*(uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1) {
        perror("error on the down operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    saveFlightArrived((int64_t)nFic, (int64_t)_sh);
    *(undefined4 *)_sh = 4;
    saveState((int64_t)nFic, _sh);
    for (var_4h._0_4_ = *(int32_t *)((int64_t)_sh + 0x8c); 0 < (int32_t)var_4h; var_4h._0_4_ = (int32_t)var_4h + -1) {
        semUp((uint64_t)_semgid, (uint64_t)*(uint32_t *)(_sh + 0x15));
    }
    iVar1 = semUp((uint64_t)_semgid, (uint64_t)*(uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    semDown((uint64_t)_semgid, (uint64_t)*(uint32_t *)(_sh + 0x17));
    iVar1 = semDown((uint64_t)_semgid, (uint64_t)*(uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1) {
        perror("error on the down operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    saveFlightReturning((int64_t)nFic, (int64_t)_sh);
    iVar1 = semUp((uint64_t)_semgid, (uint64_t)*(uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    return;
}


// older stuff

static void dropPassengersAtTarget ()
{
    if (semDown (semgid, sh->mutex) == -1) {                                                  /* enter critical region */
        perror ("error on the down operation for semaphore access (PT)");
        exit (EXIT_FAILURE);
    }
        saveFlightArrived(nFic, &sh->fSt);
        
        sh->fSt.st.pilotStat = DROPING_PASSENGERS;
        saveState(nFic, &(sh->fSt));
        saveFlightArrived(nFic, &sh->fSt);

        while(sh->fSt.nPassengersInFlight[sh->fSt.nFlight-1] > 0){
            sh->fSt.nPassengersInFlight[sh->fSt.nFlight-1]--;
        }

        if (semUp (semgid, sh->passengersWaitInFlight == -1)){
            perror("error on the down operation for semaphore access");
            exit (EXIT_FAILURE);
        }
                
    if (semUp (semgid, sh->mutex) == -1)  {                                                   /* exit critical region */
        perror ("error on the up operation for semaphore access (PT)");
        exit (EXIT_FAILURE);
    }

    /* insert your code here */

    if (semDown (semgid, sh->mutex) == -1) {                                                  /* enter critical region */
        perror ("error on the down operation for semaphore access (PT)");
        exit (EXIT_FAILURE);
    }

        
        if (semDown (semgid, sh->planeEmpty) == -1){
            perror("error on the down operation for semaphore access");
            exit (EXIT_FAILURE);
        }
        
        if (sh->fSt.nPassengersInFlight == 0){
            sh->fSt.st.pilotStat = FLYING_BACK;
            saveFlightReturning(nFic, &sh->fSt);
        }

    if (semUp (semgid, sh->mutex) == -1)  {                                                   /* exit critical region */
        perror ("error on the up operation for semaphore access (PT)");
        exit (EXIT_FAILURE);
    }
}


void waitUntilReadyToFlight(void)
{
    int32_t iVar1;
    
    iVar1 = semDown((uint64_t)_semgid, (uint64_t)*(uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    *(undefined4 *)_sh = 2;
    saveState((int64_t)nFic, _sh);
    iVar1 = semUp((uint64_t)_semgid, (uint64_t)*(uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    iVar1 = semDown((uint64_t)_semgid, (uint64_t)*(uint32_t *)(_sh + 0x16));
    if (iVar1 == -1) {
        perror("error on the down operation for semaphore readyToFLight (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    return;
}


void signalReadyForBoarding(void)
{
    int32_t iVar1;
    
    iVar1 = semDown((uint64_t)_semgid, (uint64_t)*(uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    *(undefined4 *)_sh = 1;
    *(int32_t *)((int64_t)_sh + 0x84) = *(int32_t *)((int64_t)_sh + 0x84) + 1;
    saveState((int64_t)nFic, _sh);
    saveStartBoarding((int64_t)nFic, (int64_t)_sh);
    iVar1 = semUp((uint64_t)_semgid, (uint64_t)*(uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    iVar1 = semUp((uint64_t)_semgid, (uint64_t)*(uint32_t *)((int64_t)_sh + 0xac));
    if (iVar1 == -1) {
        perror("error on the up operation for semaphore access (PT)");
    // WARNING: Subroutine does not return
        exit(1);
    }
    return;
}







/////// OLD PILOT /////////////






/**
 *  \file semSharedMemPilot.c (implementation file)
 *
 *  \brief Problem name: Air Lift
 *
 *  Synchronization based on semaphores and shared memory.
 *  Implementation with SVIPC.
 *
 *  Definition of the operations carried out by the pilot:
 *     \li flight
 *     \li signalReadyForBoarding
 *     \li waitUntilReadyToFlight
 *     \li dropPassengersAtTarget
 *
 *  \author Nuno Lau - January 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>

#include "probConst.h"
#include "probDataStruct.h"
#include "logging.h"
#include "sharedDataSync.h"
#include "semaphore.h"
#include "sharedMemory.h"

/** \brief logging file name */
static char nFic[51];

/** \brief shared memory block access identifier */
static int shmid;

/** \brief semaphore set access identifier */
static int semgid;

/** \brief pointer to shared memory region */
static SHARED_DATA *sh;

static void flight(bool go);
static void signalReadyForBoarding();
static void waitUntilReadyToFlight();
static void dropPassengersAtTarget();
static bool isFinished();

/**
 *  \brief Main program.
 *
 *  Its role is to generate the life cycle of one of intervening entities in the problem: the pilot.
 */

int main(int argc, char *argv[])
{
    int key;    /*access key to shared memory and semaphore set */
    char *tinp; /* numerical parameters test flag */

    /* validation of command line parameters */

    if (argc != 4)
    {
        freopen("error_PT", "a", stderr);
        fprintf(stderr, "Number of parameters is incorrect!\n");
        return EXIT_FAILURE;
    }
    else
        freopen(argv[3], "w", stderr);
    strcpy(nFic, argv[1]);
    key = (unsigned int)strtol(argv[2], &tinp, 0);
    if (*tinp != '\0')
    {
        fprintf(stderr, "Error on the access key communication!\n");
        return EXIT_FAILURE;
    }

    /* connection to the semaphore set and the shared memory region and mapping the shared region onto the
       process address space */

    if ((semgid = semConnect(key)) == -1)
    {
        perror("error on connecting to the semaphore set");
        return EXIT_FAILURE;
    }
    if ((shmid = shmemConnect(key)) == -1)
    {
        perror("error on connecting to the shared memory region");
        return EXIT_FAILURE;
    }
    if (shmemAttach(shmid, (void **)&sh) == -1)
    {
        perror("error on mapping the shared region on the process address space");
        return EXIT_FAILURE;
    }

    srandom((unsigned int)getpid()); /* initialize random generator */

    /* simulation of the life cycle of the pilot */

    while (!isFinished())
    {
        flight(false); // from target to origin
        signalReadyForBoarding();
        waitUntilReadyToFlight();
        flight(true); // from origin to target
        dropPassengersAtTarget();
    }

    /* unmapping the shared region off the process address space */

    if (shmemDettach(sh) == -1)
    {
        perror("error on unmapping the shared region off the process address space");
        return EXIT_FAILURE;
        ;
    }

    return EXIT_SUCCESS;
}

/**
 *  \brief test if air lift finished
 */
static bool isFinished()
{
    return sh->fSt.finished;
}

/**
 *  \brief flight.
 *
 *  The pilot takes passenger to destination (go) or
 *  plane back to starting airport (return)
 *  state should be saved.
 *
 *  \param go true if going to destination
 */

static void flight(bool go)
{
    if (semDown(semgid, sh->mutex) == -1)
    { /* enter critical region */
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }

    /* insert your code here */
    if (go)
    {
        sh->fSt.st.pilotStat = FLYING_BACK;
    }
    else
    {
        sh->fSt.st.pilotStat = FLYING;
    };

    saveState(nFic, &(sh->fSt));

    if (semUp(semgid, sh->mutex) == -1)
    { /* exit critical region */
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }

    usleep((unsigned int)floor((MAXFLIGHT * random()) / RAND_MAX + 100.0));
}

/**
 *  \brief pilot informs hostess that plane is ready for boarding
 *
 *  The pilot updates its state and signals the hostess that boarding may start
 *  The flight number should be updated.
 *  The internal state should be saved.
 */

static void signalReadyForBoarding()
{
    if (semDown(semgid, sh->mutex) == -1)
    { /* enter critical region */
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }

    sh->fSt.st.pilotStat = READY_FOR_BOARDING;
    sh->fSt.nFlight++;
    saveState(nFic, &sh->fSt);
    saveStartBoarding(nFic, &sh->fSt);

    if (semUp(semgid, sh->mutex) == -1)
    { /* exit critical region */
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }
    if (semUp(semgid, sh->readyForBoarding) == -1)
    { // Up ready for boarding
        perror("error on the down operation for semaphore access");
        exit(EXIT_FAILURE);
    }
}

/**
 *  \brief pilot waits for plane to get filled with passengers.
 *
 *  The pilot updates its state and wait for Boarding to finish
 *  The internal state should be saved.
 */

static void waitUntilReadyToFlight()
{
    if (semDown(semgid, sh->mutex) == -1)
    { /* enter critical region */
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }

    sh->fSt.st.pilotStat = WAITING_FOR_BOARDING;
    saveState(nFic, &sh->fSt);

    if (semUp(semgid, sh->mutex) == -1)
    { /* exit critical region */
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }

    if (semDown(semgid, sh->readyToFlight) == -1)
    {
        perror("error on the down operation for semaphore readyToFLight (PT)");
        exit(EXIT_FAILURE);
    }
}

/**
 *  \brief pilot drops passengers at destination.
 *
 *  Pilot update its state and allows passengers to leave plane
 *  Pilot must wait for all passengers to leave plane before starting to return.
 *  The internal state should not be saved twice (after allowing passengeres to leave and after the plane is empty).
 */

static void dropPassengersAtTarget()
{
    if (semDown(semgid, sh->mutex) == -1)
    { /* enter critical region */
        perror("error on the down operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }
    saveFlightArrived(nFic, &sh->fSt);
    sh->fSt.st.pilotStat = DROPING_PASSENGERS;
    saveState(nFic, &(sh->fSt));

    while (sh->fSt.nPassInFlight > 0)
        {
            if (semUp(semgid, sh->passengersWaitInFlight == -1))
            {
                perror("error on the down operation for semaphore access (PT)");
                exit(EXIT_FAILURE);
            }
            sh->fSt.nPassInFlight--;
        }
    // for (int num = sh->fSt.nPassInFlight; 0 < num; num--) {
    //     if (semUp (semgid, sh->passengersWaitInFlight == -1)){
    //         perror("error on the down operation for semaphore access (PT)");
    //         exit (EXIT_FAILURE);
    //     }

    // }

    if (semUp(semgid, sh->mutex) == -1)
    { /* exit critical region */
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }

    if (semDown(semgid, sh->planeEmpty) == -1)
    {
        perror("error on the down operation for semaphore PlaneEmpty access (PT)");
        exit(EXIT_FAILURE);
    }

    if (semDown(semgid, sh->mutex) == -1)
    { /* enter critical region */
        perror("error on the down operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }


    saveFlightReturning(nFic, &sh->fSt);

    if (semUp(semgid, sh->mutex) == -1)
    { /* exit critical region */
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }
}

