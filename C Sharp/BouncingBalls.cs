using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace BouncingBalls // koncowe!!!
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();

            int ilosc_kulek = 3;
            Restart(ilosc_kulek);

            //!!!! usunięcie błyskania!!!!!!
            DoubleBuffered = true;
            // ustawienie kwadratu dostępnego dla piłek - skrót
            Box = ClientRectangle;

            timer.Interval = 30;   // ustawiam timer
            timer.Start();        

            // ?? czegoś brakuje
        }

        kulka[] kulki;
        Rectangle Box;






        // tworzę funkcję wystartowania kulek
        public void Restart(int ilosc_kulek)
        {
            // Point(x,y)

            Point start = new Point(1,1);

            // tablice - by nie zawalać - SPRAWDZIC!! - odwołanie do klasy Kulka
            kulki = new kulka[ilosc_kulek];
            for (int i = 0; i < ilosc_kulek; i++)
                kulki[i] = new kulka(start, new Point(random.Next(0, 5), random.Next(0, 5)), random.Next(30, 50));
            // ostatnie - wielkosc

            // refresh
            Invalidate();
        }




        private void MainForm_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            
            foreach (kulka kulka in kulki)
                kulka.Draw(g);
        }


        public static Random random = new Random();

        private void MainForm_Load(object sender, EventArgs e)
        {

        }

        private void timer_Tick(object sender, EventArgs e)
        {
            // id
            for (int kulkaIdx = 0; kulkaIdx < kulki.Length; kulkaIdx++)
            {
                kulki[kulkaIdx].Update(this, Box);

                for (int ikulkaIdx = kulkaIdx + 1; ikulkaIdx < kulki.Length; ikulkaIdx++)
                    kulki[kulkaIdx].kolizja_z_inna(kulki[ikulkaIdx]);
            }
        }
    }


    class kulka
    {

        public kulka(Point start, Point sspeedy, int size)
        {

            Kwa = new Rectangle(start.X, start.Y, size, size);  // sprawdzajka
            // Eclipse nie działa
            speedy = sspeedy;
            kat_lotu = random.Next(-100, 100);
        }


        SolidBrush redBrush = new SolidBrush(Color.Red);
        public void Draw(Graphics g)
        {
            g.FillEllipse(redBrush, Kwa);        }

        // TranslateTransform i Scale? 
        public void kolizja_z_inna(kulka ikulka)
        {

            //haha, intersectswith - przecinanie się :D
            // liczenie distant(polozenie1 - polozenie 2) < (promien1+promien2)^2 itd... 
            // (Length(dist))

            //czy zderza się z inna kulka - ikulka
            if (Kwa.IntersectsWith(ikulka.Kwa))
            {
                Point dist = ikulka.Center - (Size)Center;
                float distance = Length(dist);  // sqrt(pol1 do pol2)

                if (distance <= Kwa.Width/2 + ikulka.Kwa.Width/2) // promienie
                {


                        PointF os_dystans = new PointF(dist.X / distance, dist.Y / distance);
                        
                        // wywala blad zmiany jednostki
                        float os_predkosc = mnoze(os_dystans, speedy);
                        float os_ikulkspeed = mnoze(os_dystans, ikulka.speedy);

                    // aaaaaaa
                        if (os_predkosc > os_ikulkspeed)
                        {
                            PointF bu_dystans = new PointF(os_dystans.Y, -os_dystans.X);
                        // do zmiany powyzsze

                            PointF os_wekt = Scale(os_dystans, os_predkosc);
                            PointF wekt = Scale(bu_dystans, mnoze(bu_dystans, speedy));

                        // coś tu wywala?

                            PointF ikulkaos_wekt = Scale(os_dystans, os_ikulkspeed);
                            PointF ikulkawekt = Scale(bu_dystans, mnoze(bu_dystans, ikulka.speedy));
                            
                            speedy = Point.Round(Add(ikulkaos_wekt, wekt));
                            ikulka.speedy = Point.Round(Add(os_wekt, ikulkawekt));
                            
                        }

                }
            }
        }


        private static float Length(PointF p)
        {
            return ((float)Math.Sqrt(p.X * p.X + p.Y * p.Y));  // odleglosc
        }

        private PointF Scale(PointF p, float scale)
        {
            return new PointF(p.X * scale, p.Y * scale);
        }

        private PointF Add(PointF p1, PointF p2)
        {
            return new PointF(p1.X + p2.X, p1.Y + p2.Y);
        }

        private float mnoze(PointF p1, PointF p2)
        {
            return p1.X * p2.X + p1.Y * p2.Y;
        }


        public void Update(Control drawingControl, Rectangle region)
        {
            drawingControl.Invalidate(Kwa);   // by nie zostawały "slady"
            Kwa.X = Kwa.X + speedy.X;
            Kwa.Y = Kwa.Y + speedy.Y;
          //  Kwa.Offset(speedy); // przesunięcie o speedy (zamiast powyższego? - zacina się)
            
            if (Kwa.Left <= region.Left)    // lewaaa sciana - zmiana - moze byc tez jak w tym drugim
            {
                Kwa.X = region.Left;
                speedy.X = -speedy.X;
            }
            else if (Kwa.Right >= region.Right) /// prawaaaaa
            {
                Kwa.X = region.Right - Kwa.Width;   // MINUS - plus wywala
                speedy.X = -speedy.X;
            }

            if (Kwa.Top <= region.Top)   // gooora
            {
                Kwa.Y = region.Top;
                speedy.Y = -speedy.Y;
            }
            else if (Kwa.Bottom >= region.Bottom)   /// dol 
            {
                Kwa.Y = region.Bottom - Kwa.Height;
                speedy.Y = -speedy.Y;
            }

            drawingControl.Invalidate(Kwa);   // znowu slady
        }

        public Point Center
        {
            get
            {
                return new Point(Kwa.X, Kwa.Y);
            }
        }


        float kat_lotu;        
        Rectangle Kwa;        
        Point speedy;    

        public static Random random = new Random();
    }
}
