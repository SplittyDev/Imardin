using System;
using System.Collections.Generic;
using System.IO;

namespace Imasm
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("--- Imardin Assembler");
            if (args.Length == 1)
            {
                try
                {
                    string output = args[0].Replace(args[0].Substring(args[0].LastIndexOf('.')), ".bin");
                    Assemble(args[0], false, output);
                }
                catch (Exception ex)
                {
                    Console.WriteLine("ERROR: " + ex.Message);
                }
            }
            else if (args.Length > 1)
            {
                bool verbose = false;
                string output = args[0].Replace (args[0].Substring (args[0].LastIndexOf('.')), ".bin");
                for (int i = 1; i < args.Length; i++)
                {
                    if (args[i] == "--verbose") verbose = true;
                    else if (args[i] == "--out")
                    {
                        i++;
                        if (args.Length < i) break;
                        output = args[i].Replace(args[i].Substring(args[i].LastIndexOf('.')), ".bin");
                    }
                }
                Assemble(args[0], verbose, output);
            }
            else
            {
                Console.WriteLine("Invalid arguments!");
                Console.WriteLine("\nUsage: imasm <file> [arguments]");
                Console.WriteLine("\n--verbose          Report progress");
                Console.WriteLine("--out [filename.bin] Use this as output filename");
                Console.WriteLine("\nPress any key to continue...");
                Console.Read();
            }
        }

        static void Assemble(string file, bool verbose, string output)
        {
            if (verbose) Console.WriteLine("[INFO] Reading input file...");
            FileStream fs = new FileStream(file, FileMode.Open, FileAccess.Read, FileShare.Read);
            StreamReader stream = new StreamReader(fs);
            byte[] opcodes = Parse(stream);
            stream.Close();
            stream.Dispose();
            fs.Close();
            fs.Dispose();
            if (verbose) Console.WriteLine("[INFO] Generating output file...");
            fs = new FileStream(output, FileMode.Create, FileAccess.ReadWrite, FileShare.Read);
            BinaryWriter writer = new BinaryWriter(fs);
            foreach (byte opcode in opcodes)
            {
                writer.Write(opcode);
            }
            writer.Close();
            writer.Dispose();
            Console.WriteLine("Done!");
            Console.WriteLine("Press any key to continue...");
            Console.Read();
        }

        static byte[] Parse(StreamReader stream)
        {
            List<byte> opcodes = new List<byte>();
            Dictionary<string, byte> lookup = new Dictionary<string, byte>();
            lookup.Add("push", 0x01);
            lookup.Add("pop", 0x02);
            lookup.Add("sss", 0x03);
            lookup.Add("lss", 0x04);
            lookup.Add("ssp", 0x05);
            lookup.Add("lsp", 0x06);
            lookup.Add("store", 0x07);
            lookup.Add("load", 0x08);
            lookup.Add("beq", 0x09);
            lookup.Add("bne", 0x0A);
            lookup.Add("bgt", 0x0B);
            lookup.Add("blt", 0x0C);
            lookup.Add("bz", 0x0D);
            lookup.Add("bnz", 0x0E);
            lookup.Add("bra", 0x0F);
            lookup.Add("bsr", 0x10);
            lookup.Add("add", 0x11);
            lookup.Add("fadd", 0x12);
            lookup.Add("sub", 0x13);
            lookup.Add("fsub", 0x14);
            lookup.Add("mul", 0x15);
            lookup.Add("fmul", 0x16);
            lookup.Add("div", 0x17);
            lookup.Add("fdiv", 0x18);
            lookup.Add("sysf", 0x19);
            lookup.Add("and", 0x1A);
            lookup.Add("or", 0x1B);
            lookup.Add("xor", 0x1C);
            lookup.Add("shl", 0x1D);
            lookup.Add("shr", 0x1E);
            lookup.Add("rol", 0x1F);
            lookup.Add("ror", 0x20);
            lookup.Add("ret", 0x21);

            // To be filled =D

            return opcodes.ToArray();
        }
    }
}
