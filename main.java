import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        ProcessBuilder pb = new ProcessBuilder("sleep", "10");
        Process p = pb.start();
        System.out.println("Processo iniciado com PID " + p.pid());
        Thread.sleep(5000);
        System.out.println("Enviando sinal SIGSTOP para o processo...");
        p.destroy();
        Thread.sleep(5000);
        pb.start();
        System.out.println("Processo reiniciado com PID " + p.pid());
        Thread.sleep(5000);
        System.out.println("Enviando sinal SIGTERM para o processo...");
        p.destroy();
    }
}
