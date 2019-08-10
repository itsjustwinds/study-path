uses math;
var
        a:array[0..201,0..201] of longint;
        tong:array[1..200,1..200] of record
                ngang:int64;
                doc:int64;
                vtd,vts:longint;
        end;
        res:int64;
        n,m,i,j,h,k:longint;

procedure nhap;
begin
        readln(n,m);
        for i:=1 to n do
                for j:=1 to m do
                        read(a[i,j]);
end;

function giao(i,j,dem:longint):int64;
begin


procedure xuly;
var     tmp:int64;
        dem,vt1,vt2:longint;
        t:array[1..200,1..200] of int64;
begin
        for k:=1 to n do
        begin
                tmp:=0;
                vtt:=1;vts:=1;
                for i:=1 to m do
                for j:=i to m do
                begin
                        inc(tmp,a[k,j])
                        if tmp>tong[k,vtt].ngang then
                        begin
                                vtt:=i;
                                vts:=j;
                                tong[k,vtt].ngang:=tmp;
                        end;
                end;
                for j:=1 to m do
                        if (j in [vtt..vts]) then
                        begin
                                tong[k,j].ngang:=tong[k,vtt].ngang;
                                tong[k,j].ngang.vtt:=vtt;
                                tong[k,j].ngang.vts:=vts;
                        end
                        else
                        begin
                                tong[k,j].ngang:=tong[k,vtt].ngang;
                                if j<vtt then
                                begin
                                        for i:=j to vtt-1 do
                                                inc(tong[k,j].ngang,a[k,i]);
                                        tong[k,j].ngang.vtt:=j;
                                        tong[k,j].ngang.vts:=vts;
                                end;
                                if j>vts then
                                begin
                                        for i:=j downto vts+1 do
                                                inc(tong[k,j].ngang,a[k,i]);
                                        tong[k,j].ngang.vtt:=vtt;
                                        tong[k,j].ngang.vts:=j;
                                end;
                        end;
        end;
         for k:=1 to m do
        begin
                tmp:=0;
                vtt:=1;vts:=1;
                for i:=1 to n do
                for j:=i to n do
                begin
                        inc(tmp,a[j,k])
                        if tmp>tong[vtt,k].doc then
                        begin
                                vtt:=i;
                                vts:=j;
                                tong[vtt,k].doc:=tmp;
                        end;
                end;
                for i:=1 to n do
                        if (i in [vtt..vts]) then
                        begin
                                tong[i,k].doc:=tong[vtt,k].doc;
                                tong[i,k].doc.vtt:=vtt;
                                tong[i,k].doc.vts:=vts;
                        end
                        else
                        begin
                                if i<vtt then
                                begin
                                        tong[i,k].doc:=tong[vtt,k].doc;
                                        tong[i,k].doc.vtt:=i;
                                        tong[i,k].doc.vts:=vts;
                                        for j:=i to vtt-1 do
                                                inc(tong[i,k].doc,a[j,k]);
                                end;
                                if i>vts then
                                begin
                                        tong[i,k].doc:=tong[vtt,k].doc;
                                        tong[i,k].doc.vtt:=vtt;
                                        tong[i,k].doc.vts:=i;
                                        for j:=i downto vts+1 do
                                                inc(tong[i,k].doc,a[j,k]);
                                end;
                        end;
        end;
        for i:=2 to n-1 do
                for j:=2 to m-1 do
                begin
                        vt1:=0;
                        tmp:=0;
                        vt2:=0;
                        d:=0;
                        for k:=max(i,j) to min(n-1,m-1) do
                        begin
                                inc(d);
                                inc(tmp,giao(vt1,vt2,tong[i+d,j+d].ngang.vtt,tong[i+d,j+d].ngang.vts,vt3,vt4,tong[i+d,j+d].doc.vtt,tong[i+d,j+d].doc.vts);
                                dec(tmp,t[vt2,vt2]);
                                dec(tmp,t[vt1,vt1]);
