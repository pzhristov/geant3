#ifndef ROOT_TGeant3TGeo
#define ROOT_TGeant3TGeo 
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

/* $Id: TGeant3TGeo.h,v 1.18 2004/11/23 14:52:52 brun Exp $ */

//////////////////////////////////////////////// 
//  C++ interface to Geant3 basic routines    // 
//////////////////////////////////////////////// 


#include "TGeant3.h" 

class TGeoMaterial;

class TGeant3TGeo : public TGeant3 { 

public: 
  TGeant3TGeo(); 
  TGeant3TGeo(const char *title, Int_t nwgeant=0); 
  virtual ~TGeant3TGeo();

 
///////////////////////////////////////////////////////////////////////
//                                                                   //
//                                                                   //
//     Here are the service routines from the geometry               //
//     which could be implemented also in other geometries           //
//                                                                   //
//                                                                   //
///////////////////////////////////////////////////////////////////////

  void  GeomIter();
  Int_t NextVolUp(Text_t *name, Int_t &copy);
  Int_t CurrentVolID(Int_t &copy) const;
  Int_t CurrentVolOffID(Int_t off, Int_t &copy) const;
  const char* CurrentVolName() const;
  const char *CurrentVolOffName(Int_t off) const;
  Int_t VolId(const Text_t *name) const;
  const char* VolName(Int_t id) const;
  Int_t NofVolumes() const;
  Int_t NofVolDaughters(const char* volName) const;
  const char*  VolDaughterName(const char* volName, Int_t i) const;
  Int_t        VolDaughterCopyNo(const char* volName, Int_t i) const;
  Int_t VolId2Mate(Int_t id) const;
  const char *GetPath();
  const char *GetNodeName();

  virtual void   Material(Int_t& kmat, const char* name, Double_t a, Double_t z,
			   Double_t dens, Double_t radl, Double_t absl, 
			   Float_t* buf=0, Int_t nwbuf=0);
  virtual void   Material(Int_t& kmat, const char* name, Double_t a, Double_t z,
			   Double_t dens, Double_t radl, Double_t absl, 
			   Double_t* buf, Int_t nwbuf);

  virtual void   Mixture(Int_t& kmat, const char* name, Float_t* a,Float_t* z,
			  Double_t dens, Int_t nlmat, Float_t* wmat);
  virtual void   Mixture(Int_t& kmat, const char* name, Double_t* a,Double_t* z,
			  Double_t dens, Int_t nlmat, Double_t* wmat);

  virtual void   Medium(Int_t& kmed, const char* name, Int_t nmat, Int_t isvol,
			Int_t ifield, Double_t fieldm, Double_t tmaxfd,
			Double_t stemax, Double_t deemax, Double_t epsil,
			Double_t stmin, Float_t* ubuf=0, Int_t nbuf=0);
  virtual void   Medium(Int_t& kmed, const char* name, Int_t nmat, Int_t isvol,
			Int_t ifield, Double_t fieldm, Double_t tmaxfd,
			Double_t stemax, Double_t deemax, Double_t epsil,
			Double_t stmin, Double_t* ubuf, Int_t nbuf);

  virtual void   Matrix(Int_t& krot, Double_t thex, Double_t phix, Double_t they,
			Double_t phiy, Double_t thez, Double_t phiz);			

  virtual void   SetRootGeometry();			

/////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                         //
//                                                                                         //
//     Here are the interface functions with GEANT3.21                                     //
//                                                                                         //
//                                                                                         //
/////////////////////////////////////////////////////////////////////////////////////////////

      // functions from GBASE 
   virtual  void  Ggclos(); 
   virtual  void  Gprint(const char *name); 
 
      // functions from GCONS 
   virtual  void  Gsmate(Int_t imat, const char *name, Float_t a, Float_t z,  
                         Float_t dens, Float_t radl, Float_t absl); 
   virtual  void  Gsmixt(Int_t imat, const char *name, Float_t *a, Float_t *z,  
                         Float_t dens, Int_t nlmat, Float_t *wmat); 
   virtual  void  Gstmed(Int_t numed, const char *name, Int_t nmat, Int_t isvol,  
                         Int_t ifield, Float_t fieldm, Float_t tmaxfd, 
                         Float_t stemax, Float_t deemax, Float_t epsil, 
                         Float_t stmin); 
 
      // functions from GTRAK 
   virtual  void  Gtreve(); 
   virtual  void  GtreveRoot(); 

      // functions from GGEOM 
   virtual  void  Gdtom(Float_t *xd, Float_t *xm, Int_t iflag); 
   virtual  void  Gdtom(Double_t *xd, Double_t *xm, Int_t iflag); 
   virtual  void  Gmedia(Float_t *x, Int_t &numed); 
   virtual  void  Gmtod(Float_t *xm, Float_t *xd, Int_t iflag); 
   virtual  void  Gmtod(Double_t *xm, Double_t *xd, Int_t iflag); 
   virtual  void  Gsdvn(const char *name, const char *mother, Int_t ndiv, Int_t iaxis); 
   virtual  void  Gsdvn2(const char *name, const char *mother, Int_t ndiv, Int_t iaxis, Double_t c0i, Int_t numed); 
   virtual  void  Gsdvs(const char *name, const char *mother, Float_t step, Int_t iaxis, Int_t numed); 
   virtual  void  Gsdvs2(const char *name, const char *mother, Float_t step, Int_t iaxis, Float_t c0, Int_t numed); 
   virtual  void  Gsdvt(const char *name, const char *mother, Double_t step, Int_t iaxis, Int_t numed, Int_t ndvmx); 
   virtual  void  Gsdvt2(const char *name, const char *mother, Double_t step, Int_t iaxis,
			 Double_t c0, Int_t numed, Int_t ndvmx); 
   virtual  void  Gsord(const char *name, Int_t iax); 
   virtual  void  Gspos(const char *name, Int_t nr, const char *mother,  
                         Double_t x, Double_t y, Double_t z, Int_t irot, const char *konly="ONLY"); 
   virtual  void  Gsposp(const char *name, Int_t nr, const char *mother,  
                         Double_t x, Double_t y, Double_t z, Int_t irot, const char *konly, Float_t *upar, Int_t np); 
   virtual  void  Gsposp(const char *name, Int_t nr, const char *mother,  
                         Double_t x, Double_t y, Double_t z, Int_t irot, const char *konly, Double_t *upar, Int_t np); 
   virtual  void  Gsrotm(Int_t nmat, Float_t theta1, Float_t phi1, Float_t theta2, Float_t phi2, 
                         Float_t theta3, Float_t phi3); 
   virtual  void  Gprotm(Int_t nmat=0); 
   virtual  Int_t Gsvolu(const char *name, const char *shape, Int_t nmed,  
                         Float_t *upar, Int_t np); 
   virtual  Int_t Gsvolu(const char *name, const char *shape, Int_t nmed,  
                         Double_t *upar, Int_t np); 
   virtual  void  Gsatt(const char *name, const char *att, Int_t val);
   virtual  Int_t  Glvolu(Int_t nlev, Int_t *lnam,Int_t *lnum);
    
      // functions from GDRAW 
   virtual  void  Gdshow(Int_t view);
   virtual  void  Gdopt(const char *name,const char *value);
   virtual  void  Gdraw(const char *name,Double_t theta=30, Double_t phi=30, Double_t psi=0,Double_t u0=10,Double_t v0=10,Double_t ul=0.01,Double_t vl=0.01);
   virtual  void  Gdrawc(const char *name,Int_t axis=1, Float_t cut=0,Float_t u0=10,Float_t v0=10,Float_t ul=0.01,Float_t vl=0.01);
   virtual  void  Gdrawx(const char *name,Float_t cutthe, Float_t cutphi, Float_t cutval,
                         Float_t theta=30, Float_t phi=30,Float_t u0=10,Float_t v0=10,Float_t ul=0.01,Float_t vl=0.01);
   virtual  void  Gdspec(const char *name);
   virtual  void  DrawOneSpec(const char *name);
   virtual  void  Gdtree(const char *name,Int_t levmax=15,Int_t ispec=0);
   virtual  void  GdtreeParent(const char *name,Int_t levmax=15,Int_t ispec=0);
        
  // Control Methods

  virtual void FinishGeometry();

  // 
  virtual void SetColors();

protected:
  TGeoMCGeometry*  fMCGeo; // Implementation of TVirtualMCGeometry for TGeo
  Bool_t           fImportRootGeometry; // Option to import geometry from TGeo
                                        // (materials and medias are filled in FinishGeometry()  

private:

  TGeant3TGeo(const TGeant3TGeo &) : TGeant3() {}
  TGeant3TGeo & operator=(const TGeant3TGeo&) {return *this;}

  Int_t  ImportMaterial(const TGeoMaterial* material);

  ClassDef(TGeant3TGeo,1)  //C++ interface to Geant basic routines with the TGeo interface
}; 

#endif //ROOT_TGeant3TGeo