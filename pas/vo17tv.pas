uses math;
var     a:array[1..50] of ansistring;
        n,i,j,k,h,dem,l:longint;
        stmp:ansistring;
        kt:boolean;
        kq:int64;
procedure nhap;
begin
        readln(n,k);
        for i:=1 to n do
                readln(a[i]);
end;
procedure xuly;
begin
        kq:=0;
        for h:=1 to n-k+1 do
        begin
                for i:=1 to length(a[h]) do
                if length(a[h])-i+1>kq then
                begin
                        kt:=false;
                        for j:=length(a[h]) downto i do
                        if j-i+1>kq then
                        begin
                                dem:=0;
                                stmp:=copy(a[h],i,j-i+1);
                                for l:=1 to n do
                                if pos(stmp,a[l])<>0 then
                                begin
                                        inc(dem);
                                        if dem=k then
                                        begin
                                                kq:=max(kq,j-i+1);
                                                kt:=true;
                                                break;
                                        end;

                                end;
                                if kt then break;
                        end
                        else break;
                end
                else break;
        end;
        writeln(kq);
end;
begin
        {assign(input,'vo17tv.inp');
        assign(output,'vo17tv.out');
        reset(input);
        rewrite(output);}
        nhap;
        xuly;
        {close(input);
        close(output);}
end.