//
// REFERENCE FUNCTIONS FROM DECOMPILER...
//

// void waitForNextFlight(void)
// {
//     int32_t iVar1;

//     iVar1 = semDown((semgid, sh->mutex));
//     if (iVar1 == -1)
//     {
//         perror("error on the up operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     sh->fSt.st.hostessStat = 0;
//     saveState(nFic, &sh->fSt);
//     iVar1 = semUp((semgid, sh->mutex));
//     if (iVar1 == -1)
//     {
//         perror("error on the down operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     iVar1 = semDown((uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0xac));
//     if (iVar1 == -1)
//     {
//         perror("error on the down operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     return;
// }

// void waitForPassenger(void)
// {
//     int32_t iVar1;

//     iVar1 = semDown((semgid, sh->mutex));
//     if (iVar1 == -1)
//     {
//         perror("error on the up operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     sh->fSt.st.hostessStat = 1;
//     saveState(nFic, &sh->fSt);
//     iVar1 = semUp((semgid, sh->mutex));
//     if (iVar1 == -1)
//     {
//         perror("error on the down operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     iVar1 = semDown((uint64_t)_semgid, (uint64_t) * (uint32_t *)(_sh + 0x14));
//     if (iVar1 == -1)
//     {
//         perror("error on the down operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     return;
// }

// undefined checkPassport(void)
// {
//     undefined last;
//     int32_t iVar2;
//     int64_t var_1h;

//     iVar2 = semUp((uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0xa4));
//     if (iVar2 == -1)
//     {
//         perror("error on the up operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     iVar2 = semDown((semgid, sh->mutex));
//     if (iVar2 == -1)
//     {
//         perror("error on the up operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     sh->fSt.st.hostessStat = 2;
//     saveState(nFic, &sh->fSt);
//     iVar2 = semUp((semgid, sh->mutex));
//     if (iVar2 == -1)
//     {
//         perror("error on the up operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     iVar2 = semDown((uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0xb4));
//     if (iVar2 == -1)
//     {
//         perror("error on the down operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     iVar2 = semDown((semgid, sh->mutex));
//     if (iVar2 == -1)
//     {
//         perror("error on the up operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     *(int32_t *)(_sh + 0x11) = *(int32_t *)(_sh + 0x11) + -1;
//     *(int32_t *)((int64_t)_sh + 0x8c) = *(int32_t *)((int64_t)_sh + 0x8c) + 1;
//     sh->fSt.totalPassBoarded = sh->fSt.totalPassBoarded + 1;
//     savePassengerChecked(nFic, &sh->fSt);
//     saveState(nFic, &sh->fSt);
//     iVar2 = nPassengersInFlight();
//     if (iVar2 < 10)
//     {
//         iVar2 = nPassengersInFlight();
//         if (4 < iVar2)
//         {
//             iVar2 = nPassengersInQueue();
//             if (iVar2 == 0)
//                 goto code_r0x004010ed;
//         }
//         if (sh->fSt.totalPassBoarded != N)
//         {
//             last = 0;
//             goto code_r0x004010f9;
//         }
//     }
// code_r0x004010ed:
//     last = 1;
// code_r0x004010f9:
//     iVar2 = semUp((semgid, sh->mutex));
//     if (iVar2 == -1)
//     {
//         perror("error on the up operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     return last;
// }

// void signalReadyToFlight(void)
// {
//     int32_t iVar1;
//     int64_t i;

//     iVar1 = semDown((semgid, sh->mutex));
//     if (iVar1 == -1)
//     {
//         perror("error on the up operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     sh->fSt.st.hostessStat = 3;
//     saveState(nFic, &sh->fSt);
//     i = 0;
//     for (j = 0; j < sh->fSt.nFlight - 1U; j = j + 1)
//     {
//         i = (int32_t)i + *(int32_t *)((int64_t)_sh + ((int64_t)(int32_t)j + 0x14) * 4 + 0xc);
//     }
//    sh->fSt.nPassengersInFlight[sh->fSt.nFlight - 1] =
//         sh->fSt.totalPassBoarded - (int32_t)i;
//     saveFlightDeparted(nFic, &sh->fSt);
//     if (sh->fSt.totalPassBoarded == N)
//     {
//         *(undefined *)((int64_t)_sh + 0x94) = 1;
//     }
//     iVar1 = semUp((semgid, sh->mutex));
//     if (iVar1 == -1)
//     {
//         perror("error on the up operation for semaphore access (HT)");
//         
//         exit(1);
//     }
//     semUp((uint64_t)_semgid, (uint64_t) * (uint32_t *)(_sh + 0x16));
//     return;
// }

//
// DECODED FUNCTIONS...
//

void waitForNextFlight(void) //CORRETA!
{
    int32_t iVar1;

    if (semDown(semgid, sh->mutex) == -1)
    {
        perror("error on the up operation for semaphore access (HT)");
        
        exit(1);
    }
    // sh->fSt.st.hostessStat = 0;
    sh->fSt.st.hostessStat = WAIT_FOR_FLIGHT;
    saveState(nFic, &sh->fSt);
    if (semUp(semgid, sh->mutex) == -1)
    {
        perror("error on the down operation for semaphore access (HT)");
        
        exit(1);
    }
    if (semDown(semgid, sh->readyForBoarding) == -1)
    {
        perror("error on the down operation for semaphore access (HT)");
        
        exit(1);
    }
    return;
}

void waitForPassenger(void) //CORRETA!
{
    int32_t iVar1;

    if (semDown(semgid, sh->mutex) == -1) 
    {
        perror("error on the up operation for semaphore access (HT)");
        
        exit(1);
    }
    // sh->fSt.st.hostessStat = 1;
    sh->fSt.st.hostessStat = WAIT_FOR_PASSENGER;
    saveState(nFic, &sh->fSt);
    if (semUp(semgid, sh->mutex) == -1)
    {
        perror("error on the down operation for semaphore access (HT)");
        
        exit(1);
    }
    if (semDown(semgid, sh->passengersInQueue) == -1)
    {
        perror("error on the down operation for semaphore access (HT)");
        
        exit(1);
    }
    return;
}

bool checkPassport(void)
{
    bool last; // bool last;
    int32_t iVar2;
    int64_t var_1h;

    if (semUp(semgid, sh->passengersWaitInQueue) == -1)
    {
        perror("error on the up operation for semaphore access (HT)");
        exit(1);
    }
    if (semDown(semgid, sh->mutex) == -1)
    {
        perror("error on the up operation for semaphore access (HT)");
        exit(1);
    }
    sh->fSt.st.hostessStat = CHECK_PASSPORT;
    saveState(nFic, &sh->fSt);
    if (semUp(semgid, sh->mutex) == -1)
    {
        perror("error on the up operation for semaphore access (HT)");
        exit(1);
    }
    if (semDown(semgid, sh->idShown) == -1)
    {
        perror("error on the down operation for semaphore access (HT)");
        exit(1);
    }
    if (semDown(semgid, sh->mutex) == -1)
    if (iVar2 == -1)
    {
        perror("error on the up operation for semaphore access (HT)");
        exit(1);
    }
    *(int32_t *)(_sh + 0x11) = *(int32_t *)(_sh + 0x11) + -1;
    *(int32_t *)((int64_t)_sh + 0x8c) = *(int32_t *)((int64_t)_sh + 0x8c) + 1;
    sh->fSt.totalPassBoarded = sh->fSt.totalPassBoarded + 1;
    savePassengerChecked(nFic, &sh->fSt);
    saveState(nFic, &sh->fSt);

    if (nPassengersInFlight() < MAXFC)
    {
        if (nPassengersInFlight() >= MINFC - 1)
        {
            if (nPassengersInQueue() == 0)
                // goto code_r0x004010ed;
                last = 1;
        }
        if (sh->fSt.totalPassBoarded != N) // N maybe == N???
        {
            last = 0;
            goto code_r0x004010f9;
        }
    }
code_r0x004010ed:
    last = 1;
code_r0x004010f9:
    if (semUp(semgid, sh->mutex) == -1)
    {
        perror("error on the up operation for semaphore access (HT)");
        exit(1);
    }
    return last;
}

void signalReadyToFlight(void)
{
    int32_t iVar1;
    int64_t i;

    if (semDown(semgid, sh->mutex) == -1)
    {
        perror("error on the up operation for semaphore access (HT)");
        exit(1);
    }
    sh->fSt.st.hostessStat = READY_TO_FLIGHT;
    saveState(nFic, &sh->fSt);
    i = 0;
    for (j = 0; j < sh->fSt.nFlight-1; j++)
    {
        i = i + sh->fSt.nPassengersInFlight[sh->fSt.nFlight+j];
    }
    sh->fSt.nPassengersInFlight[sh->fSt.nFlight - 1] = sh->fSt.totalPassBoarded - i;
    saveFlightDeparted(nFic, &sh->fSt);

    if (sh->fSt.totalPassBoarded == N)
    {
        sh->fSt.finished = true;
    }

    if (semUp(semgid, sh->mutex) == -1)
    {
        perror("error on the up operation for semaphore access (HT)");
        exit(1);
    }

    if (semUp(semgid, sh->readyToFlight) == -1)
    { 
        perror("error on the up operation for semaphore access (PT)");
        exit(EXIT_FAILURE);
    }
    return;
}