import os
import signal
import time

def signal_handler(signum, frame):
    print("Sinal %d recebido" % signum)
    if signum == signal.SIGTERM:
        print("Finalizando processo filho...")
        exit(0)

pid = os.fork()
if pid == 0:
    # processo filho
    print("Filho iniciado com PID %d" % os.getpid())
    signal.signal(signal.SIGTERM, signal_handler)
    while True:
        print("Processo filho rodando...")
        time.sleep(1)
else:
    # processo pai
    print("Pai iniciado com PID %d" % os.getpid())
    time.sleep(5)
    print("Enviando sinal SIGSTOP para o processo filho...")
    os.kill(pid, signal.SIGSTOP)
    time.sleep(5)
    print("Enviando sinal SIGCONT para o processo filho...")
    os.kill(pid, signal.SIGCONT)
    time.sleep(5)
    print("Enviando sinal SIGTERM para o processo filho...")
    os.kill(pid, signal.SIGTERM)
    os.waitpid(pid, 0)
    print("Processo filho finalizado")
