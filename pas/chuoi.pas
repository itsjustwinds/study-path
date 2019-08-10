const
        fi='chuoi.inp';
        fo='chuoi.out';
var
        s,s1,sdx:ansistring;
        i,j,n,dem:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        readln(f,s);
        close(f);
end;
function dx(a:ansistring):boolean;
var i:longint;
begin   dx:=false;
        for i:=1 to length(a) div 2 do
                if a[i]<>a[n-i+1] then exit;
        dx:=true;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        sdx:='1';
        for i:=1 to length(s) do
                for j:=length(s) to i do
                begin
                        s1:=copy(s,i,j-i+1);
                        if dx(s1) then
                        begin
                                sdx:=s1;
                                break;
                        end;
                end;
        dem:=length(sdx);
        writeln(f,dem);
        close(f);
end;
begin
        nhap;
        xuly;
end.