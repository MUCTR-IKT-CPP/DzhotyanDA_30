using System.Text;

namespace lab9_algo
{
    internal class SHA_256
    {
        private uint h0 = 0x6a09e667;
        private uint h1 = 0xbb67ae85;
        private uint h2 = 0x3c6ef372;
        private uint h3 = 0xa54ff53a;
        private uint h4 = 0x510e527f;
        private uint h5 = 0x9b05688c;
        private uint h6 = 0x1f83d9ab;
        private uint h7 = 0x5be0cd19;

        private readonly uint[] K =
            [
                0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
                0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
                0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
                0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
                0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
                0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
                0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
                0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
            ];

        internal string GetHash(string input)
        {
            string binaryString = ToBinary(input, Encoding.ASCII);

            int inputBitLength = binaryString.Length; // длина в битах до паддинга

            binaryString += "1";

            // Дополняем нулями до 448 бит (оставляем место для длины в 64 бита)
            while (binaryString.Length % 512 != 448)
            {
                binaryString += "0";
            }

            // Теперь добавляем длину исходного сообщения (до паддинга) как 64-битное число
            string length64bit = Convert.ToString(inputBitLength, 2).PadLeft(64, '0');
            binaryString += length64bit;

            // Разбиваем на блоки по 512 бит
            uint[] w = new uint[64];

            // Заполняем первые 16 слов w[0..15]
            for (int i = 0; i < 16; i++)
            {
                w[i] = Convert.ToUInt32(binaryString.Substring(i * 32, 32), 2);
            }

            // Генерация оставшихся слов w[16..63]
            for (int i = 16; i < 64; i++)
            {
                uint s0 = RotateRight(w[i - 15], 7) ^ RotateRight(w[i - 15], 18) ^ (w[i - 15] >> 3);
                uint s1 = RotateRight(w[i - 2], 17) ^ RotateRight(w[i - 2], 19) ^ (w[i - 2] >> 10);
                w[i] = w[i - 16] + s0 + w[i - 7] + s1;
            }

            uint a = h0;
            uint b = h1;
            uint c = h2;
            uint d = h3;
            uint e = h4;
            uint f = h5;
            uint g = h6;
            uint h = h7;

            // Основной цикл SHA-256
            for (int i = 0; i < K.Length; i++)
            {
                uint S1 = RotateRight(e, 6) ^ RotateRight(e, 11) ^ RotateRight(e, 25);
                uint ch = (e & f) ^ ((~e) & g);
                uint temp1 = h + S1 + ch + K[i] + w[i];
                uint S0 = RotateRight(a, 2) ^ RotateRight(a, 13) ^ RotateRight(a, 22);
                uint maj = (a & b) ^ (a & c) ^ (b & c);
                uint temp2 = S0 + maj;

                h = g;
                g = f;
                f = e;
                e = d + temp1;
                d = c;
                c = b;
                b = a;
                a = temp1 + temp2;
            }

            h0 += a;
            h1 += b;
            h2 += c;
            h3 += d;
            h4 += e;
            h5 += f;
            h6 += g;
            h7 += h;

            return $"{h0:x8}{h1:x8}{h2:x8}{h3:x8}{h4:x8}{h5:x8}{h6:x8}{h7:x8}";
        }

        private static string ToBinary(string text, Encoding encoding)
        {
            byte[] bytes = encoding.GetBytes(text);
            StringBuilder sb = new StringBuilder();

            foreach (byte b in bytes)
            {
                sb.Append(Convert.ToString(b, 2).PadLeft(8, '0'));
            }

            return sb.ToString();
        }

        private static string FormatBinaryString(string binary)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < binary.Length; i += 8)
            {
                if (i > 0 && (i % 64 == 0)) sb.AppendLine();
                else if (i > 0) sb.Append(" ");

                sb.Append(binary.Substring(i, Math.Min(8, binary.Length - i)));
            }
            return sb.ToString();
        }

        private static uint RotateRight(uint x, int n)
        {
            return (x >> n) | (x << (32 - n));
        }
    }
}
