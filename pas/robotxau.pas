const
        fi='robotxau.inp';
        fo='robotxau.out';
var
        a,l:array [0..51,0..51] of string;
        n,i,j,u:longint;
        kq:string;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                for j:=1 to n do
                begin
                        read(f,u);
                        str(u,a[i,j]);
                end;
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        l[1,1]:=a[1,1];
        for i:=2 to n do
        begin
                l[i,1]:=l[i-1,1]+a[i,1];
                l[1,i]:=l[1,i-1]+a[1,i];
        end;
        for i:=2 to n do
                for j:=2 to n do
                begin
                        if l[i-1,j]+a[i,j]>=l[i,j-1]+a[i,j] then
                                l[i,j]:=l[i,j-1]+a[i,j]
                        else l[i,j]:=l[i-1,j]+a[i,j];
                end;
         write(f,l[n,n]);
      {  for i:=1 to n do
        begin
                for j:=1 to n do
                        write(f,a[i,j],' ');
                writeln(f);
        end;                }
        close(f);
end;
begin
        nhap;
        xuat;
end.