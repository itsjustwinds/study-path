const
        fi='giaithua.inp';
        fo='giaithua.out';
var
        nt,mu:array [1..1000000] of longint;
        n,i,j,dem,m:longint;
        f:text;

procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function ngto(n:longint):boolean;
var
        i:longint;
begin   ngto:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        ngto:=true;
end;
procedure xuly;
begin   dem:=0;
        for i:=2 to n do
                if ngto(i) then
                begin
                        inc(dem);
                        nt[dem]:=i;
                end;
        dem:=1;
        for i:=2 to n do
        begin
                j:=1;
                m:=i;
                while m<>1 do
                begin
                 while m mod nt[j]=0 do
                  begin
                        m:=m div nt[j];
                        inc(mu[j]);
                  end;
                 inc(j);
                end;
                if j>dem then dem:=j-1;
        end;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to dem do
        write(f,mu[i],' ');
        close(f);
end;
begin
        nhap;
        xuly;
        xuat;
end.


