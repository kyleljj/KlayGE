// D3D9Query.hpp
// KlayGE D3D9��ѯ�� ʵ���ļ�
// Ver 3.8.0
// ��Ȩ����(C) ������, 2005-2008
// Homepage: http://klayge.sourceforge.net
//
// 3.8.0
// ����ConditionalRender (2008.10.11)
//
// 3.0.0
// ���ν��� (2005.9.27)
//
// �޸ļ�¼
/////////////////////////////////////////////////////////////////////////////////

#include <KlayGE/KlayGE.hpp>
#include <KlayGE/ThrowErr.hpp>
#include <KlayGE/Util.hpp>
#include <KlayGE/Math.hpp>
#include <KlayGE/COMPtr.hpp>
#include <KlayGE/Context.hpp>
#include <KlayGE/RenderFactory.hpp>

#include <d3d9.h>

#include <KlayGE/D3D9/D3D9RenderEngine.hpp>
#include <KlayGE/D3D9/D3D9Query.hpp>

namespace KlayGE
{
	D3D9OcclusionQuery::D3D9OcclusionQuery()
	{
		D3D9RenderEngine const & render_eng = *checked_cast<D3D9RenderEngine const *>(&Context::Instance().RenderFactoryInstance().RenderEngineInstance());
		ID3D9DevicePtr const & d3d_device = render_eng.D3DDevice();

		IDirect3DQuery9* query;
		d3d_device->CreateQuery(D3DQUERYTYPE_OCCLUSION, &query);
		query_ = MakeCOMPtr(query);
	}

	void D3D9OcclusionQuery::Begin()
	{
		TIF(query_->Issue(D3DISSUE_BEGIN));
	}

	void D3D9OcclusionQuery::End()
	{
		TIF(query_->Issue(D3DISSUE_END));
	}

	uint64_t D3D9OcclusionQuery::SamplesPassed()
	{
		uint32_t ret;
		while (S_FALSE == query_->GetData(&ret, sizeof(ret), D3DGETDATA_FLUSH));
		return ret;
	}

	void D3D9OcclusionQuery::DoOnLostDevice()
	{
		query_.reset();
	}
	
	void D3D9OcclusionQuery::DoOnResetDevice()
	{
		D3D9RenderEngine const & render_eng = *checked_cast<D3D9RenderEngine const *>(&Context::Instance().RenderFactoryInstance().RenderEngineInstance());
		ID3D9DevicePtr const & d3d_device = render_eng.D3DDevice();

		IDirect3DQuery9* query;
		d3d_device->CreateQuery(D3DQUERYTYPE_OCCLUSION, &query);
		query_ = MakeCOMPtr(query);
	}


	D3D9ConditionalRender::D3D9ConditionalRender()
	{
		D3D9RenderEngine const & render_eng = *checked_cast<D3D9RenderEngine const *>(&Context::Instance().RenderFactoryInstance().RenderEngineInstance());
		ID3D9DevicePtr const & d3d_device = render_eng.D3DDevice();

		IDirect3DQuery9* query;
		d3d_device->CreateQuery(D3DQUERYTYPE_OCCLUSION, &query);
		query_ = MakeCOMPtr(query);
	}

	void D3D9ConditionalRender::Begin()
	{
		TIF(query_->Issue(D3DISSUE_BEGIN));
	}

	void D3D9ConditionalRender::End()
	{
		TIF(query_->Issue(D3DISSUE_END));
	}

	void D3D9ConditionalRender::BeginConditionalRender()
	{
		uint32_t ret;
		while (S_FALSE == query_->GetData(&ret, sizeof(ret), D3DGETDATA_FLUSH));

		D3D9RenderEngine& re = *checked_cast<D3D9RenderEngine*>(&Context::Instance().RenderFactoryInstance().RenderEngineInstance());
		re.ConditionalRender(ret != 0);
	}

	void D3D9ConditionalRender::EndConditionalRender()
	{
		D3D9RenderEngine& re = *checked_cast<D3D9RenderEngine*>(&Context::Instance().RenderFactoryInstance().RenderEngineInstance());
		re.ConditionalRender(true);
	}

	void D3D9ConditionalRender::DoOnLostDevice()
	{
		query_.reset();
	}
	
	void D3D9ConditionalRender::DoOnResetDevice()
	{
		D3D9RenderEngine const & render_eng = *checked_cast<D3D9RenderEngine const *>(&Context::Instance().RenderFactoryInstance().RenderEngineInstance());
		ID3D9DevicePtr const & d3d_device = render_eng.D3DDevice();

		IDirect3DQuery9* query;
		d3d_device->CreateQuery(D3DQUERYTYPE_OCCLUSION, &query);
		query_ = MakeCOMPtr(query);
	}
}