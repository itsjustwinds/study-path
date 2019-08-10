const
        fi='pp.inp';
        fo='pp.out';
var
        nt:array [1..500000] of boolean;
        a:array [1..1000000] of boolean;
        l,r,dem,i,k,tu,j,n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,l,r);
        close(f);
end;
procedure sang;
var     i,j:longint;
begin
        fillchar(nt,sizeof(nt),true);
        a[1]:=false;
        for i:=2 to trunc(sqrt(r)) do
        if a[i] then
                for j:=2 to (r div i) do a[i*j]:=false;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        fillchar(a,sizeof(a),true);
        dem:=0;
        for i:=l to r do
        if (a[i]=true) then
        begin
        tu:=1;
        n:=i;
        for j:=2 to i div 2 do
                if nt[j] then
                while n mod j=0 do
                begin
                inc(tu);
                n:=n div j;
                if tu>=4 then
                begin
                        inc(dem);
                        k:=2;
                        while ((k*i)<r) and (a[k*i]=true) do
                        begin
                                a[k*i]:=false;
                                inc(k);
                                inc(dem);
                        end;
                break;
                end;
                end;
        end;
        write
        (f,dem);
        close(f);
end;
begin

        nhap;
        sang;
        xuat;
end.
