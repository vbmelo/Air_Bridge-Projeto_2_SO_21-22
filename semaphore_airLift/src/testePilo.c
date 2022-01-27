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