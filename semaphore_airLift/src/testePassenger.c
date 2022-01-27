int64_t waitInQueue(long passengerId)
{
    long var_4h;
    rdi = passengerId;
    var_4h = edi;
    sh = sh;
    edx = *((sh + 0x9c));
    semgid = semgid;
    edx = edx;
    edi = semgid;
    semgid = semDown();
    if (semgid == 0xffffffff)
    { // MUTEX DOWN linha 143
        perror("error on the down operation for semaphore access (PG)");
        exit(1);
    }
    sh = sh;
    edx = *((sh + 0x88)); // nPassInQueue
    edx++;                // nPassInQueue++
    *((sh + 0x88)) = edx; // nPassInQueue++
    sh = sh;
    edx = var_4h;
    *((sh + rdx * 4 + 8)) = 1; // passengerStat = 1 // IN_QUEUE
    sh = sh;
    rsi = sh;
    edi = nFic;
    saveState(); // SAVE STATE - linha 149
    sh = sh;
    edx = *((sh + 0x9c));
    semgid = semgid;
    edx = edx;
    edi = semgid;
    semgid = semUp();
    if (semgid == 0xffffffff) // UP PassengersInQueue - linha 151
    {
        perror("error on the up operation for semaphore access (PG)");
        exit(1);
    }
    sh = sh;
    edx = *((sh + 0xa0));
    semgid = semgid;
    edx = edx;
    edi = semgid;
    semUp(); // UP idShown - linha 156 || UP  MUTEX
    sh = sh;
    edx = *((sh + 0xa4));
    semgid = semgid;
    edx = edx;
    edi = semgid;
    semDown(); // DOWN passengersInQueue - linha 161
    sh = sh;
    edx = *((sh + 0x9c));
    semgid = semgid;
    edx = edx;
    edi = semgid;
    semgid = semDown(); // Down em outra coisa ???? DOWN MUTEX MAYBE?
    if (semgid == 0xffffffff)
    {
        perror("error on the down operation for semaphore access (PG)");
        exit(1);
    }
    sh = sh;
    edx = var_4h;
    *((sh + rdx * 4 + 8)) = 2; // estado = 2 -> waitingForBoarding || check_passport || IN_FLIGHT
    sh = sh;
    rsi = sh;
    edi = nFic;
    saveState(); // save state de algum estado = 2
    sh = sh;
    edx = *((sh + 0x9c));
    semgid = semgid;
    edx = edx;
    edi = semgid;
    semgid = semUp();
    if (semgid == 0xffffffff)
    {
        perror("error on the up operation for semaphore access (PG)");
        exit(1);
    }
    sh = sh;
    edx = var_4h;
    *((sh + 0x98)) = edx;
    sh = sh;
    edx = *((sh + 0xb4));
    semgid = semgid;
    edx = edx;
    edi = semgid;
    semUp();
    return sh;
}

int64_t waitUntilDestination(long passengerId)
{
    long var_4h;
    rdi = passengerId;
    var_4h = edi;
    sh = sh;
    edx = *((sh + 0xa8));
    semgid = semgid;
    edx = edx;
    edi = semgid;
    semDown();
    sh = sh;
    edx = *((sh + 0x9c));
    semgid = semgid;
    edx = edx;
    edi = semgid;
    semgid = semDown();
    if (semgid == 0xffffffff)
    {
        perror("error on the down operation for semaphore access (PG)");
        exit(1);
    }
    sh = sh;
    edx = var_4h;
    *((sh + rdx * 4 + 8)) = 3;
    sh = sh;
    edx = *((sh + 0x8c));
    edx--;
    *((sh + 0x8c)) = edx;
    sh = sh;
    rsi = sh;
    edi = nFic;
    saveState();
    sh = sh;
    semgid = *((sh + 0x8c));
    if (semgid == 0)
    {
        sh = sh;
        edx = *((sh + 0xb8));
        semgid = semgid;
        edx = edx;
        edi = semgid;
        semUp();
    }
    sh = sh;
    edx = *((sh + 0x9c));
    semgid = semgid;
    edx = edx;
    edi = semgid;
    semgid = semUp();
    if (semgid == 0xffffffff)
    {
        perror("error on the down operation for semaphore access (PG)");
        exit(1);
    }
    return sh;
}

//  DECOMPILING W GHIDRA

void waitInQueue(long arg1)
{
    int32_t iVar1;
    long var_4h;

    if (semDown(semgid, sh->mutex) == -1)
    {
        perror("error on the down operation for semaphore access (PG)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    sh->fSt.nPassInQueue = sh->fSt.nPassInQueue + 1;
    sh->fSt.st.passengerStat[passengerId] = 1;
    saveState(nFic, &(sh->fSt));

    if (semUp(semgid, sh->mutex) == -1)
    {
        perror("error on the up operation for semaphore access (PG)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    semUp(semgid, (uint64_t) * (uint32_t *)(_sh + 0x14));
    semDown(semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0xa4));

    if (semDown(semgid, sh->mutex) == -1)
    {
        perror("error on the down operation for semaphore access (PG)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    sh->fSt.st.passengerStat[passengerId] = 2; // IN_FLIGHT
    saveState(nFic, &(sh->fSt));

    if (semUp(semgid, sh->mutex) == -1)
    {
        perror("error on the up operation for semaphore access (PG)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    *(int32_t *)(_sh + 0x13) = (int32_t)arg1;
    semUp(semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0xb4));
    return;
}

void waitUntilDestination(long arg1)
{
    int32_t iVar1;
    long var_4h;

    semDown(semgid, (uint64_t) * (uint32_t *)(_sh + 0x15));
    if (semDown(semgid, sh->mutex) == -1)
    {
        perror("error on the down operation for semaphore access (PG)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    sh->fSt.st.passengerStat[passengerId] = 3;
    sh->fSt.nPassInFligh) = sh->fSt.nPassInFligh) + -1;
    saveState((int64_t)nFic, _sh);
    if (sh->fSt.nPassInFligh) == 0)
        {
            semUp(semgid, (uint64_t) * (uint32_t *)(_sh + 0x17));
        }
    if (semUp(semgid, sh->mutex) == -1)
    {
        perror("error on the down operation for semaphore access (PG)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    return;
}

void waitInQueue(long arg1)
{
    int32_t iVar1;
    long var_4h;

    iVar1 = semDown((uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1)
    {
        perror("error on the down operation for semaphore access (PG)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    *(int32_t *)(_sh + 0x11) = *(int32_t *)(_sh + 0x11) + 1;
    *(undefined4 *)((int64_t)_sh + (arg1 & 0xffffffffU) * 4 + 8) = 1;
    saveState((int64_t)nFic, _sh);
    iVar1 = semUp((uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1)
    {
        perror("error on the up operation for semaphore access (PG)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    semUp((uint64_t)_semgid, (uint64_t) * (uint32_t *)(_sh + 0x14));
    semDown((uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0xa4));
    iVar1 = semDown((uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1)
    {
        perror("error on the down operation for semaphore access (PG)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    *(undefined4 *)((int64_t)_sh + (arg1 & 0xffffffffU) * 4 + 8) = 2;
    saveState((int64_t)nFic, _sh);
    iVar1 = semUp((uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0x9c));
    if (iVar1 == -1)
    {
        perror("error on the down operation for semaphore access (PG)");
        // WARNING: Subroutine does not return
        exit(1);
    }
    *(int32_t *)(_sh + 0x13) = (int32_t)arg1;
    semUp((uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0xb4));
    return;
}