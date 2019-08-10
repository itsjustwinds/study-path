  const
        fi='b3.inp';
        fo='b3.out';
  var
        n,tam,i,j:longint;
        a:array [1..100] of longint;
        f:text;
  procedure nhap;
  begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                readln(f,a[i]);
        close(f);
  end;
  procedure sapxep;
  begin
        for i:=1 to n do
                for j:=n downto i do
                        if a[i]>a[j] then
                        begin
                                tam:=a[i];
                                a[i]:=a[j];
                                a[j]:=tam;
                        end;
  end;
  procedure xuat;
  begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
                write(f,a[i],' ');
        close(f);
  end;
  begin
        nhap;
        sapxep;
        xuat;
  end.

