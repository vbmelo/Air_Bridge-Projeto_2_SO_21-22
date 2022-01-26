
int64_t __gmon_start__ = 0;

void fun_400c00();

void _init() {
    int64_t rax1;

    rax1 = __gmon_start__;
    if (rax1) {
        fun_400c00();
    }
    return;
}

void fun_400c00() {
    goto __gmon_start__;
}

int64_t __libc_start_main = 0x400b06;

void fun_400b00(int64_t rdi, int64_t rsi, void* rdx, int64_t rcx, int64_t r8, int64_t r9, void** a7, int64_t a8) {
    goto __libc_start_main;
}

int64_t deregister_tm_clones() {
    int64_t rax1;

    rax1 = 7;
    if (1 || (*reinterpret_cast<int32_t*>(&rax1) = 0, *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax1) + 4) = 0, 1)) {
        return rax1;
    } else {
        goto 0;
    }
}

struct s0 {
    int32_t f0;
    int32_t f4;
};

int64_t freopen = 0x400ae6;

void fun_400ae0(int64_t rdi, int64_t rsi, struct s0* rdx) {
    goto freopen;
}

struct s1 {
    int32_t f0;
    int32_t f4;
    signed char[124] pad132;
    int32_t f132;
    int32_t f136;
    int32_t f140;
    int32_t f144;
    unsigned char f148;
    signed char[7] pad156;
    int32_t f156;
    signed char[8] pad168;
    int32_t f168;
    int32_t f172;
    int32_t f176;
    signed char[4] pad184;
    int32_t f184;
};

int64_t fwrite = 0x400be6;

void fun_400be0(struct s1* rdi, struct s0* rsi, uint64_t rdx, struct s0* rcx) {
    goto fwrite;
}

int64_t perror = 0x400b76;

void fun_400b70(struct s1* rdi, struct s0* rsi, ...) {
    goto perror;
}

int32_t fun_400aa0(struct s1* rdi);

int32_t shmemDettach(struct s1* rdi, struct s0* rsi, uint64_t rdx) {
    int32_t eax4;

    eax4 = fun_400aa0(rdi);
    return eax4;
}

int64_t __stack_chk_fail = 0x400ad6;

int64_t fun_400ad0(struct s1* rdi, struct s0* rsi, uint64_t rdx) {
    goto __stack_chk_fail;
}

struct s1* sh = reinterpret_cast<struct s1*>(0);

uint32_t isFinished(int64_t rdi, struct s0* rsi, uint64_t rdx) {
    struct s1* rax4;

    rax4 = sh;
    return static_cast<uint32_t>(rax4->f148);
}

struct s2 {
    int32_t f0;
    int32_t f4;
};

int64_t exit = 0x400bd6;

void fun_400bd0(struct s2* rdi, struct s0* rsi) {
    goto exit;
}

int64_t random = 0x400b36;

void fun_400b30() {
    goto random;
}

int64_t floor = 0x400ba6;

int32_t fun_400ba0(int64_t rdi, int64_t rsi) {
    goto floor;
}

int64_t usleep = 0x400bf6;

void fun_400bf0(int64_t rdi, int64_t rsi) {
    goto usleep;
}

int32_t semgid = 0;

int32_t semDown(int32_t edi, int32_t esi);

void saveState(unsigned char* rdi, struct s1* rsi);

void saveStartBoarding(unsigned char* rdi, struct s1* rsi);

int32_t semUp(int32_t edi, int32_t esi);

void signalReadyForBoarding(int64_t rdi, struct s0* rsi, uint64_t rdx) {
    struct s1* rax4;
    int32_t eax5;
    struct s0* rsi6;
    int32_t eax7;
    struct s1* rax8;
    struct s1* rax9;
    struct s1* rax10;
    struct s1* rax11;
    struct s1* rax12;
    int32_t eax13;
    struct s0* rsi14;
    int32_t eax15;
    struct s1* rax16;
    int32_t eax17;
    struct s0* rsi18;
    int32_t eax19;

    rax4 = sh;
    eax5 = semgid;
    *reinterpret_cast<int32_t*>(&rsi6) = rax4->f156;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi6) + 4) = 0;
    eax7 = semDown(eax5, *reinterpret_cast<int32_t*>(&rsi6));
    if (eax7 == -1) {
        fun_400b70("error on the up operation for semaphore access (PT)", rsi6);
        fun_400bd0(1, rsi6);
    }
    rax8 = sh;
    rax8->f0 = 1;
    rax9 = sh;
    rax9->f132 = rax9->f132 + 1;
    rax10 = sh;
    saveState(0x603140, rax10);
    rax11 = sh;
    saveStartBoarding(0x603140, rax11);
    rax12 = sh;
    eax13 = semgid;
    *reinterpret_cast<int32_t*>(&rsi14) = rax12->f156;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi14) + 4) = 0;
    eax15 = semUp(eax13, *reinterpret_cast<int32_t*>(&rsi14));
    if (eax15 == -1) {
        fun_400b70("error on the up operation for semaphore access (PT)", rsi14);
        fun_400bd0(1, rsi14);
    }
    rax16 = sh;
    eax17 = semgid;
    *reinterpret_cast<int32_t*>(&rsi18) = rax16->f172;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi18) + 4) = 0;
    eax19 = semUp(eax17, *reinterpret_cast<int32_t*>(&rsi18));
    if (eax19 == -1) {
        fun_400b70("error on the up operation for semaphore access (PT)", rsi18);
        fun_400bd0(1, rsi18);
    }
    return;
}

struct s0* openLog(unsigned char* rdi, struct s0* rsi);

void fun_400b10(struct s0* rdi, struct s0* rsi, int64_t rdx, struct s0* rcx);

void fun_400af0(int64_t rdi, struct s0* rsi, int64_t rdx, struct s0* rcx);

void closeLog(struct s0* rdi, struct s0* rsi, ...);

void saveState(unsigned char* rdi, struct s1* rsi) {
    struct s1* v3;
    struct s0* rax4;
    struct s0* v5;
    int64_t rdx6;
    struct s0* rcx7;
    int64_t rdx8;
    struct s0* rcx9;
    struct s0* rcx10;
    int32_t v11;
    struct s0* rcx12;
    struct s0* rcx13;
    int64_t rdx14;
    struct s0* rcx15;
    int64_t rdx16;
    struct s0* rcx17;
    int64_t rdx18;
    struct s0* rcx19;
    struct s0* rcx20;

    v3 = rsi;
    rax4 = openLog(rdi, "a");
    v5 = rax4;
    *reinterpret_cast<int32_t*>(&rdx6) = v3->f0;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx6) + 4) = 0;
    fun_400b10(v5, "%3d", rdx6, rcx7);
    *reinterpret_cast<int32_t*>(&rdx8) = v3->f4;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx8) + 4) = 0;
    fun_400b10(v5, "%3d", rdx8, rcx9);
    fun_400af0(32, v5, rdx8, rcx10);
    v11 = 0;
    while (v11 <= 20) {
        *reinterpret_cast<int32_t*>(&rdx8) = *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(v3) + v11 * 4 + 8);
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx8) + 4) = 0;
        fun_400b10(v5, "%4d", rdx8, rcx12);
        ++v11;
    }
    fun_400af0(32, v5, rdx8, rcx13);
    *reinterpret_cast<int32_t*>(&rdx14) = v3->f136;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx14) + 4) = 0;
    fun_400b10(v5, "%4d", rdx14, rcx15);
    *reinterpret_cast<int32_t*>(&rdx16) = v3->f140;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx16) + 4) = 0;
    fun_400b10(v5, "%4d", rdx16, rcx17);
    *reinterpret_cast<int32_t*>(&rdx18) = v3->f144;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx18) + 4) = 0;
    fun_400b10(v5, "%4d", rdx18, rcx19);
    fun_400af0(10, v5, rdx18, rcx20);
    closeLog(v5, v5, v5, v5);
    return;
}

void printHeader(struct s0* rdi, struct s0* rsi, int64_t rdx, struct s0* rcx);

void saveStartBoarding(unsigned char* rdi, struct s1* rsi) {
    struct s0* rax3;
    int64_t rdx4;
    struct s0* rcx5;
    struct s0* rcx6;

    rax3 = openLog(rdi, "a");
    *reinterpret_cast<int32_t*>(&rdx4) = rsi->f132;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx4) + 4) = 0;
    fun_400b10(rax3, "Flight %d : Boarding Started\n", rdx4, rcx5);
    printHeader(rax3, "Flight %d : Boarding Started\n", rdx4, rcx6);
    closeLog(rax3, "Flight %d : Boarding Started\n", rax3, "Flight %d : Boarding Started\n");
    return;
}

uint64_t g28;

int64_t fun_400bc0(struct s1* rdi, struct s0* rsi, int64_t rdx);

int32_t semUp(int32_t edi, int32_t esi) {
    uint64_t rax3;
    struct s0* rsi4;
    struct s1* rdi5;
    int64_t rax6;
    uint64_t rdx7;

    rax3 = g28;
    rsi4 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8 - 16);
    *reinterpret_cast<int32_t*>(&rdi5) = edi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi5) + 4) = 0;
    rax6 = fun_400bc0(rdi5, rsi4, 1);
    rdx7 = rax3 ^ g28;
    if (rdx7) {
        rax6 = fun_400ad0(rdi5, rsi4, rdx7);
    }
    return *reinterpret_cast<int32_t*>(&rax6);
}

void waitUntilReadyToFlight(int64_t rdi, struct s0* rsi, uint64_t rdx) {
    struct s1* rax4;
    int32_t eax5;
    struct s0* rsi6;
    int32_t eax7;
    struct s1* rax8;
    struct s1* rax9;
    struct s1* rax10;
    int32_t eax11;
    struct s0* rsi12;
    int32_t eax13;
    struct s1* rax14;
    int32_t eax15;
    struct s0* rsi16;
    int32_t eax17;

    rax4 = sh;
    eax5 = semgid;
    *reinterpret_cast<int32_t*>(&rsi6) = rax4->f156;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi6) + 4) = 0;
    eax7 = semDown(eax5, *reinterpret_cast<int32_t*>(&rsi6));
    if (eax7 == -1) {
        fun_400b70("error on the up operation for semaphore access (PT)", rsi6);
        fun_400bd0(1, rsi6);
    }
    rax8 = sh;
    rax8->f0 = 2;
    rax9 = sh;
    saveState(0x603140, rax9);
    rax10 = sh;
    eax11 = semgid;
    *reinterpret_cast<int32_t*>(&rsi12) = rax10->f156;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi12) + 4) = 0;
    eax13 = semUp(eax11, *reinterpret_cast<int32_t*>(&rsi12));
    if (eax13 == -1) {
        fun_400b70("error on the up operation for semaphore access (PT)", rsi12);
        fun_400bd0(1, rsi12);
    }
    rax14 = sh;
    eax15 = semgid;
    *reinterpret_cast<int32_t*>(&rsi16) = rax14->f176;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi16) + 4) = 0;
    eax17 = semDown(eax15, *reinterpret_cast<int32_t*>(&rsi16));
    if (eax17 == -1) {
        fun_400b70("error on the down operation for semaphore readyToFLight (PT)", rsi16);
        fun_400bd0(1, rsi16);
    }
    return;
}

void saveFlightArrived(unsigned char* rdi, struct s1* rsi);

void saveFlightReturning(unsigned char* rdi, struct s1* rsi);

void dropPassengersAtTarget(int64_t rdi, struct s0* rsi, uint64_t rdx) {
    struct s1* rax4;
    int32_t eax5;
    struct s0* rsi6;
    int32_t eax7;
    struct s1* rax8;
    struct s1* rax9;
    struct s1* rax10;
    struct s1* rax11;
    int32_t v12;
    struct s1* rax13;
    int32_t eax14;
    int32_t esi15;
    struct s1* rax16;
    int32_t eax17;
    struct s0* rsi18;
    int32_t eax19;
    struct s1* rax20;
    int32_t eax21;
    int32_t esi22;
    struct s1* rax23;
    int32_t eax24;
    struct s0* rsi25;
    int32_t eax26;
    struct s1* rax27;
    struct s1* rax28;
    int32_t eax29;
    struct s0* rsi30;
    int32_t eax31;

    rax4 = sh;
    eax5 = semgid;
    *reinterpret_cast<int32_t*>(&rsi6) = rax4->f156;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi6) + 4) = 0;
    eax7 = semDown(eax5, *reinterpret_cast<int32_t*>(&rsi6));
    if (eax7 == -1) {
        fun_400b70("error on the down operation for semaphore access (PT)", rsi6);
        fun_400bd0(1, rsi6);
    }
    rax8 = sh;
    saveFlightArrived(0x603140, rax8);
    rax9 = sh;
    rax9->f0 = 4;
    rax10 = sh;
    saveState(0x603140, rax10);
    rax11 = sh;
    v12 = rax11->f140;
    while (v12 > 0) {
        rax13 = sh;
        eax14 = semgid;
        esi15 = rax13->f168;
        semUp(eax14, esi15);
        --v12;
    }
    rax16 = sh;
    eax17 = semgid;
    *reinterpret_cast<int32_t*>(&rsi18) = rax16->f156;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi18) + 4) = 0;
    eax19 = semUp(eax17, *reinterpret_cast<int32_t*>(&rsi18));
    if (eax19 == -1) {
        fun_400b70("error on the up operation for semaphore access (PT)", rsi18);
        fun_400bd0(1, rsi18);
    }
    rax20 = sh;
    eax21 = semgid;
    esi22 = rax20->f184;
    semDown(eax21, esi22);
    rax23 = sh;
    eax24 = semgid;
    *reinterpret_cast<int32_t*>(&rsi25) = rax23->f156;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi25) + 4) = 0;
    eax26 = semDown(eax24, *reinterpret_cast<int32_t*>(&rsi25));
    if (eax26 == -1) {
        fun_400b70("error on the down operation for semaphore access (PT)", rsi25);
        fun_400bd0(1, rsi25);
    }
    rax27 = sh;
    saveFlightReturning(0x603140, rax27);
    rax28 = sh;
    eax29 = semgid;
    *reinterpret_cast<int32_t*>(&rsi30) = rax28->f156;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi30) + 4) = 0;
    eax31 = semUp(eax29, *reinterpret_cast<int32_t*>(&rsi30));
    if (eax31 == -1) {
        fun_400b70("error on the up operation for semaphore access (PT)", rsi30);
        fun_400bd0(1, rsi30);
    }
    return;
}

void saveFlightArrived(unsigned char* rdi, struct s1* rsi) {
    struct s0* rax3;
    int64_t rdx4;
    struct s0* rcx5;
    struct s0* rcx6;

    rax3 = openLog(rdi, "a");
    *reinterpret_cast<int32_t*>(&rdx4) = rsi->f132;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx4) + 4) = 0;
    fun_400b10(rax3, "Flight %d : Arrived \n", rdx4, rcx5);
    printHeader(rax3, "Flight %d : Arrived \n", rdx4, rcx6);
    closeLog(rax3, "Flight %d : Arrived \n", rax3, "Flight %d : Arrived \n");
    return;
}

void saveFlightReturning(unsigned char* rdi, struct s1* rsi) {
    struct s0* rax3;
    int64_t rdx4;
    struct s0* rcx5;
    struct s0* rcx6;

    rax3 = openLog(rdi, "a");
    *reinterpret_cast<int32_t*>(&rdx4) = rsi->f132;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx4) + 4) = 0;
    fun_400b10(rax3, "Flight %d : Returning \n", rdx4, rcx5);
    printHeader(rax3, "Flight %d : Returning \n", rdx4, rcx6);
    closeLog(rax3, "Flight %d : Returning \n", rax3, "Flight %d : Returning \n");
    return;
}

int32_t semDown(int32_t edi, int32_t esi) {
    uint64_t rax3;
    struct s0* rsi4;
    struct s1* rdi5;
    int64_t rax6;
    uint64_t rdx7;

    rax3 = g28;
    rsi4 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8 - 16);
    *reinterpret_cast<int32_t*>(&rdi5) = edi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi5) + 4) = 0;
    rax6 = fun_400bc0(rdi5, rsi4, 1);
    rdx7 = rax3 ^ g28;
    if (rdx7) {
        rax6 = fun_400ad0(rdi5, rsi4, rdx7);
    }
    return *reinterpret_cast<int32_t*>(&rax6);
}

struct s0* stdout = reinterpret_cast<struct s0*>(0);

struct s0* fun_400b60(unsigned char* rdi, struct s0* rsi);

struct s0* openLog(unsigned char* rdi, struct s0* rsi) {
    uint32_t eax3;
    struct s0* rax4;
    struct s0* rax5;

    if (!rdi || (eax3 = *rdi, !*reinterpret_cast<signed char*>(&eax3))) {
        rax4 = stdout;
    } else {
        rax5 = fun_400b60(rdi, rsi);
        if (!rax5) {
            fun_400b70("error on opening log file", rsi);
            fun_400bd0(1, rsi);
        }
        rax4 = rax5;
    }
    return rax4;
}

int64_t fflush = 0x400b46;

void fun_400b40(struct s0* rdi) {
    goto fflush;
}

int64_t fputc = 0x400af6;

void fun_400af0(int64_t rdi, struct s0* rsi, int64_t rdx, struct s0* rcx) {
    goto fputc;
}

int64_t fprintf = 0x400b16;

void fun_400b10(struct s0* rdi, struct s0* rsi, int64_t rdx, struct s0* rcx) {
    goto fprintf;
}

struct s0* stderr = reinterpret_cast<struct s0*>(0);

int32_t fun_400ac0(struct s0* rdi);

void closeLog(struct s0* rdi, struct s0* rsi, ...) {
    struct s0* rax3;
    struct s0* rax4;
    int32_t eax5;

    rax3 = stderr;
    if (rdi == rax3 || (rax4 = stdout, rdi == rax4)) {
        fun_400b40(rdi);
    } else {
        eax5 = fun_400ac0(rdi);
        if (eax5 == -1) {
            fun_400b70("error on closing of log file", rsi);
            fun_400bd0(1, rsi);
        }
    }
    return;
}

int64_t strcpy = 0x400a96;

void fun_400a90(int64_t rdi, int64_t rsi, struct s0* rdx) {
    goto strcpy;
}

int64_t strtol = 0x400b26;

int32_t fun_400b20(int64_t rdi, struct s0* rsi, uint64_t rdx) {
    goto strtol;
}

int32_t fun_400a70(struct s1* rdi, struct s0* rsi, int64_t rdx);

int32_t semConnect(int32_t edi, struct s0* rsi, uint64_t rdx) {
    uint64_t rax4;
    struct s0* rsi5;
    struct s1* rdi6;
    int32_t eax7;
    int64_t rax8;
    int64_t rax9;
    uint64_t rdx10;

    rax4 = g28;
    *reinterpret_cast<int32_t*>(&rsi5) = 1;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi5) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rdi6) = edi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi6) + 4) = 0;
    eax7 = fun_400a70(rdi6, 1, 0x180);
    if (eax7 != -1) {
        rsi5 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8 - 32);
        *reinterpret_cast<int32_t*>(&rdi6) = eax7;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi6) + 4) = 0;
        rax8 = fun_400bc0(rdi6, rsi5, 2);
        if (*reinterpret_cast<int32_t*>(&rax8) != -1) {
            *reinterpret_cast<int32_t*>(&rax9) = eax7;
        } else {
            *reinterpret_cast<int32_t*>(&rax9) = -1;
        }
    } else {
        *reinterpret_cast<int32_t*>(&rax9) = -1;
    }
    rdx10 = rax4 ^ g28;
    if (rdx10) {
        rax9 = fun_400ad0(rdi6, rsi5, rdx10);
    }
    return *reinterpret_cast<int32_t*>(&rax9);
}

int32_t fun_400bb0(int64_t rdi, int64_t rsi, int64_t rdx);

int32_t shmemConnect(int32_t edi, struct s0* rsi, uint64_t rdx) {
    int64_t rdi4;
    int32_t eax5;

    *reinterpret_cast<int32_t*>(&rdi4) = edi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi4) + 4) = 0;
    eax5 = fun_400bb0(rdi4, 1, 0x180);
    return eax5;
}

int32_t fun_400b90(int64_t rdi, int64_t rsi, int64_t rdx);

int32_t shmemAttach(int32_t edi, struct s0* rsi, uint64_t rdx) {
    int64_t rdi4;
    int32_t rax5;
    int32_t eax6;

    *reinterpret_cast<int32_t*>(&rdi4) = edi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi4) + 4) = 0;
    rax5 = fun_400b90(rdi4, 0, 0);
    if (rax5 == -1) {
        eax6 = 1;
    } else {
        rsi->f0 = rax5;
        eax6 = 0;
    }
    return eax6;
}

int64_t getpid = 0x400ab6;

int32_t fun_400ab0(int64_t rdi, struct s0* rsi, uint64_t rdx) {
    goto getpid;
}

int64_t srandom = 0x400a86;

void fun_400a80(int64_t rdi, struct s0* rsi, uint64_t rdx) {
    goto srandom;
}

int64_t shmdt = 0x400aa6;

int32_t fun_400aa0(struct s1* rdi) {
    goto shmdt;
}

struct s3 {
    int32_t f0;
    int32_t f4;
};

struct s4 {
    int32_t f0;
    int32_t f4;
};

void flight(int32_t edi, struct s0* rsi, uint64_t rdx) {
    int32_t eax4;
    struct s1* rax5;
    int32_t eax6;
    struct s0* rsi7;
    int32_t eax8;
    struct s1* rax9;
    struct s1* rax10;
    struct s1* rax11;
    struct s1* rax12;
    int32_t eax13;
    struct s0* rsi14;
    struct s2* rdi15;
    int32_t eax16;
    struct s3* rdi17;
    struct s4* rsi18;
    int32_t* rdi19;
    int32_t* rsi20;
    int64_t rsi21;
    int32_t eax22;
    int64_t rdi23;

    eax4 = edi;
    rax5 = sh;
    eax6 = semgid;
    *reinterpret_cast<int32_t*>(&rsi7) = rax5->f156;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi7) + 4) = 0;
    eax8 = semDown(eax6, *reinterpret_cast<int32_t*>(&rsi7));
    if (eax8 == -1) {
        fun_400b70("error on the up operation for semaphore access (PT)", rsi7);
        fun_400bd0(1, rsi7);
    }
    if (!*reinterpret_cast<signed char*>(&eax4)) {
        rax9 = sh;
        rax9->f0 = 0;
    } else {
        rax10 = sh;
        rax10->f0 = 3;
    }
    rax11 = sh;
    saveState(0x603140, rax11);
    rax12 = sh;
    eax13 = semgid;
    *reinterpret_cast<int32_t*>(&rsi14) = rax12->f156;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi14) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rdi15) = eax13;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi15) + 4) = 0;
    eax16 = semUp(*reinterpret_cast<int32_t*>(&rdi15), *reinterpret_cast<int32_t*>(&rsi14));
    if (eax16 == -1) {
        fun_400b70("error on the up operation for semaphore access (PT)", rsi14);
        *reinterpret_cast<int32_t*>(&rdi15) = 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi15) + 4) = 0;
        fun_400bd0(1, rsi14);
    }
    fun_400b30();
    __asm__("pxor xmm0, xmm0");
    __asm__("cvtsi2sd xmm0, rax");
    rdi15->f0 = rsi14->f0;
    rdi17 = reinterpret_cast<struct s3*>(&rdi15->f4);
    rsi18 = reinterpret_cast<struct s4*>(&rsi14->f4);
    __asm__("mulsd xmm0, xmm1");
    rdi17->f0 = rsi18->f0;
    rdi19 = &rdi17->f4;
    rsi20 = &rsi18->f4;
    __asm__("divsd xmm0, xmm1");
    *rdi19 = *rsi20;
    rsi21 = reinterpret_cast<int64_t>(rsi20 + 1);
    __asm__("addsd xmm0, xmm1");
    eax22 = fun_400ba0(rdi19 + 1, rsi21);
    __asm__("cvttsd2si rax, xmm0");
    *reinterpret_cast<int32_t*>(&rdi23) = eax22;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi23) + 4) = 0;
    fun_400bf0(rdi23, rsi21);
    return;
}

void printHeader(struct s0* rdi, struct s0* rsi, int64_t rdx, struct s0* rcx) {
    struct s0* v5;
    int64_t rdx6;
    int32_t v7;

    v5 = rdi;
    fun_400b10(v5, "%3s", "PT", rcx);
    *reinterpret_cast<int32_t*>(&rdx6) = reinterpret_cast<int32_t>("HT");
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx6) + 4) = 0;
    fun_400b10(v5, "%3s", "HT", rcx);
    fun_400af0(32, v5, "HT", rcx);
    v7 = 0;
    while (v7 <= 20) {
        *reinterpret_cast<int32_t*>(&rcx) = v7;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx) + 4) = 0;
        *reinterpret_cast<int32_t*>(&rdx6) = reinterpret_cast<int32_t>("P");
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx6) + 4) = 0;
        fun_400b10(v5, " %s%02d", "P", rcx);
        ++v7;
    }
    fun_400af0(32, v5, rdx6, rcx);
    fun_400b10(v5, "%4s", "InQ", rcx);
    fun_400b10(v5, "%4s", "InF", rcx);
    fun_400b10(v5, "%4s", "toB", rcx);
    fun_400af0(10, v5, "toB", rcx);
    return;
}

int64_t semop = 0x400bc6;

int64_t fun_400bc0(struct s1* rdi, struct s0* rsi, int64_t rdx) {
    goto semop;
}

int64_t semctl = 0x400b86;

void fun_400b80(int64_t rdi, int64_t rsi, int64_t rdx, int64_t rcx) {
    goto semctl;
}

int64_t fopen = 0x400b66;

struct s0* fun_400b60(unsigned char* rdi, struct s0* rsi) {
    goto fopen;
}

int64_t fclose = 0x400ac6;

int32_t fun_400ac0(struct s0* rdi) {
    goto fclose;
}

int64_t semget = 0x400a76;

int32_t fun_400a70(struct s1* rdi, struct s0* rsi, int64_t rdx) {
    goto semget;
}

int64_t shmget = 0x400bb6;

int32_t fun_400bb0(int64_t rdi, int64_t rsi, int64_t rdx) {
    goto shmget;
}

int64_t shmat = 0x400b96;

int32_t fun_400b90(int64_t rdi, int64_t rsi, int64_t rdx) {
    goto shmat;
}

int64_t shmctl = 0x400b56;

void fun_400b50(int64_t rdi, int64_t rsi, int64_t rdx) {
    goto shmctl;
}

struct s5 {
    signed char[8] pad8;
    int64_t f8;
    int64_t f16;
    int64_t f24;
};

int64_t main(int32_t edi, struct s5* rsi);

void __libc_csu_init(int32_t edi, int64_t rsi, int64_t rdx);

void __libc_csu_fini();

void _start() {
    void* rsp1;
    int64_t rdx2;
    int64_t rax3;

    rsp1 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) + 8);
    fun_400b00(main, __return_address(), rsp1, __libc_csu_init, __libc_csu_fini, rdx2, (reinterpret_cast<uint64_t>(rsp1) & 0xfffffffffffffff0) - 8 - 8, rax3);
    __asm__("hlt ");
}

void _fini() {
    return;
}

void fun_400cb5() {
    int64_t v1;

    goto v1;
}

int64_t __JCR_END__ = 0;

void usleep();

void frame_dummy() {
    int1_t zf1;

    zf1 = __JCR_END__ == 0;
    if (!(zf1 || 1)) {
        usleep();
    }
    if (1) 
        goto 0x400cb8;
    if (1) 
        goto 0x400cb8;
    goto 0;
}

int32_t shmid = 0;

int64_t main(int32_t edi, struct s5* rsi) {
    uint64_t rax3;
    uint64_t v4;
    struct s0* rdx5;
    int64_t rdi6;
    int64_t rsi7;
    uint64_t rdx8;
    struct s0* rsi9;
    int64_t rdi10;
    int32_t eax11;
    uint32_t eax12;
    unsigned char* v13;
    int32_t eax14;
    int32_t eax15;
    int32_t eax16;
    int32_t eax17;
    int32_t eax18;
    int64_t rdi19;
    int32_t eax20;
    int32_t eax21;
    int64_t rdi22;
    uint32_t eax23;
    uint32_t eax24;
    struct s1* rax25;
    struct s1* rdi26;
    int32_t eax27;
    int64_t rax28;
    struct s0* rax29;
    struct s0* rax30;
    struct s0* rax31;
    uint64_t rcx32;

    rax3 = g28;
    v4 = rax3;
    if (edi == 4) {
        rdx5 = stderr;
        rdi6 = rsi->f24;
        fun_400ae0(rdi6, "w", rdx5);
        rsi7 = rsi->f8;
        fun_400a90(0x603140, rsi7, rdx5);
        *reinterpret_cast<int32_t*>(&rdx8) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx8) + 4) = 0;
        rsi9 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8 - 16);
        rdi10 = rsi->f16;
        eax11 = fun_400b20(rdi10, rsi9, 0);
        eax12 = *v13;
        if (!*reinterpret_cast<signed char*>(&eax12)) {
            eax14 = semConnect(eax11, rsi9, 0);
            semgid = eax14;
            eax15 = semgid;
            if (eax15 != -1) {
                eax16 = shmemConnect(eax11, rsi9, 0);
                shmid = eax16;
                eax17 = shmid;
                if (eax17 != -1) {
                    eax18 = shmid;
                    *reinterpret_cast<int32_t*>(&rsi9) = 0x603180;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi9) + 4) = 0;
                    *reinterpret_cast<int32_t*>(&rdi19) = eax18;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi19) + 4) = 0;
                    eax20 = shmemAttach(*reinterpret_cast<int32_t*>(&rdi19), 0x603180, 0);
                    if (eax20 != -1) {
                        eax21 = fun_400ab0(rdi19, 0x603180, 0);
                        *reinterpret_cast<int32_t*>(&rdi22) = eax21;
                        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi22) + 4) = 0;
                        fun_400a80(rdi22, 0x603180, 0);
                        while (eax23 = isFinished(rdi22, 0x603180, 0), eax24 = eax23 ^ 1, !!*reinterpret_cast<signed char*>(&eax24)) {
                            flight(0, 0x603180, 0);
                            signalReadyForBoarding(0, 0x603180, 0);
                            waitUntilReadyToFlight(0, 0x603180, 0);
                            *reinterpret_cast<int32_t*>(&rdi22) = 1;
                            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi22) + 4) = 0;
                            flight(1, 0x603180, 0);
                            dropPassengersAtTarget(1, 0x603180, 0);
                        }
                        rax25 = sh;
                        rdi26 = rax25;
                        eax27 = shmemDettach(rdi26, 0x603180, 0);
                        if (eax27 == -1) 
                            goto addr_400ee2_10;
                    } else {
                        *reinterpret_cast<int32_t*>(&rdi26) = reinterpret_cast<int32_t>("error on mapping the shared region on the process address space");
                        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi26) + 4) = 0;
                        fun_400b70("error on mapping the shared region on the process address space", 0x603180, "error on mapping the shared region on the process address space", 0x603180);
                        *reinterpret_cast<int32_t*>(&rax28) = 1;
                        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax28) + 4) = 0;
                        goto addr_400ef8_12;
                    }
                } else {
                    *reinterpret_cast<int32_t*>(&rdi26) = reinterpret_cast<int32_t>("error on connecting to the shared memory region");
                    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi26) + 4) = 0;
                    fun_400b70("error on connecting to the shared memory region", rsi9, "error on connecting to the shared memory region", rsi9);
                    *reinterpret_cast<int32_t*>(&rax28) = 1;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax28) + 4) = 0;
                    goto addr_400ef8_12;
                }
            } else {
                *reinterpret_cast<int32_t*>(&rdi26) = reinterpret_cast<int32_t>("error on connecting to the semaphore set");
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi26) + 4) = 0;
                fun_400b70("error on connecting to the semaphore set", rsi9, "error on connecting to the semaphore set", rsi9);
                *reinterpret_cast<int32_t*>(&rax28) = 1;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax28) + 4) = 0;
                goto addr_400ef8_12;
            }
        } else {
            rax29 = stderr;
            *reinterpret_cast<int32_t*>(&rdx8) = 39;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx8) + 4) = 0;
            *reinterpret_cast<int32_t*>(&rsi9) = 1;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi9) + 4) = 0;
            *reinterpret_cast<int32_t*>(&rdi26) = reinterpret_cast<int32_t>("Error on the access key communication!\n");
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi26) + 4) = 0;
            fun_400be0("Error on the access key communication!\n", 1, 39, rax29);
            *reinterpret_cast<int32_t*>(&rax28) = 1;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax28) + 4) = 0;
            goto addr_400ef8_12;
        }
    } else {
        rax30 = stderr;
        fun_400ae0("error_PT", "a", rax30);
        rax31 = stderr;
        *reinterpret_cast<int32_t*>(&rdx8) = 35;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx8) + 4) = 0;
        *reinterpret_cast<int32_t*>(&rsi9) = 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi9) + 4) = 0;
        *reinterpret_cast<int32_t*>(&rdi26) = reinterpret_cast<int32_t>("Number of parameters is incorrect!\n");
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi26) + 4) = 0;
        fun_400be0("Number of parameters is incorrect!\n", 1, 35, rax31);
        *reinterpret_cast<int32_t*>(&rax28) = 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax28) + 4) = 0;
        goto addr_400ef8_12;
    }
    *reinterpret_cast<int32_t*>(&rax28) = 0;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax28) + 4) = 0;
    addr_400ef8_12:
    rcx32 = v4 ^ g28;
    if (rcx32) {
        rax28 = fun_400ad0(rdi26, rsi9, rdx8);
    }
    return rax28;
    addr_400ee2_10:
    *reinterpret_cast<int32_t*>(&rdi26) = reinterpret_cast<int32_t>("error on unmapping the shared region off the process address space");
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi26) + 4) = 0;
    fun_400b70("error on unmapping the shared region off the process address space", 0x603180, "error on unmapping the shared region off the process address space", 0x603180);
    *reinterpret_cast<int32_t*>(&rax28) = 1;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax28) + 4) = 0;
    goto addr_400ef8_12;
}

void semDestroy(int32_t edi) {
    int64_t rdi2;

    *reinterpret_cast<int32_t*>(&rdi2) = edi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi2) + 4) = 0;
    fun_400b80(rdi2, 0, 0, 0);
    return;
}

void createLog(unsigned char* rdi) {
    struct s0* rax2;
    struct s0* rcx3;
    struct s0* rcx4;

    rax2 = openLog(rdi, "w");
    fun_400b10(rax2, "%31cAir Lift - Description of the internal state\n\n", 32, rcx3);
    printHeader(rax2, "%31cAir Lift - Description of the internal state\n\n", 32, rcx4);
    closeLog(rax2, "%31cAir Lift - Description of the internal state\n\n", rax2, "%31cAir Lift - Description of the internal state\n\n");
    return;
}

void __libc_csu_init(int32_t edi, int64_t rsi, int64_t rdx) {
    int32_t r15d4;
    int64_t r14_5;
    int64_t r13_6;
    int64_t rbx7;
    int64_t rdi8;

    r15d4 = edi;
    r14_5 = rsi;
    r13_6 = rdx;
    _init();
    if (!0) {
        *reinterpret_cast<int32_t*>(&rbx7) = 0;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx7) + 4) = 0;
        do {
            *reinterpret_cast<int32_t*>(&rdi8) = r15d4;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi8) + 4) = 0;
            *reinterpret_cast<int64_t*>(0x602e00 + rbx7 * 8)(rdi8, r14_5, r13_6);
            ++rbx7;
        } while (rbx7 != 1);
    }
    return;
}

void __libc_csu_fini() {
    return;
}

int64_t g603010 = 0;

void fun_400a76() {
    goto g603010;
}

void fun_400b06() {
    goto 0x400a60;
}

/* completed.7594 */
signed char completed_7594 = 0;

int64_t __do_global_dtors_aux() {
    int1_t zf1;
    int64_t rax2;

    zf1 = completed_7594 == 0;
    if (zf1) {
        rax2 = deregister_tm_clones();
        completed_7594 = 1;
    }
    return rax2;
}

void fun_400ae6() {
    goto 0x400a60;
}

void fun_400be6() {
    goto 0x400a60;
}

void fun_400b76() {
    goto 0x400a60;
}

int32_t semCreate(int32_t edi, int32_t esi) {
    struct s0* rsi3;
    struct s1* rdi4;
    int32_t eax5;

    *reinterpret_cast<int32_t*>(&rsi3) = esi + 1;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi3) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rdi4) = edi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi4) + 4) = 0;
    eax5 = fun_400a70(rdi4, rsi3, 0x780);
    return eax5;
}

void fun_400ad6() {
    goto 0x400a60;
}

void fun_400bd6() {
    goto 0x400a60;
}

void fun_400b36() {
    goto 0x400a60;
}

void fun_400ba6() {
    goto 0x400a60;
}

void fun_400bf6() {
    goto 0x400a60;
}

struct s6 {
    signed char[132] pad132;
    int32_t f132;
    signed char[16] pad152;
    int32_t f152;
};

void savePassengerChecked(unsigned char* rdi, struct s6* rsi) {
    struct s0* rax3;
    struct s0* rcx4;
    int64_t rdx5;

    rax3 = openLog(rdi, "a");
    *reinterpret_cast<int32_t*>(&rcx4) = rsi->f152;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx4) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rdx5) = rsi->f132;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx5) + 4) = 0;
    fun_400b10(rax3, "Flight %d : Passenger %d checked\n", rdx5, rcx4);
    closeLog(rax3, "Flight %d : Passenger %d checked\n", rax3, "Flight %d : Passenger %d checked\n");
    return;
}

struct s7 {
    signed char[132] pad132;
    uint32_t f132;
};

void saveAirLiftResult(unsigned char* rdi, struct s7* rsi) {
    struct s7* v3;
    struct s0* rax4;
    struct s0* v5;
    int64_t rdx6;
    struct s0* rsi7;
    uint32_t v8;
    int64_t rax9;
    struct s0* rcx10;
    int64_t rdx11;

    v3 = rsi;
    rax4 = openLog(rdi, "a");
    v5 = rax4;
    fun_400be0("AirLift result\n", 1, 15, v5);
    *reinterpret_cast<uint32_t*>(&rdx6) = v3->f132;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx6) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("AirLift used %d Flights\n");
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi7) + 4) = 0;
    fun_400b10(v5, "AirLift used %d Flights\n", rdx6, v5);
    v8 = 0;
    while (v3->f132 > v8) {
        *reinterpret_cast<uint32_t*>(&rax9) = v8;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax9) + 4) = 0;
        *reinterpret_cast<int32_t*>(&rcx10) = *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(v3) + (v8 + 20) * 4 + 12);
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx10) + 4) = 0;
        *reinterpret_cast<int32_t*>(&rdx11) = static_cast<int32_t>(rax9 + 1);
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx11) + 4) = 0;
        *reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("Flight %d took %2d passengers\n");
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi7) + 4) = 0;
        fun_400b10(v5, "Flight %d took %2d passengers\n", rdx11, rcx10);
        ++v8;
    }
    closeLog(v5, rsi7);
    return;
}

int32_t shmemCreate(int32_t edi, int32_t esi) {
    int64_t rcx3;
    int64_t rdi4;
    int32_t eax5;

    *reinterpret_cast<int32_t*>(&rcx3) = esi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx3) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rdi4) = edi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi4) + 4) = 0;
    eax5 = fun_400bb0(rdi4, rcx3, 0x780);
    return eax5;
}

int64_t semSignal(int32_t edi) {
    uint64_t rax2;
    struct s0* rsi3;
    struct s1* rdi4;
    int64_t rax5;
    uint64_t rdx6;

    rax2 = g28;
    rsi3 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8 - 16);
    *reinterpret_cast<int32_t*>(&rdi4) = edi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi4) + 4) = 0;
    rax5 = fun_400bc0(rdi4, rsi3, 1);
    rdx6 = rax2 ^ g28;
    if (rdx6) {
        rax5 = fun_400ad0(rdi4, rsi3, rdx6);
    }
    return rax5;
}

void fun_400b46() {
    goto 0x400a60;
}

void fun_400af6() {
    goto 0x400a60;
}

void fun_400b16() {
    goto 0x400a60;
}

void fun_400a96() {
    goto 0x400a60;
}

void fun_400b26() {
    goto 0x400a60;
}

void shmemDestroy(int32_t edi) {
    int64_t rdi2;

    *reinterpret_cast<int32_t*>(&rdi2) = edi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi2) + 4) = 0;
    fun_400b50(rdi2, 0, 0);
    return;
}

void fun_400ab6() {
    goto 0x400a60;
}

void fun_400a86() {
    goto 0x400a60;
}

void fun_400aa6() {
    goto 0x400a60;
}

struct s8 {
    signed char[132] pad132;
    int32_t f132;
};

void saveFlightDeparted(unsigned char* rdi, struct s8* rsi) {
    struct s0* rax3;
    int64_t rax4;
    int64_t rdx5;
    struct s0* rcx6;
    int64_t rdx7;

    rax3 = openLog(rdi, "a");
    *reinterpret_cast<int32_t*>(&rax4) = rsi->f132;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax4) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rdx5) = static_cast<int32_t>(rax4 - 1);
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx5) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rcx6) = *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(rsi) + (rdx5 + 20) * 4 + 12);
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx6) + 4) = 0;
    *reinterpret_cast<int32_t*>(&rdx7) = rsi->f132;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx7) + 4) = 0;
    fun_400b10(rax3, "Flight %d : Departed with %d passengers\n", rdx7, rcx6);
    printHeader(rax3, "Flight %d : Departed with %d passengers\n", rdx7, rcx6);
    closeLog(rax3, "Flight %d : Departed with %d passengers\n", rax3, "Flight %d : Departed with %d passengers\n");
    return;
}

void fun_400bc6() {
    goto 0x400a60;
}

void fun_400b86() {
    goto 0x400a60;
}

void fun_400b66() {
    goto 0x400a60;
}

void fun_400ac6() {
    goto 0x400a60;
}

void fun_400bb6() {
    goto 0x400a60;
}

void fun_400b96() {
    goto 0x400a60;
}

void fun_400b56() {
    goto 0x400a60;
}
