(semgid, sh->mutex) = (uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0x9c)

(semgid, sh->readyForBoarding) = (uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0xac)

sh->fSt.st.hostessStat = *(undefined4 *)((int64_t)_sh + 4)

saveState(nFic, &sh->fSt); = saveState((int64_t)nFic, _sh);

(semgid, sh->passengersInQueue) = (uint64_t)_semgid, (uint64_t) * (uint32_t *)(_sh + 0x14)

(semgid, sh->passengersWaitInQueue) = (uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0xa4)

(semgid, sh->idShown) = (uint64_t)_semgid, (uint64_t) * (uint32_t *)((int64_t)_sh + 0xb4)

sh->fSt.nPassInQueue = *(int32_t *)(_sh + 0x11)
sh->fSt.nPassInFlight = *(int32_t *)((int64_t)_sh + 0x8c)
sh->fSt.totalPassBoarded = *(int32_t *)(_sh + 0x12)

N = 0x15

savePassengerChecked(nFic, &sh->fSt); = savePassengerChecked((int64_t)nFic, (int64_t)_sh);

(semgid, sh->readyToFlight) = (uint64_t)_semgid, (uint64_t) * (uint32_t *)(_sh + 0x16)

sh->fSt.finished = *(undefined *)((int64_t)_sh + 0x94)

sh->fSt.nFlight = *(int32_t *)((int64_t)_sh + 0x84)

sh->fSt.passengerChecked = *(int32_t *)(_sh + 0x13)

sh->fSt.st.passengerStat[passengerId] = *(undefined4 *)((int64_t)_sh + (passengerId & 0xffffffffU) * 4 + 8)


semgid, sh->passengersWaitInFlight = semgid, (uint64_t) * (uint32_t *)(_sh + 0x15)

semgid, sh->planeEmpty = semgid, (uint64_t) * (uint32_t *)(_sh + 0x17)




